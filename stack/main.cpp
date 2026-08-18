#include "array_stack.hpp"
#include "vector_stack.hpp"
#include <iostream>
using namespace std;

template <typename T> void displayTop(Stack<T> &stack) {
  cout << "top is " << stack.top();
}

template <typename T> void countOff(Stack<T> &stack) {
  int originalSize = stack.getSize();
  for (int i = 0; i < originalSize; i++)
    {
      cout << stack.top() << endl;
      stack.pop();
    }
  cout << "Who do we appreciate?\nPOINTERS!!!!\n";
}

int main() {
  int primes[] = {2, 3, 5, 7};
  Stack<int> *stackPtr;
  {
    ArrayStack<int> stack{primes, 4};
    stackPtr = &stack;

    while (!stackPtr->isEmpty()) {
      displayTop(stack);
      cout << endl << "Pop!\n";
      stackPtr->pop();
    }
    cout << endl << "Empty? " << (stackPtr->isEmpty() ? "Yup" : "Nope") << endl;

    stackPtr->push(10);
    stackPtr->push(8);
    stackPtr->push(6);
    stackPtr->push(4);

    // This one should kick off a new allocation
    stackPtr->push(2);

    countOff(*stackPtr);
  }

  {
    VectorStack<int> stack{primes, 4};
    // Because of abstraction, I can reassign the pointer to point to a
    // different type
    stackPtr = &stack;

    while (!stackPtr->isEmpty()) {
      displayTop(stack);
      cout << endl << "Pop!\n";
      stackPtr->pop();
    }

    cout << "Starting capacity: " << stackPtr->getCapacity() << endl;
    stackPtr->push(10);
    stackPtr->push(8);
    stackPtr->push(6);
    stackPtr->push(4);
    stackPtr->push(9);
    stackPtr->push(13);
    stackPtr->push(27);
    cout << "Ending capacity: " << stackPtr->getCapacity() << endl;

    countOff(*stackPtr);
  }

  return 0;
}
