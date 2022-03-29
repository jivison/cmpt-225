#include <iostream>
#include <iomanip>

#include "PriorityQueue.h"
#include "Event.h"
#include "Queue.h"

using namespace std;

void displayEventProcessing(Event &event);
void displayFinalStatistics(int cumulativeWaitingTime, int customersServed);

int main()
{
  // Variables for parsing file input
  int delimiterPosition;
  string delimiter = " ";
  string time;

  // Queue that holds arrivals
  Queue<Event> arrivalQueue = Queue<Event>();
  // Priority queue that holds all events, in time order
  PriorityQueue<Event> pq = PriorityQueue<Event>();

  // Read each line of the file input
  for (string line; getline(cin, line);)
  {
    // Parse file line
    delimiterPosition = line.find(delimiter);
    time = line.substr(0, delimiterPosition);
    line.erase(0, delimiterPosition + delimiter.length());

    // Create an arrival event and add it to the priority queue
    Event arrival = Event('A', stoi(time), stoi(line));
    pq.enqueue(arrival);
  }

  // Holds the earliest available time the next event can be processed
  int latestTime = pq.peek().getTime();

  // Variables for calculating final statistics
  int cumulativeWaitingTime = 0;
  int customersServed = 0;

  cout << "Simulation Begins" << endl;

  // While either the priority queue or the arrival queue has items...
  while (!pq.isEmpty() || !arrivalQueue.isEmpty())
  {
    // If the arrival queue is empty,
    // process the next event in the priority queue
    if (arrivalQueue.isEmpty())
    {
      Event next = pq.peek();
      pq.dequeue();

      // If the event is an arrival, add it to the arrival queue
      if (next.getType() == 'A')
      {
        arrivalQueue.enqueue(next);
      }

      // Display trace of event
      displayEventProcessing(next);

      // If the latest arrival is after the last departure was processed
      // set the latest time to be the that of the latest arrival
      if (next.getTime() > latestTime)
      {
        latestTime = next.getTime();
      }
    }
    else
    {
      // Fetch the latest arrival from the queue
      Event processing = arrivalQueue.peek();
      arrivalQueue.dequeue();

      // Increment the statistics
      customersServed++;
      // The time waiting is the time the event was processed,
      // minus the time it was queued at
      cumulativeWaitingTime += latestTime - processing.getTime();

      // Set the latest time to be when this arrival is done processing
      latestTime = latestTime + processing.getLength();

      // Create and queue the departure event for this arrival
      Event departure = Event('D', latestTime);
      pq.enqueue(departure);
    }
  }

  cout << "Simulation Ends" << endl;

  displayFinalStatistics(cumulativeWaitingTime, customersServed);

  return 0;
}

void displayEventProcessing(Event &event)
{
  bool isArrival = event.getType() == event.ARRIVAL;

  cout << "Processing " << (isArrival ? "an arrival" : "a departure") << " event at time: " << setw(isArrival ? 6 : 5) << event.getTime() << endl;
}

void displayFinalStatistics(int cumulativeWaitingTime, int customersServed)
{
  cout << "\nFinal Statistics:\n\n\tTotal number of people processed: "
       << customersServed
       << "\n\tAverage amount of time spent waiting: "
       << static_cast<float>(cumulativeWaitingTime) / customersServed << "\n\n";
}