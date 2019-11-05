 #include "payrolllist.h"


//constructor
PayRollList::PayRollList()
{
	head = nullptr;
}
//destructor
PayRollList::~PayRollList()
{
	//set a new crsr to the first node in the list
	ListNode* crsr = head;
	//while the crsr is pointing to something
	while(crsr)
	{
		//crsr moves forward, head is deleted, and head now points to crsr
		crsr = crsr->next;
		delete head;
		head = crsr;
	}
}
// copy constructor, passes in another list by reference
// and copy each element into the new list
PayRollList::PayRollList(PayRollList& oldP){
	//crsr points to the old lists head
	ListNode* crsr = oldP.head;
	//the new list is empty
	head = nullptr;
	while(crsr != nullptr){
		//uses the insert() to place the elements from the old list into the new
		insert(crsr->p);
		crsr = crsr->next;
	}
}

//returns number of elements in the lists
int PayRollList::length(){
	int total = 0;
	//crsr starts at head
	ListNode* crsr = head;

	while(crsr != nullptr){
		//counts an element then moves forward till the end
		total++;
		crsr = crsr->next;
	}
	//returns the total element
	return total;
}

// An overloaded index operator
// Takes an integer index and (if it exissts)
// returns a *reference to* the payroll inside it
// () returns nullptr if the objest is not there
PayRoll* PayRollList::operator[](int n){
	//crsr starts at the head
	ListNode* crsr = head;
	//length is assigned the length of the list
	int length = this->length();
	if(length < n){//if the index doesn't exist
    cout << "Index Out of Bounds" << endl;
		return nullptr;
	}else{//if it does exist
		for(int i = 0; i < n; i++){
			//move forward until the node is pointed to
			crsr = crsr->next;
		}
		//return a refernce to the object at the given index
		return &crsr->p;
	}
}
PayRollList PayRollList::operator=(const PayRollList& rhs){
  if(this == &rhs){
    std::cout << "They are the same." << std::endl;
  }else{
    ListNode* crsr = this->head;
    while(crsr){
      crsr = crsr->next;
      delete this->head;
      this->head = crsr;
    }
    head = nullptr;
    int index = 0;
    crsr = rhs.head;
    while(crsr){
      this->insert(index, crsr->p);
      crsr = crsr->next;
    }
  }
}
bool PayRollList::operator<(const PayRollList p1, const PayRollList p2){
  crsr1 = p1->head;
  crsr2 = p2->head;

  int sum1 = 0, sum2 = 0;
  while(crsr1){
    sum1 += crsr1->p.getPay();
    crsr1 = crsr1->next;
  }
  while(crsr2){
    sum2 += crsr2->p.getPay();
    crsr2 = crsr2->next;
  }
  return sum1 < sum2;
}
std::ostream& operator<<(std::ostream&, const PayRollList&){

}

// Remove the list item at the index given
void PayRollList::remove(int n){
	//prev and crsr are created
	ListNode* prev;
	ListNode* crsr;
  if(n > this->length() || n < 0){
    cout << "Index out of bounds" << endl;
    return;
  }else if(n == 0){
		//if the index removed is at the beginning
		//have crsr point to the next and delete head
		crsr = head->next;
		delete head;
		//have head point to crsr(head->next)
		head = crsr;
	}else{//if the element is not at the beginning
		//have crsr point at the head
		crsr = head;
		for(int i = 0; i < n; i++){
			//let prev and crsr move forward until the index is reached
			prev = crsr;
			crsr = crsr->next;
		}
		//the next node from prev point now to the crsr->next
		prev->next = crsr->next;
		//crsr is deleted to free that block
		delete crsr;
	}

}

// Copy a PayRoll object into a specific position
void PayRollList::assign(int n, PayRoll pRoll){
	ListNode* nNode = new ListNode;
	ListNode* crsr = head;
	//newnode is given the attributes of pRoll
	nNode->p = PayRoll(pRoll.getName(), pRoll.getRate(), pRoll.getHours());
	nNode->next = nullptr;
	//when n is at the beginning
	if(n == 0){
		//allow the heads object to be assigned the nNodes object
		head->p = nNode->p;
		//free nNode from the heap
		delete nNode;
	}else{
		for(int i = 0; i < n; i++){
			//move until the index
			crsr = crsr->next;
			if(crsr == nullptr){
				cout << "That index does not exist in the list." << endl;
				delete nNode;
				return;
			}
		}
		//the given node is found and assigned the nNodes object
		crsr->p = nNode->p;
		delete nNode;
	}

}

// Inserts the PayRoll into the list so that it is
// in the specified position
void PayRollList::insert(int n, PayRoll pRoll){
	ListNode* nNode = new ListNode;
	ListNode* prev = head;
	ListNode* crsr = nullptr;
	nNode->p = pRoll;
	if(n == 0){
		//nNode is inserted into the beginning of the list
		nNode->next = head;
		head = nNode;
	}else{
		//prev and crsr move until the inserted index is reached
		crsr = head;
		for(int i = 0; i < n; i++){
			prev = crsr;
			crsr = crsr->next;
		}
    //the nNode is placed between prev and crsr
  	prev->next = nNode;
  	nNode->next = crsr;
	}

}
// Takes name, rate, and hours worked as
// parameters for a new ListNode.
// The new node may sorted by payrate
void PayRollList::insert(string name, double rate, double hours)
{
	//A new node is created to be added to the list
	ListNode* nNode = new ListNode;
	//Sets the new nodes PayRoll object to the given information
	nNode->p  = PayRoll(name, rate, hours);
	//Sets the next node that our new node points to
	//a nullptr since the locaction the node is being inserted to
	//is unknown.
	nNode->next = nullptr;
	//A crsr node is made to start at head and keep track of the
	//current node as well as the next node
	ListNode* crsr = head;

	//if the list is empty, let the head point to the new node
	if(head == nullptr){
		head = nNode;
		return;
	}else if(nNode->p.getRate() < head->p.getRate()){//if the new nodes payrate is less than the head's payrate
	head = nNode;
	nNode->next = crsr;
}else{
	//while crsr isn't at the end and the node in front of crsr is less than the new nodes rate
	while((crsr->next != nullptr) && crsr->next->p.getRate() < nNode->p.getRate())
	{
		//crsr moves forward in the list
		crsr = crsr->next;
	}
	if(crsr->next == nullptr){//the crsr has reached the end of the list
		crsr->next = nNode;
		nNode->next = nullptr;
	}else{

		//Inserts the node between crsr and crsr-next since crsr stops where the
		//node is to be inserted
		nNode->next = crsr->next;
		crsr->next = nNode;
	}
}
}

// Overide, accept a PayRoll object directly.
// To make life easy, this should either call or
// be called from insert(string, double, double)
// rather than repeat the logic!
void PayRollList::insert(PayRoll nPayRoll)
{
	insert(nPayRoll.getName(), nPayRoll.getRate(), nPayRoll.getHours());
}
// Prints each employee name and total pay to the terminal
// or, optionally, to a text file(loosely simulating the user
// pressing the "print" button in a program)
void PayRollList::printPayChecks()
{
	ListNode* crsr = head;
	while(crsr){
		crsr->p.displayInfo();
		crsr = crsr->next;
	}
}
