#include "SUList.h"

template <class DataType>
SUList<DataType>::SUList(){ // Default ctor
	head = nullptr;
	tail = nullptr;
}

template <class DataType>
SUList<DataType>::SUList(const SUList& rhs){ // Copy ctor
	std::cout << "Copy Constructor Called" << std::endl << std::endl;
	ListNode* crsr = rhs.head;

	int count = 0;

	while(crsr){
		count++;
		crsr = crsr->next;
	}
	crsr = rhs.head;
	ListNode* temp = rhs.head;
	head = nullptr;
	tail = nullptr;

	for(crsr = rhs.head; crsr; crsr = crsr->next){
		for(int i = 0; i < count - 1; i++){
			temp = temp->next;
		}
		putFront(temp->data);
		temp = rhs.head;
		count--;
	}
}

template <class DataType>
SUList<DataType>::~SUList(){ // Destructor
	std::cout << "Destructing List..." << std::endl;
	ListNode* crsr = head;
	while(crsr){
		ListNode* temp = crsr->next;
		delete crsr;
		crsr = temp;
		
	}
}

template <class DataType>
DataType SUList<DataType>::getFront(){// Remove & return the front
	ListNode* temp = head;
	DataType t = head->data;
	head = head->next;
	delete temp;
	return t;
}

template <class DataType>
DataType SUList<DataType>::getBack(){ // Remove & return the back
	ListNode* temp = tail;
	DataType t = tail->data;
	if(head && tail){
		tail = temp->prev;
		tail->next = nullptr;
		delete temp;
		return t;
	}else{
		tail = temp->prev;
		head = nullptr;
		delete temp;
		return t;
	}
}

template <class DataType>
void SUList<DataType>::putFront(const DataType& d){// Add to the front
	ListNode* nNode = new ListNode;
	nNode->data = d;
	nNode->next = nullptr;
	nNode->prev = nullptr;
	if(!head && !tail){
		nNode->next = head;
		head = nNode;
		tail = nNode;
	}else{
		nNode->next = head;
		head->prev = nNode;
		head = nNode;
	}
	ListNode* crsr = head;
	while(crsr->next){
		crsr = crsr->next;
	}
	tail = crsr;
}

template <class DataType>
void SUList<DataType>::putBack(const DataType& d){ // Add to the back
	ListNode* nNode = new ListNode;
	nNode->data = d;
	nNode->next = nullptr;
	nNode->prev = nullptr;
	if(!tail && !head){
		nNode->prev = tail;
		head = nNode;
		tail = nNode;
	}else{
		nNode->prev = tail;
		tail->next = nNode;
		tail = nNode;
	}
}

template <class DataType>
int SUList<DataType>::size() const{ // Returns the number of elements
	ListNode* crsr = head;
	int count = 0;
	while(crsr){
		count++;
		crsr = crsr->next;
	}
	return count;
}

template <class DataType>
bool SUList<DataType>::contains(const DataType& d){// Tests for membership
	ListNode* crsr = head;
	while(crsr){
		if(crsr->data == d){
			std::cout << "List contains " << d << std::endl;
			return true;
		}else{
			crsr = crsr->next;
		}
	}
	std::cout << "List does not contain " << d << std::endl;
	return false;
}

template <class DataType>
SUList<DataType>& SUList<DataType>::operator=(const SUList<DataType>& rhs){ // Overloaded assignment
	std::cout << "= Overload Called" << std::endl << std::endl;
	int count = 0;
	if(this == &rhs){
		std::cout << "Self Assignment" << std::endl;
		ListNode* temp = nullptr;
		return *this;
	}else{
		ListNode* crsr = this->head;
		while(crsr){
			ListNode* nextN = crsr->next;
			delete crsr;
			crsr = nextN;
		}
		crsr = rhs.head;
		while(crsr){
			count++;
			crsr = crsr->next;
		}
		crsr = rhs.head;
		ListNode* temp = rhs.head;
		this->head = nullptr;
		this->tail = nullptr;

		for(crsr = rhs.head; crsr; crsr = crsr->next){
			for(int i = 0; i < count - 1; i++){
				temp = temp->next;
			}
			this->putFront(temp->data);
			temp = rhs.head;
			count--;
		}
		return *this;
	}

}

template <class DataType>
void SUList<DataType>::display() const{
	ListNode* crsr = head;
	std::cout << "List: " << std::endl;
	while(crsr){
		std::cout << crsr->data << std::endl;
		crsr = crsr->next;
	}
	std::cout << std::endl;
}
