#ifndef MYSTACK_H
#define MYSTACK_H
#include<iostream>

template <class T>
class MyStack{
  private:
    struct Node{
      T data;
      Node* next;
    };
    Node* top;
/* Fill in stack operations: push, pop, peek */
  public:
    MyStack();
    ~MyStack();
    MyStack(const MyStack&);
    MyStack& operator=(const MyStack&);
    void push(T);
    void pop(T&);
    T peek();
    void displayStack();
};
#endif

template <class T>
MyStack<T>::MyStack(){
  top = nullptr;
}
template <class T>
MyStack<T>::~MyStack(){
  Node* crsr = top;
  while(crsr){
    Node* nextN = crsr->next;
    delete crsr;
    crsr = nextN;
  }
}
template <class T>
MyStack<T>::MyStack(const MyStack& rhs){
  Node* crsr = rhs.top;
  int count = 0;
  while(crsr){
    count++;
    crsr = crsr->next;
  }
  crsr = rhs.top;
  Node* temp = rhs.top;
  top = nullptr;
  for(crsr = rhs.top; crsr; crsr = crsr->next){
    for(int i = 0; i < count - 1; i++){
      temp = temp->next;
    }
    push(temp->data);
    temp = rhs.top;
    count--;
  }
}
template <class T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T>& rhs){
  int count = 0;
  Node* crsr = rhs.top;
  if( this == &rhs){
    std::cout << "The Same" << std::endl;
  }else{
    Node* crsr = this->top;
    while(crsr){
      Node* nextN = crsr->next;
      delete crsr;
      crsr = nextN;
    }
    crsr = rhs.top;
    while(crsr){
      count++;
      crsr = crsr->next;
    }
    crsr = rhs.top;
    Node* temp = rhs.top;
    this->top = nullptr;
    for(crsr = rhs.top; crsr; crsr = crsr->next){
      for(int i = 0; i < count - 1; i++){
        temp = temp->next;
      }
      this->push(temp->data);
      temp = rhs.top;
      count--;
    }
    return *this;
  }
}
template <class T>
void MyStack<T>::push(T t){
  Node* nNode = nullptr;
  nNode = new Node;
  nNode->data = t;
  if(!top){
    top = nNode;
    nNode->next = nullptr;
  }else{
    nNode->next = top;
    top = nNode;
  }
}
template <class T>
void MyStack<T>::pop(T& t){
  if(top == nullptr){
    std::cout << "Empty" << std::endl;
  }else{
    Node* temp = top;
    t = top->data;
    top = top->next;
    delete temp;

  }
}
template <class T>
T MyStack<T>::peek(){
  if(top){
    return top->data;
  }else{
    std::cout << "Stack is Empty" << std::endl;
  }

}
template <class T>
void MyStack<T>::displayStack(){
  Node* crsr = top;
  while(crsr){
    std::cout << crsr->data << " ";
    crsr = crsr->next;
  }
  std::cout << std::endl;
}
