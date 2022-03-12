#include"Dictionary.h"
#include"BST.h"
using namespace std;


template <class ElementType>
Dictionary<ElementType>::Dictionary()
{
	keyValuePairs = new BST<ElementType>();
}


template <class ElementType>
Dictionary<ElementType>::Dictionary(ElementType& element)
{
	keyValuePairs = new BST<ElementType>(element);
}


template <class ElementType>
Dictionary<ElementType>::~Dictionary()
{
	keyValuePairs->~BST();
	delete[]keyValuePairs;
}

template <class ElementType>
unsigned int Dictionary<ElementType>::getElementCount() const
{
	return keyValuePairs->getElementCount();
}
template <class ElementType>
void Dictionary<ElementType>::put(const ElementType& newElement)
{
	keyValuePairs->insert(newElement);
}
template <class ElementType>
ElementType& Dictionary<ElementType>::get(const ElementType& targetElement) const
{
	return keyValuePairs->retrieve(targetElement);
}
template <class ElementType>
void Dictionary<ElementType>::displayContent(void visit(const ElementType&)) const
{
	keyValuePairs->traverseInOrder(visit);
}