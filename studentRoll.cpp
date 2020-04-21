#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
    Node *new_node;
    Student a = new Student(s);
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
    std:string output = "[";
    Node *temp = head;
    while(temp){
        output = output + temp->s->toString();
        if(temp->next != NULL){
            output = output + ",";
        }
        temp = temp->next;
    }
    output = output + "]";
    return output;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
    head = tail = NULL;
    Node *temp = orig.head;
    while(temp){
        insertAtTail(*(temp->s));
        temp = temp->next;
    }

    
}

StudentRoll::~StudentRoll() {
    Node *temp = head;
    while(temp){
        Node *temp2 = temp;
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
    
    Node* temp = right.head;
    while(temp){
        insertAtTail(*(temp->s));
        temp = temp->next;
    }

  // TODO... Here is where there is code missing that you need to 
  // fill in...


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





