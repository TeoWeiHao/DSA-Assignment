// DSA-Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "BookingInfo.h"
#include "List.h"
#include "Room.h"
#include "RoomDictionary.h"
#include <time.h>
using namespace std;

void Menu();
void readRoomsFile();
void readBookingsFile();

List bookingsList;
RoomDictionary roomDict = RoomDictionary();

int main()
{
	readBookingsFile();
	readRoomsFile();

	string dateTime = "1/4/2021";

	int menuOption;
	while (true) {
		Menu();
        cin >> menuOption;

        if (menuOption == 1) {
			string newGuestName, newRoomType, checkInDate, checkOutDate, specialRequests;
			int noOfGuests;
			cout << endl;
			cout << "Enter Guest Name : ";
			cin >> newGuestName;
			cout << "Enter Room Type (Standard City View | Deluxe City View | Executive Sea View | President Suite) : ";
			cin >> newRoomType;
			cout << "Enter Check In Date : ";
			cin >> checkInDate;
			cout << "Enter Check Out Date : ";
			cin >> checkOutDate;
			cout << "Enter Number of Guests : ";
			cin >> noOfGuests;
			cout << "Enter Special Requests : ";
			cin >> specialRequests;

			BookingInfo newBooking = BookingInfo(bookingsList.getLength()+1, "", newGuestName, newRoomType, "Booked", checkInDate, checkOutDate, noOfGuests, specialRequests);
			bookingsList.add(newBooking);
        }
        else if (menuOption == 2) {
			string searchGuestName, searchRoomType;
			int noOfGuests;
			cout << endl;
			cout << "Enter Guest Name : ";
			cin >> searchGuestName;
			cout << "Enter Room Type (Standard City View | Deluxe City View | Executive Sea View | President Suite) : ";
			cin >> searchRoomType;
			cout << "Enter Number of Guests : ";
			cin >> noOfGuests;

			// setStatus
			// assignRoom
        }
        else if (menuOption == 3) {
			string searchGuestName, searchRoomType;
			int noOfGuests;
			cout << endl;
			cout << "Enter Guest Name : ";
			cin >> searchGuestName;
			cout << "Enter Room Type (Standard City View | Deluxe City View | Executive Sea View | President Suite) : ";
			cin >> searchRoomType;
			cout << "Enter Number of Guests : ";
			cin >> noOfGuests;
			// setStatus
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

void readBookingsFile() {
	string line;
	vector<string> row;

	fstream fin;
	fin.open("Bookings.csv", ios::in);
	getline(fin, line);
	while (getline(fin, line)) {
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

		BookingInfo newBooking = BookingInfo(stoi(row[0]), row[1], row[2], row[3], row[4], row[5], row[6], row[7], stoi(row[8]), row[9]);
		bookingsList.add(newBooking);

	}
	fin.close();
}

tm stringToDate(string date) {
	tm result;

	char aString[10];
	strcpy(aString, date.c_str());

	sscanf(aString, "%d/%d/%4d", &result.tm_mday, &result.tm_mon, &result.tm_year);

	return result;
}

tm stringToDateTime(string dateTime) {
	tm result;

	char aString[20];
	strcpy(aString, dateTime.c_str());

	sscanf(aString, "%d/%d/%4d  %d:%d:%d", &result.tm_mday, &result.tm_mon, &result.tm_year, &result.tm_hour, &result.tm_min, &result.tm_sec);

	return result;
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
