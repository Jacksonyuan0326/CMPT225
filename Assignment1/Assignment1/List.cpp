#include<iostream>
#include"List.h"
#include"Patient.h"
using namespace std;


//Default constructor
//Pre-condition: set the initial capacity is max_elements.

List::List()
{
	capacity = MAX_ELEMENTS;
	patientList = new Patient[MAX_ELEMENTS];
	elementCount = 0;
}

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{
	delete[]patientList;//de-allocated the patientList
	capacity = 0;//assign all variables to 0
	elementCount = 0;
	patientList = nullptr;
}

int List::getElementCount()const
{
	if (patientList == nullptr)//if patientList is not exiting
		return 0;
	return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement)
{
	//if capacity is currently enough
	//search whether newElement is in the data collection
	if (this->search(newElement) != NULL)
		return false;

	patientList[elementCount++] = newElement;
	Bubble_sort_descend();
	if (elementCount == capacity)
	{
		Patient* temp = new Patient[2 * capacity];
		for (int i = 0; i < capacity; i++)
		{
			temp[i] = patientList[i];
		}
		this->~List();
		patientList = temp;
		capacity *= 2;
	}
	return true;
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove(const Patient& toBeRemoved)
{
	for (int i = 0; i < elementCount; i++) {
		if (patientList[i] == toBeRemoved) {//while the content of cell is same as the target 
			for (int j = i + 1; j < elementCount; i++)//from this position, every cell towards move forwards one cell
				patientList[i] = patientList[j++];
			elementCount--;
		}
		return true;
	}
	return false;//if nothing to remove, return false
}

void List::removeAll()
{
	int newCapacity = capacity;//record original capacity
	delete[]patientList;//delete all elements
	patientList = new Patient[newCapacity];//assign a new allocated memory to it
	elementCount = 0;//assign elementCount back to 0
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target)
{
	for (int i = 0; i < elementCount; i++)
		if (patientList[i] == target) {
			return &patientList[i];
		}
	return NULL;
}

void List::printList()
{
	for (int i = 0; i < elementCount; i++)
	{
		cout << patientList[i] << endl;
	}
}

//Sorting function(descending)
void List::Bubble_sort_descend()
{
	Patient temp;
	for (int i = 0; i < getElementCount(); i++)
		for (int j = 1; j < getElementCount(); j++)
		{
			if (patientList[i] > patientList[j])//if the order is descending
				continue;
			else {
				temp = patientList[i];//bubble sorting to swap in order to get descending array
				patientList[i] = patientList[j];
				patientList[j] = temp;
			}
		}
}