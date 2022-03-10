#include <iostream>

#include "Patient.h"
#include "List.h"

void startup();
bool readAndRunOption(List *list);
void displayMenu();

int main()
{
  startup();

  List *list = new List();

  while (true)
  {
    displayMenu();
    if (!readAndRunOption(list))
      return 0;
  }

  delete list;

  return 0;
}

void displayMenu()
{
  cout << endl
       << "Enter a number to select an option: " << endl
       << "(1) Add a new patient" << endl
       << "(2) Remove a patient" << endl
       << "(3) Search for a patient" << endl
       << "(4) Edit a patient" << endl
       << "(5) See all patients" << endl
       << "(6) Quit" << endl
       << endl;
}

string readParameter(string prompt)
{
  cout << prompt;

  string parameter;

  std::getline(cin >> ws, parameter);

  return parameter;
}

void addPatient(List *list)
{
  string name = readParameter("Please enter a name: ");
  string address = readParameter("Please enter an address: ");
  string phone = readParameter("Please enter an phone number: ");
  string email = readParameter("Please enter an email: ");
  string careCard = readParameter("Please enter a care card number: ");

  Patient patient = Patient(name, address, phone, email, careCard);

  if (!list->insert(patient))
  {
    cout << endl
         << "\e[31mA patient with that care card already exists in the system, or the system is at capacity!\e[0m" << endl;
  }
}

void removePatient(List *list)
{
  string careCard = readParameter("Please the care card of the patient you wish to remove: ");

  if (!list->remove(Patient(careCard)))
  {
    cout << endl
         << "\e[31mCouldn't find a patient with the care card number '" << careCard << "'!\e[0m" << endl;
  }
  else
  {
    cout << endl
         << "Successfully removed patient '" << careCard << "'!" << endl;
  }
}

void searchPatient(List *list)
{
  string careCard = readParameter("Please the care card of the patient you wish to find: ");

  cout << endl;

  Patient *patient = list->search(Patient(careCard));

  if (patient == NULL)
  {
    cout << "Couldn't find that patient..." << endl;
  }
  else
  {
    cout << "Patient: "
         << *patient << endl;
  }
}

void editPatient(List *list)
{
  string careCard = readParameter("Please the care card of the patient you wish to edit: ");

  cout << endl;

  Patient *patient = list->search(Patient(careCard));

  if (patient == NULL)
  {
    cout << "Couldn't find that patient..." << endl;
    return;
  }

  string name = readParameter("Please enter a new name (or type '-' to leave blank): ");
  string address = readParameter("Please enter a new address (or type '-' to leave blank): ");
  string phone = readParameter("Please enter a new phone number (or type '-' to leave blank): ");
  string email = readParameter("Please enter a new email (or type '-' to leave blank): ");

  cout << endl
       << "Before: " << *patient << endl;

  if (name != "-")
    patient->setName(name);
  if (address != "-")
    patient->setAddress(address);
  if (phone != "-")
    patient->setPhone(phone);
  if (email != "-")
    patient->setEmail(email);

  cout << "After: " << *patient << endl;
}

void seeAllPatients(List *list)
{
  cout << "All patients in the system:\n"
       << "==========================="
       << endl;

  list->printList();
}

bool readAndRunOption(List *list)
{
  cout << "Enter an option: ";
  string option;
  cin >> option;

  cout << endl;

  if (option == "1")
    addPatient(list);
  else if (option == "2")
    removePatient(list);
  else if (option == "3")
    searchPatient(list);
  else if (option == "4")
    editPatient(list);
  else if (option == "5")
    seeAllPatients(list);
  else if (option == "6")
    return false;
  else
  {
    cout << endl
         << "Please enter a valid option (1, 2, 3, 4, 5, or 6)" << endl;
    displayMenu();
    return readAndRunOption(list);
  }

  return true;
}

void startup()
{
  const char *menuCard =
      "██     ██  █████  ██      ██   ██       ██ ███    ██ ®\n"
      "██     ██ ██   ██ ██      ██  ██        ██ ████   ██\n"
      "██  █  ██ ███████ ██      █████   █████ ██ ██ ██  ██\n"
      "██ ███ ██ ██   ██ ██      ██  ██        ██ ██  ██ ██\n"
      " ███ ███  ██   ██ ███████ ██   ██       ██ ██   ████\n"
      "====================================================\n";

  cout << endl
       << menuCard << endl
       << endl;
}

// 0000000001