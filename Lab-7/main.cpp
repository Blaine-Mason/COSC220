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
  Node* nNode = new Node(n);
  if(head == nullptr){
		std::cout << "We Made it" << std::endl;
    return nNode;
  }
  if(head->next == nullptr){
    head->next = nNode;
    return head->next;
  }
  if(n < head->next->value && head->next){
    nNode->next = head->next;
		head->next = nNode;

    return nNode;
  }
  return insertSorted(head->next, n);
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
  print(head);
  reversePrint(head);
  std::cout << std::endl;


 	head = insertSorted(head, 4);
	print(head);
}
