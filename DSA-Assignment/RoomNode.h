#pragma once
#include "Room.h"

typedef Room ItemType;
typedef std::string KeyType;

struct RoomNode {
	RoomNode() {};

	KeyType  key;   // search key
	ItemType item;	// data item
	RoomNode* next;	// pointer pointing to next item
};