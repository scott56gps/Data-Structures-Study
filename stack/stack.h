#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
 public:
  virtual ~Stack() = default;
  virtual T top() = 0;
  virtual void pop() = 0;
  virtual void push(T element) = 0;
  virtual int getSize() = 0;
  virtual int getCapacity() = 0;
  virtual void grow(int newCapacity) = 0;
  virtual bool isEmpty() = 0;
};

#endif
