#pragma once
#include "Room.h"
#include <string>

const int MAX_SIZE = 4;

struct Node
{
	std::string key;
	Room item;
	Node* next;
};
class RoomDictionary
{
private:
	Node* items[MAX_SIZE];
	int size;

public:
	RoomDictionary();

	int hash(std::string key);

	void add(std::string newKey, Room newRoom);

	int getLength();

};