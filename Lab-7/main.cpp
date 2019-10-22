#include <iostream>

struct Node{
  int value;
  Node* next;
  Node(){
    value = 0;
    next = nullptr;
  }
  Node(int n){
    value = n;
    next = nullptr;
  }
};

int length(Node* head){
  if (head == nullptr){
    return 0;
  }else{
    return length(head->next) + 1;
  }
}

Node* insertSorted(Node* head, int n){
  if(head == nullptr){
    Node* nNode = new Node(n);
    return nNode;
  }
  if(val < head->value){
    Node* nNode = new Node(n);
    nNode->next = head;
    return nNode;
  }   
}



int main(){
  Node* head = nullptr;
  Node* n1 = new Node;
  Node* n2 = new Node;
  Node* n3 = new Node;
  n1->value = 1;
  n2->value = 2;
  n3->value = 3;
  head = n1;
  head->next = n2;
  n2->next = n3;
  n3 = nullptr;

  std::cout << length(head) << std::endl;
  
}

