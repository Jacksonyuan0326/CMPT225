/* 
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: Yu Yuan 301387501
 * Date: FEB 16, 2022
 */
 
#include <cstddef>  // For NULL
#include "Stack.h"

using namespace std;


// Description:  Constructor
// Postcondition:  Stack is empty
Stack::Stack()
{
    head = nullptr;
    tail = nullptr;//make headnode and tailnode both to nullptr
}

// Description:  Destrcuctor
// Postcondition:  will de-allocated the elements pointer
Stack::~Stack()
{
	while (head != nullptr)
		pop();
}


/*Big-O: O(n) because insert one elements will need O(1) operation
		insert n elements will need O(n) operation*/
void Stack::push(int x)
{
    StackNode* newNode = new StackNode();  //create a new StackNode for temp in the heap
    newNode->data = x; //assign value to the newNode
    if(isEmpty()){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;  //make tailnode next pointer to newNde
        tail = newNode; //make newNode be the tailnode
    }
}

/*Big-O: O(n) because delete one elements will need O(1) operation
		delete n elements will need O(n) operation*/
// Description:  Remove and return element at the top of the stack.
// Pre-condition: if the stack is not empty
// Postcondition: return the value of the top node and return NULL if the stack is empty
int Stack::pop()
{
    if(isEmpty())
      return NULL;
    else if(head == tail){
            int data = head->data;
            delete[]head;
            head = NULL;
            tail == NULL;
            return data;
    }
    else{// len > 1
        StackNode* curNode = this->head;
        while(curNode->next->next != NULL)
        {
            curNode = curNode->next;
        }
        int data = curNode->next->data;
        delete[]tail;
        tail = curNode;
        curNode->next = NULL;
        return data;
    }
}


// Description:  Return the topmost element of the stack.
// Precondition:  if stack is not empty
// Postcondition: return the value of the top element, return NULL if empty
int Stack::peek() const
{ 
    if(isEmpty()) 
        return NULL;
    return tail->data;
}


// Description:  
// Postcondition:  
bool Stack::isEmpty() const
{
    return head == NULL;
}