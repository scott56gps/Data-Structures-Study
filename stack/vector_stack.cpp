#include "vector_stack.h"
#include <vector>
#include <iostream>
using namespace std;

VectorStack::VectorStack(int store[], int size)
{
  this->data = vector<int>();

  // 2. Fill the vector from the back
  for (int i = 0; i < size; i++)
    this->data.push_back(store[i]);
}

VectorStack::~VectorStack()
{
  // delete[] this->dataPtr;
}

int VectorStack::top()
{
  return this->data.back();
}

void VectorStack::pop()
{
  this->data.pop_back();
}

void VectorStack::push(int element)
{
  this->data.push_back(element);
}

void VectorStack::grow(int additionalCapacity)
{
  cout << "Allocating " << additionalCapacity << " new data slots...\n";
  int newCapacity = this->data.capacity() + additionalCapacity;

  this->data.reserve(newCapacity);

  cout << "New capacity: " << this->data.capacity() << endl;
}

int VectorStack::getSize()
{
  return this->data.size();
}

int VectorStack::getCapacity()
{
  return this->data.capacity();
}

bool VectorStack::isEmpty()
{
  return this->data.empty();
}
