#pragma once
#include "Room.h"
#include <string>
#include "RoomNode.h"
#include "List.h"

const int HASH_TABLE_SIZE = 4;

class RoomDictionary
{
private:

	RoomNode* items[HASH_TABLE_SIZE];
	int size;

public:
	RoomDictionary();

	~RoomDictionary();

	int hash(std::string key);

	void add(std::string newKey, Room newRoom);

	int getLength();

	void printDictionary();

	std::string getAvaliableRoom(std::string roomType, std::string date, List blist);

};