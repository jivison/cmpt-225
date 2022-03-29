/* 
 * Stack.h
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author:
 * Date:
 */

class Stack {
    private:

        // Description: Implemented by a stack-allocated array arr[CAPACITY].
        //              Stack contains elementCount elements.
        //              Top of Stack is at index elementCount-1.
        static const unsigned int CAPACITY = 20;
        int arr[CAPACITY];
        unsigned elementCount;


    public:

        // Description: Constructor
        Stack();

        // Description: Returns true if Stack empty.
        bool isEmpty() const;

        // Description: Insert element x to the top of Stack.
        void push(int x);

        // Description: Remove and return element at the top of Stack.
        int pop();

        // Description: Removes and returns the max element.
        //              In case of duplicated max, take the one closest to the top.
        // Precondition: Stack nonempty
        // Postcondition: Order of remaining elements is preserved
        int removeMax();

};

