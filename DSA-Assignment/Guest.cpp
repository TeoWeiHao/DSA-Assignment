#include "Guest.h"

Guest::Guest() {}
Guest::Guest(int Id, string d, string n, int rNum, string rType, string s, string cIn, string cOut, int gNum, string r) : bookingId(Id), bookingDate(d), name(n), roomNum(rNum), roomType(rType) , status(s), checkIn(cIn), checkOut(cOut), numOfGuest(gNum), request(r) {}

void Guest::setId(int Id) { bookingId = Id; }
int Guest::getId() { return bookingId; }
void Guest::setBookingDate(string d) { bookingDate = d; }
string Guest::getBookingDate() { return bookingDate; }
void Guest::setName(string n) { name = n; }
string Guest::getName() { return name; }
void Guest::setRoomNum(int rNum) { roomNum = rNum; }
int Guest::getRoomNum() { return roomNum; }
void Guest::setRoomType(string rType) { roomType = rType; }
string Guest::getRoomType() { return roomType; }
void Guest::setStatus(string s) { status = s; }
string Guest::getStatus() { return status; }
void Guest::setCheckIn(string cIn){ checkIn = cIn; }
string Guest::getCheckIn() { return checkIn; }
void Guest::setCheckOut(string cOut) { checkOut = cOut; }
string Guest::getCheckOut() { return checkOut; }
void Guest::setNumOfGuest(int gNum) { numOfGuest = gNum; }
int Guest::getNumOfGuest() { return numOfGuest; }
void Guest::setRequest(string r) { request = r; }
string Guest::getRequest() { return request; }