#include"List.h"
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
	delete[]patientList;
	capacity = 0;
	elementCount = 0;
	patientList = nullptr;
}

int List::getElementCount()const
{
	if (patientList == nullptr)
		return 0;
	int count = 0;

}

bool List::insert(const Patient& newElement)
{
	//if capacity is currently enough
	//case 1: if elementsCount is less than capacity after inserting one element


	//case 2: if elementsCount is greater than capacity after inserting one element

}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove(const Patient& toBeRemoved)
{
	for(int i = 0; i < elementCount; i++)
		if (patientList[i] == toBeRemoved) {
			for (int j = i + 1; j < elementCount; j++)
				patientList[i] == patientList[j];
			elementCount--;
			return true;
		}
	return false;
}

void List::removeAll()
{

}

Patient* List::search(const Patient& target)
{

}

void List::printList()
{

}