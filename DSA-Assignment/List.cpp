#include <iostream>
using namespace std;

#include "List.h"
#include "time.h"

tm stringToDate(string date) {
	tm result;

	char aString[10];

	for (int i = 0; i < 10; i++) {
		aString[i] = date[i];
	}

	sscanf_s(aString, "%d/%d/%4d", &result.tm_mday, &result.tm_mon, &result.tm_year);

	return result;
}

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

void List::AssignRoomNumber(int index, string rn)
{

	Node* current = firstNode;
	for (int i = 0; i < index;i++)
	{
		current = current->next;
	}
	current->item.AssignRoomNumber(rn);
}

void List::setStatus(int index, string s)
{

	Node* current = firstNode;
	for (int i = 0; i < index;i++)
	{
		current = current->next;
	}
	current->item.setStatus(s);
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

int List::checkInSearch(string gn, string rt, int nog, string date) {
	Node* current = firstNode;
	for (int i = 0; i < size;i++)
	{
		if (current->item.getGuestName() == gn && current->item.getRoomType() == rt && current->item.getStatus() == "Booked" && current->item.getGuestsNo() == nog) {
			tm dtnow = stringToDate(date);
			tm dtcheckin = stringToDate(current->item.getCheckIn());
			if(dtnow.tm_year == dtcheckin.tm_year && dtnow.tm_mon == dtcheckin.tm_mon && dtnow.tm_mday == dtcheckin.tm_mday)
				return i;
		}
		current = current->next;
	}
	return -1;
}

int List::checkOutSearch(string gn, string rn, int nog, string date) {
	Node* current = firstNode;
	for (int i = 0; i < size;i++)
	{
		if (current->item.getGuestName() == gn && current->item.getRoomNo() == rn && current->item.getStatus() == "Checked In" && current->item.getGuestsNo() == nog) {
			tm dtnow = stringToDate(date);
			tm dtcheckout = stringToDate(current->item.getCheckOut());
			if (dtnow.tm_year == dtcheckout.tm_year && dtnow.tm_mon == dtcheckout.tm_mon && dtnow.tm_mday == dtcheckout.tm_mday)
				return i;
		}
		current = current->next;
	}
	return -1;
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
	bool occupied[21][32];
	for (int r = 1; r <= 20; r++) {
		for (int d = 1; d <= 31; d++) {
			occupied[r][d] = false;
		}
	}
	int days = daysInMonth(month, year);
	for (int day = 1; day <= days; day++) {
		Node* current = firstNode;
		for (int i = 0; i < size; i++)
		{

			tm tmCheckIn = stringToDate(current->item.getCheckIn());
			tm tmCheckOut = stringToDate(current->item.getCheckOut());


			if (tmCheckIn.tm_year < year || (tmCheckIn.tm_year == year && tmCheckIn.tm_mon < month) || (tmCheckIn.tm_year == year && tmCheckIn.tm_mon == month && tmCheckIn.tm_mday <= day)) {
				if (tmCheckOut.tm_year > year || (tmCheckOut.tm_year == year && tmCheckOut.tm_mon > month) || (tmCheckOut.tm_year == year && tmCheckOut.tm_mon == month && tmCheckOut.tm_mday >= day)) {
					occupied[stoi(current->item.getRoomNo().substr(current->item.getRoomNo().length() - 2))][day] = true;
				}
			}
			current = current->next;
		}
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