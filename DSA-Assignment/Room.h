#pragma once
#include <string>
using namespace std;

class Room
{
	private:
		int roomNum;
		string roomType;
		int cost;
	public:
		Room();
		Room(int, string, int);
		void setRoomNum(int);
		int getRoomNum();
		void setRoomType(string);
		string getRoomType();
		void setCost(int);
		int getCost();
};

