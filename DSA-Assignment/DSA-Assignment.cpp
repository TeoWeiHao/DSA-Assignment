// DSA-Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include "Booking.h"
using namespace std;

void Menu();
void AddBooking(Booking& bookingList);
void CheckIn(Booking& bookingList);
void InitBookingList(Booking& bookingList);

void InitBookingList()
{
    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("Bookings.csv", ios::in);

    // Get the roll number
    // of which the data is required
    int rollnum, roll2, count = 0;
    cout << "Enter the roll number "
        << "of the student to display details: ";
    cin >> rollnum;

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, temp;

    while (fin >> temp) {

        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word,',')) {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        // convert string to integer for comparision
        roll2 = stoi(row[0]);

        // Compare the roll number
        if (roll2 == rollnum) {

            // Print the found data
            count = 1;
            cout << "Details of Roll " << row[0] << " : \n";
            cout << "Name: " << row[1] << "\n";
            cout << "Maths: " << row[2] << "\n";
            cout << "Physics: " << row[3] << "\n";
            cout << "Chemistry: " << row[4] << "\n";
            cout << "Biology: " << row[5] << "\n";
            break;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}

void AddBooking() 
{
	Booking pList;
	int bookingId;
	string name;
	string bookingDate;
	int numOfGuest;
	string request;
	cout << "Enter Booking Id: ";
	cin >> bookingId;
	cout << "Enter Booking Date: ";
	cin >> bookingId;
	cout << "Enter Name: ";
	cin >> name;
	cout << "Enter number of guests: ";
	cin >> numOfGuest;
	//pList.add(bookingId, name, phoneNo, email);


}

void checkIn()
{

}

int main()
{
	Booking bookingList;
	//InitBookingList(bookingList);
	int option = 0;
	switch (option)
	{
		Menu();
		cin >> option;
	case 1: AddBooking();
		break;
	case 2: checkIn();
		break;
	case 3: ;
		break;
	case 4: ;
		break;
	case 5:;
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
