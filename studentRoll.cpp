#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
	Node* new_node = new Node;
	Student* a = new Student(s);
	new_node->s = a;
	new_node->next = NULL;

	if(head == NULL){
		head = new_node;
		tail = new_node;
	}
	else{
	tail->next = new_node;
	tail = new_node;
	}
}

std::string StudentRoll::toString() const {
	std::string output = "[";
	Node *temp = head;
	while(temp){
		output= output+ temp -> s -> toString();
		if(temp != tail){
			output=output+",";
		}
		temp = temp ->next;
	}
	output = output +"]";
	return output;

}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  // STUB
  head = tail = NULL;
  Node *temp = orig.head;
  while(temp){
	  insertAtTail(*(temp->s));
	  temp = temp -> next;
  }
}

StudentRoll::~StudentRoll() {
  // STUB
  Node* temp = head;
  while(temp != NULL){
	Node* temp2 = temp;
	temp = temp->next;
	delete temp2->s;
	delete temp2;
  }  
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);
  // TODO... Here is where there is code missing that you need to 
  // fill in...
	this->~StudentRoll();
    Node *temp2 = right.head;
    
    while(temp2){
        insertAtTail(*(temp2->s));
        temp2 = temp2 ->next;
    }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}


