#ifndef VECTOR_STACK_H
#define VECTOR_STACK_H
#include "stack.h"
#include <vector>

template <typename T>
class VectorStack : public Stack<T>
{
 private:
  std::vector<T> data;
 public:
  VectorStack(T store[], int size);
  ~VectorStack();
  T top() override;
  void pop() override;
  void push(int element) override;
  int getSize() override;
  int getCapacity() override;
  void grow(int newCapacity) override;
  bool isEmpty() override;
};

#include "vector_stack.tpp"
#endif
