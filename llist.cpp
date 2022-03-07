//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Austin Yono
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist() { 
     
  //     cout << "... in llist constructor..." << endl; 
  
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

llist::~llist() {
 
  //     cout << ".... in llist destructor..." << endl;
     
  el_t num;

  while (isEmpty() == false) {
    deleteFront(num);
  }
}

// PURPOSE: 
// PARAMETER: 
bool llist::isEmpty() {
     
  if (Front == NULL && Rear == NULL && Count == 0) {
    return true;
  } else {
    return false;
  }
} // be sure to check all 3 data members

// PURPOSE:
// PARAMETER:
void llist::displayAll() { 

  Node* P = Front;

  if (isEmpty()) {
    cout << "[ EMPTY ]\n";
  } else {
    cout << "[ ";
    while (P != NULL) {
      cout << P -> Elem << " ";
      P = P -> Next;
    }
    cout << "]\n";
  }

}  // be sure to display horizontally in [  ] with
// blanks between elements
  
// PURPOSE:
// PARAMETER:
void llist::addRear(el_t NewNum) {

  if (isEmpty()) {
    Front = new Node();
    Front -> Elem = NewNum;
    Rear = Front;
    Rear -> Next = NULL;
    Count++;
  } else {
    Rear -> Next = new Node();
    Rear = Rear -> Next;
    Rear -> Elem = NewNum;
    Rear -> Next = NULL;
    Count++;
  }
} // comment the 2 cases

// PURPOSE:
// PARAMETER:
void llist::addFront(el_t NewNum) { 
     
  if (isEmpty()) {
    Front = new Node();
    Front -> Elem = NewNum;
    Rear = Front;
    Rear -> Next = NULL;
    Count++;
  } else {
    Node* Temp = new Node();
    Temp -> Elem = NewNum;
    Temp -> Next = Front;
    Front = Temp;
    Count++;
  }

} // comment the 2 cases

// PURPOSE:
// PARAMETER:
void llist::deleteFront(el_t& OldNum) { 
     
  if (isEmpty()) {
    throw Underflow();
  } else if (Count == 1) {
    OldNum = Front -> Elem;
    delete Front;
    Front = NULL;
    Rear = NULL;
    Count--;
  } else { 
    OldNum = Front -> Elem;
    Node* Second;
    Second = Front -> Next;
    delete Front;
    Front = Second;
    Count--;
  }
} // comment the 3 cases

// PURPOSE:
// PARAMETER:
void llist::deleteRear(el_t& OldNum) {

  if (isEmpty()) {
    throw Underflow();
  } else if (Count == 1) {
    OldNum = Rear -> Elem;
    delete Rear;
    Front = NULL;
    Rear = NULL;
    Count--; 
  } else {
    OldNum = Rear -> Elem;
    Node* P;
    P = Front;
    while (P -> Next != Rear) {
      P = P -> Next;
    }
    delete Rear;
    Rear = P;
    Rear -> Next = NULL;
    Count--;
  }
} // comment the 3 cases


/* harder ones follow */

// Utility Function to move a local pointer to the Ith node
void llist::moveTo(int I, Node*& temp) { // moves temp I-1 times

  for (int j = 1; j <= I - 1; j++) {
    temp = temp -> Next;
  }
}

// PURPOSE:
// PARAMETER:
void llist::deleteIth(int I, el_t& OldNum) { 

  Node* P = Front;

  if (I > Count || I < 1) {
    throw OutOfRange();
  } if (I == 1) {
    deleteFront(OldNum);
  } else if (I == Count) {
    deleteRear(OldNum);
  } else {
    moveTo(I-1, P);  
    Node* Q = P -> Next;
    P -> Next = Q -> Next;
    delete Q;
    Count--;
  }

} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.  

// PURPOSE:
// PARAMETER:
void llist::insertIth(int I, el_t newNum) { 

  Node* P = new Node;
  P -> Elem = newNum;
  P -> Next = NULL;

  if (I > (Count + 1) || I < 1) {     
    throw OutOfRange();
  } if (I == 1) {
    addFront(newNum);      
  } else if (I == (Count + 1)) {
    addRear(newNum);
  } else {
    Node* Q = Front;
    moveTo(I-1, Q);
    P -> Next = Q -> Next;
    Q -> Next = P;
    Count++;
  }

} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.

// PURPOSE:
// PARAMETER:
llist::llist(const llist& Original) { 
     
  Front = NULL;
  Rear = NULL;
  Count = 0;
  Node* P;
  P = Original.Front;

  while (P != NULL) {
    this -> addRear(P -> Elem);
    P = P-> Next;
  }
} // use my code

// PURPOSE:
// PARAMETER:
llist& llist::operator=(const llist& OtherOne) { 

  el_t x;

  if (&OtherOne != this) {
    while (!this -> isEmpty()) {
      this -> deleteRear(x);
    }
    Node* P;
    P = OtherOne.Front;
    while (P != NULL) {
      this -> addRear(P -> Elem);
      P = P -> Next;
    }
  }
  return *this;
} // use my code
