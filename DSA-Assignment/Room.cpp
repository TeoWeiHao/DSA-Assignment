#include "Room.h"

Room::Room() {}
Room::Room(int r, string t, int c) : roomNum(r), roomType(t), cost(c) {}

void Room::setRoomNum(int r) { roomNum = r; }
int Room::getRoomNum() { return roomNum; }
void Room::setRoomType(string t) { roomType = t; }
string Room::getRoomType() { return roomType; }
void Room::setCost(int c) { cost = c; }
int Room::getCost() { return cost; }