#pragma once
#include "Room.h"
#include <string>
#include "RoomNode.h"

const int MAX_SIZE = 4;

class RoomDictionary
{
private:

	RoomNode* items[MAX_SIZE];
	int size;

public:
	RoomDictionary();

	~RoomDictionary();

	int hash(KeyType key);

	void add(KeyType newKey, ItemType newRoom);

	int getLength();

};