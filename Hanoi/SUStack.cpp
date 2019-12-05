#include "SUStack.h"
#include <iostream>


template <class DataType>
SUStackArr<DataType>::SUStackArr(){ // Constructor
  capacity = 3;
  top = -1;
  arr = new DataType[capacity];
}

template <class DataType>
SUStackArr<DataType>::SUStackArr(const SUStackArr& rhs){ // Copy Constructor
  std::cout << "Copy Constructor Called" << std::endl << std::endl;
  capacity = rhs.capacity;
  top = rhs.top;
  arr = new DataType[capacity];
  for(int i = 0; i < capacity; i++){
    arr[i] = rhs.arr[i];
  }
}

template <class DataType>
SUStackArr<DataType>::~SUStackArr(){ // Destructor
  std::cout << "Destructing StackArr..." << std::endl;
  delete[] arr;
}

template <class DataType>
int SUStackArr<DataType>::size() const{ // get the number of elements in the stack
  return top + 1;
}

template <class DataType>
bool SUStackArr<DataType>::isEmpty() const{ // Check if the stack is empty
  return size() == 0;
}

template <class DataType>
void SUStackArr<DataType>::push(const DataType& d){ // Pushes an object onto the stack
  std::cout << "Pushing: " << d << std::endl;
  if(top == capacity - 1){
    capacity++;
    arr = copyArr(arr, capacity, top);
    top++;
    arr[top] = d;
  }else{
    top++;
    arr[top] = d;
  }
}

template <class DataType>
void SUStackArr<DataType>::pop(DataType& d){ // Pop an object off the stack and store it
  d = arr[top];
  std::cout << "Popping: " << d << std::endl;
  top--;
  capacity--;
  arr = copyArr(arr, capacity, top);
}

template <class DataType>
void SUStackArr<DataType>::printStack() const{ // Prints the stack from the top, down
  std::cout << "Stack: " << std::endl;
  for(int i = 0; i < capacity; i++){
    std::cout << arr[i] << std::endl;
  }
  std::cout << std::endl;
}

template <class DataType>
SUStackArr<DataType>& SUStackArr<DataType>::operator=(const SUStackArr<DataType>& rhs){ // Assignment operator
  std::cout << "= Overload Called" << std::endl << std::endl;
  delete[] this->arr;
  capacity = rhs.capacity;
  top = rhs.top;
  this->arr = new DataType[capacity];
  for(int i = 0; i < capacity; i++)
    this->arr[i] = rhs.arr[i];
  return *this;
}
template <class DataType>
DataType* SUStackArr<DataType>::copyArr(DataType* arr, int cap, int t){
  DataType* newArr;
  newArr = new DataType[cap];
  for(int i = 0; i <= t; i++){
    newArr[i] = arr[i];
  }
  delete[] arr;
  return newArr;
}






template <class DataType>
SUStackList<DataType>::SUStackList(){ // Constructor

}

template <class DataType>
SUStackList<DataType>::SUStackList(const SUStackList & rhs){ // Copy Constructor
}

template <class DataType>
SUStackList<DataType>::~SUStackList(){ // Destructor

}

template <class DataType>
int SUStackList<DataType>::size() const{ // get the number of elements in the stack
  return list.size();
}

template <class DataType>
bool SUStackList<DataType>::isEmpty() const{ // Check if the stack is empty
  return size() == 0;
}

template <class DataType>
void SUStackList<DataType>::push(const DataType& d){ // Pushes an object onto the stack
  std::cout << "Pushing..." << std::endl << d << std::endl;
  list.putFront(d);
  return;
}

template <class DataType>
void SUStackList<DataType>::pop(DataType& d){ // Pop an object off the stack and store it
  d = list.getFront();
  std::cout << "Popping ..." << std::endl << d << std::endl;
}

template <class DataType>
void SUStackList<DataType>::printStack() const{ // Prints the stack from the top, down
  list.display();
  return;
}
/*
template <class DataType>
SUStackList<DataType>& SUStackList<DataType>::operator=(const SUStackList<DataType>& rhs){ // Assignment operator

}
*/
