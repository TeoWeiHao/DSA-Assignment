#include "Room.h"

Room::Room() {

}

Room::Room(std::string rn, std::string rt, int cpn) {
	roomNo = rn;
	roomType = rt;
	costPerNight = cpn;
}

std::string Room::getRoomNo() {
	return roomNo;
}

std::string Room::getRoomType() {
	return roomType;
}

int Room::getCostPerNight() {
	return costPerNight;
}