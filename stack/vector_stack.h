#ifndef VECTOR_STACK_H
#define VECTOR_STACK_H
#include "stack.h"
#include <vector>

class VectorStack : public Stack
{
 private:
  std::vector<int> data;
 public:
  VectorStack(int store[], int size);
  ~VectorStack();
  int top() override;
  void pop() override;
  void push(int element) override;
  int getSize() override;
  int getCapacity() override;
  void grow(int newCapacity) override;
  bool isEmpty() override;
};

#endif
