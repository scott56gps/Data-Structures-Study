#ifndef STACK_H
#define STACK_H
#include <stack>

class Stack
{
 private:
  // int* dataPtr; // We wish to model a single access point for the data
  std::stack<int> data;
  int topIndex; // We will use an index to access the chunk of data we want
  int size; // Cardinality: How many elements
  int capacity; // Total allocated space for this container
 public:
  Stack(int store[], int size);
  ~Stack();
  int top();
  void pop();
  void push(int element);
  int getSize();
  int getCapacity();
  void grow(int newCapacity);
  bool isEmpty();
};

#endif
