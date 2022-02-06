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
			cout << "Enter Room Type ( [SCV] Standard City View | [DCV] Deluxe City View | [ESV] Executive Sea View | [PS] President Suite) : ";
			cin >> newRoomType;
			if (newRoomType == "SCV")
				newRoomType = "Standard City View";
			if (newRoomType == "DCV")
				newRoomType = "Deluxe City View";
			if (newRoomType == "ESV")
				newRoomType = "Executive Sea View";
			if (newRoomType == "PS")
				newRoomType = "President Suite";
			cout << "Enter Check In Date : ";
			cin >> checkInDate;
			cout << "Enter Check Out Date : ";
			cin >> checkOutDate;
			cout << "Enter Number of Guests : ";
			cin >> noOfGuests;
			cout << "Enter Special Requests : ";
			cin >> specialRequests;

			BookingInfo newBooking = BookingInfo(bookingsList.getLength()+1, dateTime, newGuestName, newRoomType, "Booked", checkInDate, checkOutDate, noOfGuests, specialRequests);
			bookingsList.add(newBooking);

			cout << endl;
			cout << "Booking is successful" << endl;
			cout << "Booking ID:" << newBooking.getBookingID() << endl;
			cout << "Booking Date:" << newBooking.getBookingDate() << endl;
			cout << "Guest Name:" << newBooking.getGuestName() << endl;
			cout << "Room Type:" << newBooking.getRoomType() << endl;
			cout << "Status:" << newBooking.getStatus() << endl;
			cout << "Check In Date:" << newBooking.getCheckIn() << endl;
			cout << "Check Out Date:" << newBooking.getCheckOut() << endl;
			cout << "No. of Guests:" << newBooking.getGuestsNo() << endl;
			cout << "Special Requests:" << newBooking.getSpecialRequests() << endl;
			cout << endl;
        }
        else if (menuOption == 2) {
			string searchGuestName, searchRoomType, checkInDate, roomType, roomNo;
			int noOfGuests, index, hash;
			cout << endl;
			cout << "Enter Guest Name : ";
			cin >> searchGuestName;
			cout << "Enter Room Type ( [SCV] Standard City View | [DCV] Deluxe City View | [ESV] Executive Sea View | [PS] President Suite) : ";
			cin >> searchRoomType;
			if (searchRoomType == "SCV")
				searchRoomType = "Standard City View";
			if (searchRoomType == "DCV")
				searchRoomType = "Deluxe City View";
			if (searchRoomType == "ESV")
				searchRoomType = "Executive Sea View";
			if (searchRoomType == "PS")
				searchRoomType = "President Suite";
			cout << "Enter Number of Guests : ";
			cin >> noOfGuests;

			index = bookingsList.checkInSearch(searchGuestName, searchRoomType, noOfGuests);
			checkInDate = bookingsList.get(index).getCheckIn();
			roomType = bookingsList.get(index).getRoomType();

			roomNo = roomDict.getAvaliableRoom(roomType, checkInDate, bookingsList);

			bookingsList.AssignRoomNumber(index, roomNo);
			bookingsList.setStatus(index, "Checked In");

			cout << endl;
			cout << "Check in is successful" << endl;
			cout << "Booking ID:" << bookingsList.get(index).getBookingID() << endl;
			cout << "Booking Date:" << bookingsList.get(index).getBookingDate() << endl;
			cout << "Guest Name:" << bookingsList.get(index).getGuestName() << endl;
			cout << "Room No.:" << bookingsList.get(index).getRoomNo() << endl;
			cout << "Room Type:" << bookingsList.get(index).getRoomType() << endl;
			cout << "Status:" << bookingsList.get(index).getStatus() << endl;
			cout << "Check In Date:" << bookingsList.get(index).getCheckIn() << endl;
			cout << "Check Out Date:" << bookingsList.get(index).getCheckOut() << endl;
			cout << "No. of Guests:" << bookingsList.get(index).getGuestsNo() << endl;
			cout << "Special Requests:" << bookingsList.get(index).getSpecialRequests() << endl;
			cout << endl;
        }
        else if (menuOption == 3) {
			string searchGuestName, searchRoomNo;
			int noOfGuests, index;
			cout << endl;
			cout << "Enter Guest Name : ";
			cin >> searchGuestName;
			cout << "Enter Room No. : ";
			cin >> searchRoomNo;
			cout << "Enter Number of Guests : ";
			cin >> noOfGuests;
			
			index = bookingsList.checkOutSearch(searchGuestName, searchRoomNo, noOfGuests);
			bookingsList.setStatus(index, "Checked Out");

			cout << endl;
			cout << "Check out is successful" << endl;
			cout << "Booking ID:" << bookingsList.get(index).getBookingID() << endl;
			cout << "Booking Date:" << bookingsList.get(index).getBookingDate() << endl;
			cout << "Guest Name:" << bookingsList.get(index).getGuestName() << endl;
			cout << "Room No.:" << bookingsList.get(index).getRoomNo() << endl;
			cout << "Room Type:" << bookingsList.get(index).getRoomType() << endl;
			cout << "Status:" << bookingsList.get(index).getStatus() << endl;
			cout << "Check In Date:" << bookingsList.get(index).getCheckIn() << endl;
			cout << "Check Out Date:" << bookingsList.get(index).getCheckOut() << endl;
			cout << "No. of Guests:" << bookingsList.get(index).getGuestsNo() << endl;
			cout << "Special Requests:" << bookingsList.get(index).getSpecialRequests() << endl;
			cout << endl;
        }
        else if (menuOption == 4) {
			string dateChosen;
			cout << endl;
			cout << "Date : ";
			cin >> dateChosen;
			bookingsList.guestsOnDate(dateChosen);
        }
		else if (menuOption == 5) {
			int monthChosen, yearChosen;
			cout << endl;
			cout << "Month : ";
			cin >> monthChosen;
			cout << "Year : ";
			cin >> yearChosen;
			bookingsList.dateOccupied(monthChosen, yearChosen);
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
