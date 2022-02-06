#pragma once
#include <string>

class BookingInfo
{
private:
	int bookingID;
	std::string bookingDate;
	std::string guestName;
	std::string roomNo;
	std::string roomType;
	std::string status;
	std::string checkIn;
	std::string checkOut;
	int guestsNo;
	std::string specialRequests;

public:
	BookingInfo();

	BookingInfo(int id, std::string bdate, std::string gn, std::string rt, std::string s, std::string ci, std::string co, int g, std::string sp);

	BookingInfo(int id, std::string bdate, std::string gn, std::string rn, std::string rt, std::string s, std::string ci, std::string co, int g, std::string sp);

	void AssignRoomNumber(std::string rn);

	void setStatus(std::string s);

	int getBookingID();

	std::string getBookingDate();

	std::string getGuestName();

	std::string getRoomNo();

	std::string getRoomType();

	std::string getStatus();

	std::string getCheckIn();

	std::string getCheckOut();

	int getGuestsNo();

	std::string getSpecialRequests();

	std::string print();
};

