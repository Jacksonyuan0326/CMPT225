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

// Description:  
// Postcondition:  
Stack::~Stack()
{
	while (head != NULL)
		pop();
}


/*Big-O: O(n) because insert one elements will need O(1) operation
		insert n elements will need O(n) operation*/
void Stack::push(int x)
{
    StackNode* newNode = new StackNode();  //create a new StackNode for temp in the heap
    newNode->data = x; //assign value to the newNode
    newNode->next = tail;  //make tailnode reference pointer to newNde
    tail = newNode; //make newNode be the tailnode
}

/*Big-O: O(n) because delete one elements will need O(1) operation
		delete n elements will need O(n) operation*/
// Description:  Remove and return element at the top of the stack.
//Pre-condition: if the stack is not empty
//Postcondition: return the value of the top node and return NULL if the stack is empty
int Stack::pop()
{
    if(isEmpty())
      return NULL;
    StackNode* newNode =  tail;
    tail = newNode->next;
    delete[]newNode;
}


// Description:  Return the topmost element of the stack.
// Precondition:  
// Postcondition:  
int Stack::peek() const
{ 
    if(isEmpty()) return NULL;
    return tail->data;
}


// Description:  
// Postcondition:  
bool Stack::isEmpty() const
{
    return head == NULL;
}