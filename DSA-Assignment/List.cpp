#include <iostream>
using namespace std;

#include "List.h"


List::List()
{
	firstNode = NULL;
	size = 0;
}

bool List::add(ItemType item)
{
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (isEmpty())
		firstNode = newNode;
	else {
		Node* temp = firstNode;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	size++;
	return true;
}

bool List::add(int index, ItemType item)
{
	bool success = (index >= 0) && (index < size);
	if (success)
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		if (index == 0)
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else {
			Node* temp = firstNode;
			for (int i = 0; i < index - 1;i++)
				temp = temp->next;
			newNode->next = temp->next;
			temp->next = newNode;
		}
		size++;
	}
	return success;
}

void List::remove(int index)
{
	bool success = (index >= 0) && (index < size);
	if (success)
	{
		if (index == 0)
		{
			Node* temp = firstNode;
			firstNode = firstNode->next;
			temp->next = NULL;
			delete temp;
		}
		else {
			Node* current = firstNode;
			Node* previous = firstNode;
			for (int i = 0; i < index - 1;i++)
			{
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
			current->next = NULL;
			delete current;
		}
		size--;
	}
}

ItemType List::get(int index)
{

	Node* current = firstNode;
	for (int i = 0; i < index;i++)
	{
		current = current->next;
	}
	return current->item;
}



bool List::isEmpty()
{
	return size = 0;
}

int List::getLength()
{
	return size;
}

void List::print()
{
	Node* temp = firstNode;
	if (isEmpty())
	{
		while (temp != NULL)
		{
			cout << temp->item.print() << endl;
			temp = temp->next;
		}
	}
	else
		cout << "The list is empty." << endl;
}
