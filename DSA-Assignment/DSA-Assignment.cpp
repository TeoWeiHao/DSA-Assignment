// DSA-Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BookingInfo.h"
using namespace std;

void Menu();

int main()
{
	int option = 1;
	BookingInfo newBooking;
	string newGuestName, newRoomType;
	switch (option)
	{
		Menu();
		cin >> option;
	case 1:
		cout << endl;
		cout << "Enter Guest Name : ";
		cin >> newGuestName;
		newBooking = BookingInfo(101, "", "", "", "", "", "", 1,"");
		break;
	case 2: ;
		break;
	case 3: ;
		break;
	case 4: ;
		break;
	case 5: ;
		break;
	case 0:
		cout << "Bye!\n";

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
