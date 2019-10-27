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
  }if(head->value > n && head->next != nullptr){
    std::cout << "Hi" << std::endl;
    Node* nNode = new Node(n);
    return nNode;
  }else{
    std::cout << "Hey" << std::endl;
    head->next = insertSorted(head->next, n);
    return head;
  }
}
void print(Node* head){
  if(head == nullptr){
    std::cout << std::endl;
    return;
  }
  std::cout << head->value << " ";
  print(head->next);
}

void reversePrint(Node* head){
  if(head == nullptr){
    return;
  }
  reversePrint(head->next);
  std::cout << head->value << " ";
}
Node* remove(Node* head, int n){
  if(head == nullptr){
    Node* nNode = new Node(n);
    return nNode;
  }if(head->value == n){
    Node* nNode = new Node;
    nNode = head;
    head = head->next;
    return nNode;
  }else{
    head = remove(head->next, n);
  }
}
Node* appendList(Node* head, Node* head2){
  if(head2->next != nullptr){
    head->next = head2;
    return head;
  }else{
     return appendList(head->next, head2);
  }
}
Node* reverse(Node* head){
  if(head->next == nullptr){
    return head;
  }else{
    head = reverse(head->next);
    return reverse(head);
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
  n3->next = nullptr;

  std::cout << length(head) << std::endl;
  print(head);
  reversePrint(head);
  std::cout << std::endl;


 	//head = insertSorted(head, 2);
	//print(head);

  Node* removedNode = new Node;
  removedNode = remove(head, 2);
  print(head);
  std::cout << removedNode->value << std::endl;

  Node* head2 = nullptr;
  Node* n4 = new Node;
  Node* n5 = new Node;
  Node* n6 = new Node;
  n4->value = 4;
  n5->value = 5;
  n6->value = 6;
  head2 = n4;
  head2->next = n5;
  n5->next = n6;
  n6->next = nullptr;

  head = appendList(head, head2);
  print(head);

  head = reverse(head);
  print(head);
}
