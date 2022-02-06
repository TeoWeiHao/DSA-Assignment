#include <iostream>
using namespace std;

#include "List.h"
#include "time.h"


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
	return size == 0;
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

int List::checkInSearch(string gn, string rt, int nog) {
	Node* current = firstNode;
	for (int i = 0; i < size;i++)
	{
		if(current->item.getGuestName() == gn && current->item.getRoomType() == rt && current->item.getStatus() == "Booked" && current->item.getGuestsNo() == nog)
			return i;
		current = current->next;
	}
	return -1;
}

int List::checkOutSearch(string gn, string rn, int nog) {
	Node* current = firstNode;
	for (int i = 0; i < size;i++)
	{
		if (current->item.getGuestName() == gn && current->item.getRoomNo() == rn && current->item.getStatus() == "Checked In" && current->item.getGuestsNo() == nog)
			return i;
		current = current->next;
	}
	return -1;
}

tm stringToDate(string date) {
	tm result;

	char aString[10];
	strcpy_s(aString, date.c_str());

	sscanf_s(aString, "%d/%d/%4d", &result.tm_mday, &result.tm_mon, &result.tm_year);

	return result;
}

tm stringToDateTime(string dateTime) {
	tm result;

	char aString[20];
	strcpy_s(aString, dateTime.c_str());

	sscanf_s(aString, "%d/%d/%4d  %d:%d:%d", &result.tm_mday, &result.tm_mon, &result.tm_year, &result.tm_hour, &result.tm_min, &result.tm_sec);

	return result;
}
bool List::isRoomFreeOnDate(string date, string roomNo) {
	Node* current = firstNode;
	tm tmChosenDate = stringToDate(date);
	for (int i = 0; i < size;i++)
	{
		tm tmCheckIn = stringToDate(current->item.getCheckIn());
		tm tmCheckOut = stringToDate(current->item.getCheckOut());

		if (tmCheckIn.tm_year < tmChosenDate.tm_year || (tmCheckIn.tm_year == tmChosenDate.tm_year && tmCheckIn.tm_mon < tmChosenDate.tm_mon) || (tmCheckIn.tm_year == tmChosenDate.tm_year && tmCheckIn.tm_mon == tmChosenDate.tm_mon && tmCheckIn.tm_mday <= tmChosenDate.tm_mday)) {
			if (tmCheckOut.tm_year > tmChosenDate.tm_year || (tmCheckOut.tm_year == tmChosenDate.tm_year && tmCheckOut.tm_mon > tmChosenDate.tm_mon) || (tmCheckOut.tm_year == tmChosenDate.tm_year && tmCheckOut.tm_mon == tmChosenDate.tm_mon && tmCheckOut.tm_mday >= tmChosenDate.tm_mday)) {
				if (current->item.getRoomNo() == roomNo) {
					return false;
				}
			}
		}
		current = current->next;
	}
	return true;
}

void List::guestsOnDate(string date) {
	Node* current = firstNode;
	tm tmChosenDate = stringToDate(date);
	for (int i = 0; i < size;i++)
	{
		tm tmCheckIn = stringToDate(current->item.getCheckIn());
		tm tmCheckOut = stringToDate(current->item.getCheckOut());

		if (tmCheckIn.tm_year < tmChosenDate.tm_year || (tmCheckIn.tm_year == tmChosenDate.tm_year && tmCheckIn.tm_mon < tmChosenDate.tm_mon) || (tmCheckIn.tm_year == tmChosenDate.tm_year && tmCheckIn.tm_mon == tmChosenDate.tm_mon && tmCheckIn.tm_mday <= tmChosenDate.tm_mday)) {
			if (tmCheckOut.tm_year > tmChosenDate.tm_year || (tmCheckOut.tm_year == tmChosenDate.tm_year && tmCheckOut.tm_mon > tmChosenDate.tm_mon) || (tmCheckOut.tm_year == tmChosenDate.tm_year && tmCheckOut.tm_mon == tmChosenDate.tm_mon && tmCheckOut.tm_mday >= tmChosenDate.tm_mday)) {
				cout << current->item.getGuestName() << endl;
			}
		}
		current = current->next;
	}
}

int daysInMonth(int month, int year) {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			return 28;
		}
		else {
			return 29;
		}
	}
	else {
		return 31;
	}
}

void List::dateOccupied(int month, int year) {
	Node* current = firstNode;
	bool occupied[20][31];
	for (int i = 0; i < size; i++)
	{
		tm tmCheckIn = stringToDate(current->item.getCheckIn());
		tm tmCheckOut = stringToDate(current->item.getCheckOut());

		int days = daysInMonth(month, year);
		for (int day = 1; day <= days; day++) {
			if (tmCheckIn.tm_year < year || (tmCheckIn.tm_year == year && tmCheckIn.tm_mon < month) || (tmCheckIn.tm_year == year && tmCheckIn.tm_mon == month && tmCheckIn.tm_mday == day)) {
				if (tmCheckOut.tm_year > year || (tmCheckOut.tm_year == year && tmCheckOut.tm_mon > month) || (tmCheckOut.tm_year == year && tmCheckOut.tm_mon == month && tmCheckOut.tm_mday == day)) {
					occupied[stoi(current->item.getRoomNo().substr(current->item.getRoomNo().length() - 2))][day] = true;
				}
			}
		}
		current = current->next;
	}
	for (int r = 1; r <= 20; r++) {
		cout << "Room " << 100 + r << endl;
		for (int d = 1; d <= 31; d++) {
			if (occupied[r][d]) {
				cout << d << " ";
			}
		}
		cout << endl;
	}
}