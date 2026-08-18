#include <vector>
#include <iostream>
using namespace std;

template <typename T>
VectorStack<T>::VectorStack(T store[], int size)
{
  this->data = vector<int>();

  // 2. Fill the vector from the back
  for (int i = 0; i < size; i++)
    this->data.push_back(store[i]);
}

template <typename T> VectorStack<T>::~VectorStack() {
  // delete[] this->dataPtr;
}

template <typename T> T VectorStack<T>::top() { return this->data.back(); }

template <typename T> void VectorStack<T>::pop() { this->data.pop_back(); }

template <typename T> void VectorStack<T>::push(int element) {
  this->data.push_back(element);
}

template <typename T> void VectorStack<T>::grow(int additionalCapacity) {
  cout << "Allocating " << additionalCapacity << " new data slots...\n";
  int newCapacity = this->data.capacity() + additionalCapacity;

  this->data.reserve(newCapacity);

  cout << "New capacity: " << this->data.capacity() << endl;
}

template <typename T> int VectorStack<T>::getSize() {
  return this->data.size();
}

template <typename T> int VectorStack<T>::getCapacity() {
  return this->data.capacity();
}

template <typename T> bool VectorStack<T>::isEmpty() {
  return this->data.empty();
}
