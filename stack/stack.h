#ifndef STACK_H
#define STACK_H

class Stack
{
 public:
  virtual ~Stack() = default;
  virtual int top() = 0;
  virtual void pop() = 0;
  virtual void push(int element) = 0;
  virtual int getSize() = 0;
  virtual int getCapacity() = 0;
  virtual void grow(int newCapacity) = 0;
  virtual bool isEmpty() = 0;
};

#endif
