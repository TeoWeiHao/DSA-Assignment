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

	int hash(std::string key);

	void add(std::string newKey, Room newRoom);

	int getLength();

	void printDictionary();

};