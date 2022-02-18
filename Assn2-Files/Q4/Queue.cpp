/* 
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author:
 * Date:
 */
 
#include "Queue.h"


// Description:  Constructor
Queue::Queue() : elementCount(0), capacity(INITIAL_CAPACITY), frontindex(0), backindex(0) {
	elements = new int[INITIAL_CAPACITY];
} 

// Description: Destructor
Queue::~Queue()
{
	elementCount = 0;
	delete[]elements;
	frontindex = 0;
	backindex = 0;
}

// Description:  Inserts element x at the back (O(1))
void Queue::enqueue(int x) {
	// check whether the capacity is full
	//if full, double array size and copy the elements of old array to the new array
	if (elementCount+1 == capacity)
	{
		int* temp = new int[2 * capacity];
		for (int i = 0; i < elementCount; i++)
			temp[i] = elements[i];
		temp[elementCount] = x;
		~Queue();
		elements = temp;
		backindex++;
		elementCount++;
	}
	//else it will direct insert
    elementCount++;
    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;
} 


// Description:  Removes the frontmost element (O(1))
// Precondition:  Queue not empty
void Queue::dequeue() {
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
} 


// Description:  Returns a copy of the frontmost element (O(1))
// Precondition:  Queue not empty
int Queue::peek() const {
    return elements[frontindex];
} 


// Description:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return elementCount == 0;
}




