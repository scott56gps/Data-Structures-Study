#include "stack.h"
#include <iostream>
using namespace std;

void displayTop(Stack& stack)
{
  cout << "top is " << stack.top();
}

void countOff(Stack& stack)
{
  int originalSize = stack.getSize();
  for (int i = 0; i < originalSize; i++)
    {
      cout << stack.top() << endl;
      stack.pop();
    }
  cout << "Who do we appreciate?\nPOINTERS!!!!\n";
}

int main()
{
  int primes[] = { 2, 3, 5, 7 };
  Stack stack { primes, 4 };

  while(!stack.isEmpty())
    {
      displayTop(stack);
      cout << endl << "Pop!\n";
      stack.pop();
    }
  cout << endl << "Empty? " << (stack.isEmpty() ? "Yup" : "Nope") << endl;

  stack.push(10);
  stack.push(8);
  stack.push(6);
  stack.push(4);

  // This one should kick off a new allocation
  stack.push(2);

  countOff(stack);

  return 0;
}
