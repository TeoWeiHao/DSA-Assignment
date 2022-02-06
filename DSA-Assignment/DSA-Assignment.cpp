// DSA-Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "BookingInfo.h"
#include "BST.h"
#include <vector>
#include "Room.h"
#include "RoomDictionary.h"
using namespace std;

void Menu();
void readRoomsFile();

RoomDictionary roomDict = RoomDictionary();

int main()
{
	int menuOption;
	BST bst;
	ItemType target;

	readRoomsFile();

	while (true) {
        Menu();
        cin >> menuOption;

        if (menuOption == 1) {
			string newGuestName;
			cout << endl;
			cout << "Enter Guest Name : ";
			cin >> newGuestName;
			BookingInfo newBooking = BookingInfo(101, "", "", "", "", "", "", 1, "");
			bst.insert(101);
        }
        else if (menuOption == 2) {
			cout << "Enter a booking ID to search : ";
			cin >> target;
			BinaryNode* p = bst.search(target);
			if (p != NULL)
				cout << "Booking not found" << endl;
			else
				//newBooking.AssignRoomNumber()
				cout << "";
        }
        else if (menuOption == 3) {
            
        }
        else if (menuOption == 4) {
            
        }
		else if (menuOption == 5) {

		}
        else if (menuOption == 0) {
            cout << "Bye!\n";
        }
        else {
            cout << "Invalid input, please try again!" << endl;
        }
    }
}

void Menu()
{

	cout << "----------------Main Menu------------------\n";
	cout << "[1] Add Booking\n";
	cout << "[2] Check In\n";
	cout << "[3] Check Out\n";
	cout << "[4] Display guest on a particular date\n";
	cout << "[5] Display rooms occupied on a month\n";
	cout << "[0] Exit\n";
	cout << "----------------------------------------------\n";
	cout << "Enter your option : ";
}

void readRoomsFile() {
	string line;
	vector<string> row;

	fstream fin;
	fin.open("Rooms.csv", ios::in);
	getline(fin, line);
	cout << line << endl;
	while ( getline(fin, line) ) {
		row.clear();

		string s = line;
		string delimiter = ",";

		size_t pos = 0;
		string token;
		while ((pos = s.find(delimiter)) != string::npos) {
			token = s.substr(0, pos);
			row.push_back(token);
			s.erase(0, pos + delimiter.length());
		}
		row.push_back(s);

		Room newRoom = Room(row[0], row[1], stoi(row[2]));
		roomDict.add(row[1], newRoom);
	}
	fin.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
