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
  Patient* temp = NULL;
  for(int i = 0; i < patientList.elementCount; i++)
    if(patientList[i] == target)
      temp = patientList[i];
  return temp; 
}

void List::printList()
{
  Bubble_sort_descend(this->patientList);
  for(int i =0; i < patientList.elementCount; i++)
  {
    cout << patientList[i] << endl;
  }
}

//Sorting function(descending)
void Bubble_sort_descend(const List& target)
{
  for(int i = 0; i < target.getElementCount(); i++)
    for(int j = 1; j < target.getElementCount(); j++)
    {
      if(target[i] > target[j])//if the order is descending
        continue;
        else{
          Patient temp = target[i];//bubble sorting to swap in order to get descending array
          target[i] = target[j];
          target[j] = temp;
        }
    }
}