/* 
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: YUYUAN 301387501
 * Date:FEB 18, 2022
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
	if (elementCount+1 >= capacity)
	{
		int* temp = new int[2 * capacity];
		for (int i = 0; i < elementCount; i++)
			temp[i] = elements[i];
		temp[elementCount] = x;
		delete[]elements;
		elements = temp;
		backindex++;
		elementCount++;
	}
	else{
	//else it will direct insert
    elementCount++;
    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;
	}
} 


// Description:  Removes the frontmost element (O(1))
// Precondition:  Queue not empty, capacity should greater than INITIAL_CAPACITY
// Postcondition: will half capacity if the elements is less than 1/4 current capacity, but resized capacity should greater than INITIAL_CAPACITY
void Queue::dequeue() {
	if(isEmpty())
		return;
	int* temp;
	if(capacity/2 < INITIAL_CAPACITY) // if the half of capacity is less than INITIAL_CAPACITY
	{
		temp = new int[INITIAL_CAPACITY>capacity?INITIAL_CAPACITY:capacity];
		for(int i = 0; i < elementCount - 1; i++)
			temp[i] = elements[i];
		delete[]elements;
		elements = temp;
		capacity = INITIAL_CAPACITY>capacity?INITIAL_CAPACITY:capacity;
		elementCount--;
		backindex--;
	}
	/*else if(elementCount <= (capacity/4) && capacity/2 >= INITIAL_CAPACITY)
	{
		temp = new int[capacity/2];
		for(int i =0; i < elementCount - 1; i++)
			temp[i] = elements[i];
		delete[]elements;
		temp = elements;
		capacity/=2;
		backindex--;
	}*/
	
	if(elementCount < capacity/4 && capacity/2 > INITIAL_CAPACITY)
	{
		temp = new int[capacity/2];
		for(int i = 0; i < elementCount - 1; i++)
			{ 
				temp[i] = elements[i];//copy n -1 elements to new array
			}
		delete[]elements;
		elements = temp;
		elementCount--;
		backindex--;
	}

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



