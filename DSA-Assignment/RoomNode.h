#pragma once
#include "Room.h"


struct RoomNode {
	RoomNode() {};

	std::string  key;   // search key
	Room item;	// data item
	RoomNode* next;	// pointer pointing to next item
};