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
    void pop(T &);
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
  top = nullptr;
  while(crsr){
    push(crsr->data);
    crsr = crsr->next;
  }
}
template <class T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T>& rhs){
  Node* crsr = rhs.top;
  if( this == &rhs){
    std::cout << "The Same" << std::endl;
  }else{
    while(crsr){
      push(crsr->data);
      crsr = crsr->next;
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
