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
  if(head == nullptr || n < head->value){
    Node* nNode = new Node(n);
    return nNode;
  }else{
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
    return nullptr;
  }if(head->value == n){
    Node* t = head->next;
    delete head;
    return t;
  }
  head->next = remove(head->next, n);
  return head;
}
Node* appendList(Node* head, Node* head2){
  if(head == nullptr){
    return head2;
  }if(head2 == nullptr){
    return head;
  }else{
     Node* c = appendList(head->next, head);
     c->next = head2;
  }
  return head;
}
Node* reverse(Node* head){
  if(head->next == nullptr){
    return head;
  }
  Node* nNode = reverse(head->next);
  head->next->next = head;
  head->next = nullptr;
  return nNode;
}
void deleteLists(Node* head){
  if(head != nullptr){
    Node* crsr = head;
    while(crsr){
      crsr = crsr->next;
      delete head;
      head = crsr;
    }
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

  std::cout << "Length Test: " << std::endl;
  std::cout << length(head) << std::endl;
  std::cout << "Print Test: " << std::endl;
  print(head);
  std::cout << "Reverse Print Test: " << std::endl;
  reversePrint(head);
  std::cout << std::endl;

  std::cout << "insertSorted Test(value 4): " << std::endl;
 	head = insertSorted(head, 4);
	print(head);

  std::cout << "Remove Test: " << std::endl;
  Node* removedNode = new Node;
  removedNode = remove(head, 2);
  print(head);
  std::cout << "Removed Node: " << std::endl;
  std::cout << removedNode->value << std::endl;

  Node* head2 = nullptr;
  Node* n4 = new Node;
  Node* n5 = new Node;
  Node* n6 = new Node;
  n4->value = 6;
  n5->value = 7;
  n6->value = 8;
  head2 = n4;
  head2->next = n5;
  n5->next = n6;
  n6->next = nullptr;

  std::cout << "appendList Test: " << std::endl;
  //head = appendList(head, head2);
  print(head);

  std::cout << "Reverse Test: " << std::endl;
  head2 = reverse(head2);
  print(head2);
  delete removedNode;
  deleteLists(head);
  deleteLists(head2);



}
