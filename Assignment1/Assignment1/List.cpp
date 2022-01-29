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
	delete[]patientList;//de-allocated the patientList
	capacity = 0;//assign all variables to 0
	elementCount = 0;
	patientList = nullptr;
}

int List::getElementCount()const
{
	if (patientList == nullptr)//if patientList is not exiting
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
		if (patientList[i] == toBeRemoved) {//while the content of cell is same as the target 
			for (int j = i + 1; j < elementCounmentCount//from this position, every cell towards move forwards one cell
				patientList[i] == patientList[j];
			elementCount--;
			return true;
		}
	return false;//if nothing to remove, return false
}

void List::removeAll()
{
  int newCapacity = patientList.capacity;//record original capacity
  delete[]patientList;//delete all elements
  patientList = new Patient[newCapacity];//assign a new allocated memory to it
  elementCount = 0;//assign elementCount back to 0
}

Patient* List::search(const Patient& target)
{
  for(int i = 0; i < patientList.elementCount; i++)
    if(patientList[i] == target)
    return
}

void List::printList()
{

}