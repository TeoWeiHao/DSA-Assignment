#pragma once
#include<iostream>
using namespace std;
#include "BookingInfo.h"

typedef BookingInfo ItemType;

class List
{
private:
	struct Node
	{
		ItemType item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* firstNode;	// point to the first item
	int  size;			// number of items in the list

public:

	// constructor
	List();

	// add a new item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: new item is added to the back of the list
	//       size of list is increased by 1
	bool add(ItemType newItem);

	// add a new item at a specified position in the list (insert)
	// pre : 1 <= index <= size+1
	// post: new item is added to the specified position in the list
	//       items after the position are shifted back by 1 position
	//       size of list is increased by 1
	bool add(int index, ItemType newItem);

	// remove an item at a specified position in the list
	// pre : 1 <= index <= size
	// post: item is removed the specified position in the list
	//       items after the position are shifted forward by 1 position
	//       size of list is decreased by 1
	void remove(int index);

	// get an item at a specified position of the list (retrieve)
	// pre : 1 <= index <= size
	// post: none
	// return the item in the specified index of the list
	ItemType get(int index);

	void AssignRoomNumber(int index, string rn);

	void setStatus(int index, string s);

	// check if the list is empty
	// pre : none
	// post: none
	// return true if the list is empty; otherwise returns false
	bool isEmpty();

	// check the size of the list
	// pre : none
	// post: none
	// return the number of items in the list
	int getLength();

	//------------------- Other useful functions -----------------

	// display the items in the list
	void print();

	int checkInSearch(string gn, string rt, int nog, string date);

	int checkOutSearch(string gn, string rn, int nog, string date);

	bool isRoomFreeOnDate(string date, string roomNo);

	void guestsOnDate(string date);

	void dateOccupied(int month, int year);

	// void replace(int index, ItemType item);
	// int search(ItemType item);
};

