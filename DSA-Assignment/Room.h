#pragma once
#include <string>

class Room
{
private:
	std::string roomNo;
	std::string roomType;
	int costPerNight;

public:
	Room(std::string rn, std::string rt, int cpn);

	std::string getRoomNo();

	std::string getRoomType();

	int getCostPerNight();
};

