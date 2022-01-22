#pragma once
#include <string>
using namespace std;

class Guest
{
    private:
        int bookingId;
        string name;
        string bookingDate;
        int roomNum;
        string roomType;
        string status;
        string checkIn;
        string checkOut;
        int numOfGuest;
        string request;
    public:
        Guest();
        Guest(int, string, string, int, string, string, string, string, int, string);
        void setId(int);
        int getId();
        void setBookingDate(string);
        string getBookingDate();
        void setName(string);
        string getName();
        void setRoomNum(int);
        int getRoomNum();
        void setRoomType(string);
        string getRoomType();
        void setStatus(string);
        string getStatus();
        void setCheckIn(string);
        string getCheckIn();
        void setCheckOut(string);
        string getCheckOut();
        void setNumOfGuest(int);
        int getNumOfGuest();
        void setRequest(string);
        string getRequest();
};

