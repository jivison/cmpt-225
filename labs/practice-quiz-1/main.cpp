
#include <iostream>
#include "Stack.h"

using namespace std;

void printStack()
{
}

int main()
{
    Stack SA, SB, SC, SD, SE;
    int resA, resB, resC, resD, resE;

    // Test case 1:
    cout << "Test Case 1 - No duplication of max elements:" << endl;

    int A[10] = {13, 8, 2, 3, 1, 5, 21, 1, 55, 34};
    int B[10] = {25, 64, 100, 81, 49, 1, 9, 16, 4, 36};

    for (unsigned int i = 0; i < 10; i++)
    {
        SA.push(A[i]);
        SB.push(B[i]);
    }

    resA = SA.removeMax();
    resB = SB.removeMax();

    if (resA == 55 && resB == 100)
    {
        cout << "Pass" << endl;
    }
    else
    {
        cout << "Fail:  resA=" << resA << " resB=" << resB << endl;
    }

    // Test case 2:
    cout << "Test Case 2 - Duplication of max elements:" << endl;

    int C[10] = {13, 8, 2, 3, 1, 5, 21, 55, 55, 34};
    int D[10] = {25, 64, 100, 81, 49, 1, 9, 16, 4, 100};

    for (unsigned int i = 0; i < 10; i++)
    {
        SC.push(C[i]);
        SD.push(D[i]);
    }

    cout << "SD before: ";
    while (!SD.isEmpty())
    {
        int element = SD.pop();
        SD.push(element);

        cout << element << ", ";
    }
    cout << endl;

    resC = SC.removeMax();
    resD = SD.removeMax();

    if (resC == 55 && resD == 100)
    {
        cout << "Pass" << endl;
    }
    else
    {
        cout << "Fail:  resC=" << resC << " resD=" << resD << endl;
    }

    // Test case 3:
    cout << "Test Case 2 - Only one element:" << endl;

    SE.push(15);

    resE = SE.removeMax();

    if (resE == 15)
    {
        cout << "Pass" << endl;
    }
    else
    {
        cout << "Fail:  resC=" << resC << " resD=" << resD << endl;
    }

    cout << "SD after: ";
    while (!SD.isEmpty())
    {
        int element = SD.pop();
        SD.push(element);

        cout << element << ", ";
    }
    cout << endl;

    return 0;
} // main
