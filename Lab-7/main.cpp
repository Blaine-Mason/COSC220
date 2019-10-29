#include <iostream>
//Blaine Mason
//Lab07
//Dr.Anderson
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
/*
* Returns the length of the list
*/
int length(Node* head){
  if (head == nullptr){
    return 0;
  }else{
    return length(head->next) + 1;
  }
}
/*
* Inserts the value into a linked list in a sorted position
*/
Node* insertSorted(Node* head, int n){
  //base case
  if(head == nullptr || n < head->value){
    Node* nNode = new Node(n);
    return nNode;
  }else{
    //move forward until ibase case is met
    head->next = insertSorted(head->next, n);
    //return head of the list
    return head;
  }
}
/*
* Prints Linked List
*/
void print(Node* head){
  if(head == nullptr){
    std::cout << std::endl;
    return;
  }
  std::cout << head->value << " ";
  print(head->next);
}
/*
* Prints Linked List, but in reverse.
*/
void reversePrint(Node* head){
  if(head == nullptr){
    return;
  }
  //swapping two lines is hard
  reversePrint(head->next);
  std::cout << head->value << " ";
}
/*
* Removes an item from the list and returns that item.
* DOES NOT WORK :( Looking forward to being Humbled tomorrow.
*/
Node* remove(Node* head, int n){
  //base case
  if(head == nullptr){
    return nullptr;
  }if(head->value == n){//if we find that value we are looking for
    //Not sure exactly what is going on here
    //I'm trying to "temp" store the next position then delete the current head
    //and return that back to the recursive call
    Node* t = head->next;
    delete head;
    return t;
  }
  //progress forward in the list until the value is found
  head->next = remove(head->next, n);
}
/*
* "Links two lists together"
*/
Node* appendList(Node* head, Node* head2){
  //If either are empty
  if(head == nullptr){
    return head2;
  }if(head2 == nullptr){
    return head;
  }
  //move forward until head gets to the last index
  //then have last node of head point to first of head2
  head->next = appendList(head->next, head2);
  return head;
}
/*
* Reverse the pointers in a Linked List
*/
Node* reverse(Node* head){
  //if the list has one element
  if(head->next == nullptr){
    return head;
  }
  //nNode holds the last element
  Node* nNode = reverse(head->next);
  //pushes the head in front of nNode
  head->next->next = head;
  //sets the end node to be the last node
  head->next = nullptr;
  //returns the "end" of the list
  return nNode;
}
/*
* A "destructor" that could've been done recursively, but I'm facing adversity.
*/
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
  //Node* removedNode = new Node;
  //removedNode = remove(head, 3);
  print(head);
  std::cout << "Removed Node: " << std::endl;
  //std::cout << removedNode->value << std::endl;

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
  head = appendList(head, head2);
  print(head);

  std::cout << "Reverse Test: " << std::endl;
  head2 = reverse(head2);
  print(head2);
  //delete removedNode;
  deleteLists(head);
  deleteLists(head2);



}
