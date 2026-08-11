#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int store[], int size)
{
  this->size = size;
  this->capacity = size;

  // 1. Allocate memory on the heap according to the size
  // This is now a window into a range of data, addressable by int-sized chunks
  this->dataPtr = new int[size];

  // 2. Fill the allocated memory from the back
  for (int i = 0; i < size; i++)
    this->dataPtr[size - 1 - i] = store[i];

  this->topIndex = size - 1;
}

Stack::~Stack()
{
  delete[] this->dataPtr;
}

int Stack::top()
{
  return this->dataPtr[topIndex];
}

void Stack::pop()
{
  this->topIndex = this->topIndex - 1;
  this->size--;
}

void Stack::push(int element)
{
  if(this->topIndex == (this->capacity - 1))
    {
      this->grow(5);
    }
  this->dataPtr[topIndex + 1] = element;
  this->topIndex = this->topIndex + 1;
  this->size++;
  cout << "Pushed " << element << endl;
}

void Stack::grow(int additionalCapacity)
{
  cout << "Allocating " << additionalCapacity << " new data slots...\n";
  cout << "Current Capacity: " << this->capacity << endl;
  int newCapacity = this->capacity + additionalCapacity;
  int* newStartPtr = new int[newCapacity];

  for (int i = topIndex; i >= 0; i--)
    newStartPtr[i] = dataPtr[i];

  delete[] this->dataPtr;
  this->dataPtr = newStartPtr;
  this->capacity = newCapacity;

  cout << "New capacity: " << this->capacity << endl;
}

int Stack::getSize()
{
  return this->size;
}

int Stack::getCapacity()
{
  return this->capacity;
}

bool Stack::isEmpty()
{
  return topIndex < 0;
}
