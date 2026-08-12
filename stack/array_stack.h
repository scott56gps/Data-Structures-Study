#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include "stack.h"

class ArrayStack : public Stack
{
 private:
  int* dataPtr; // We wish to model a single access point for the data
  int topIndex; // We will use an index to access the chunk of data we want
  int size; // Cardinality: How many elements
  int capacity; // Total allocated space for this container
 public:
  ArrayStack(int store[], int size);
  ~ArrayStack();
  int top() override;
  void pop() override;
  void push(int element) override;
  int getSize() override;
  int getCapacity() override;
  void grow(int newCapacity) override;
  bool isEmpty() override;
};

#endif
