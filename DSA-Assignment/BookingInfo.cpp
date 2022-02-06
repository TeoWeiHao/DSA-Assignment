#include "BookingInfo.h"
#include <string>

BookingInfo::BookingInfo() {

}

BookingInfo::BookingInfo(int id, std::string bdate, std::string gn, std::string rt, std::string s, std::string ci, std::string co, int g, std::string sp) {
	bookingID = id;
	bookingDate = bdate;
	guestName = gn;
	roomType = rt;
	status = s;
	checkIn = ci;
	checkOut = co;
	guestsNo = g;
	specialRequests = sp;
}

BookingInfo::BookingInfo(int id, std::string bdate, std::string gn, std::string rn, std::string rt, std::string s, std::string ci, std::string co, int g, std::string sp) {
	bookingID = id;
	bookingDate = bdate;
	guestName = gn;
	roomNo = rn;
	roomType = rt;
	status = s;
	checkIn = ci;
	checkOut = co;
	guestsNo = g;
	specialRequests = sp;
}

void BookingInfo::AssignRoomNumber(std::string rn) {
	roomNo = rn;
}

int BookingInfo::getBookingID() {
	return bookingID;
}

std::string BookingInfo::getBookingDate() {
	return bookingDate;
}

std::string BookingInfo::getGuestName() {
	return guestName;
}

std::string BookingInfo::getRoomNo() {
	return roomNo;
}

std::string BookingInfo::getRoomType() {
	return roomType;
}

std::string BookingInfo::getStatus() {
	return status;
}

std::string BookingInfo::getCheckIn() {
	return checkIn;
}

std::string BookingInfo::getCheckOut() {
	return checkOut;
}

int BookingInfo::getGuestsNo() {
	return guestsNo;
}

std::string BookingInfo::getSpecialRequests() {
	return specialRequests;
}