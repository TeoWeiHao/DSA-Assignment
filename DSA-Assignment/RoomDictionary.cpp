#include "RoomDictionary.h"
#include "RoomNode.h"

RoomDictionary::RoomDictionary() {
	for (int i = 0; i < MAX_SIZE; i++)
		items[i] = NULL;
	size = 0;
}

RoomDictionary::~RoomDictionary() {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (items[i] != NULL) {
			RoomNode* current = items[i];
			RoomNode* previous = current;
			while (current != NULL) {
				previous = current;
				current = current->next;
				previous->next = NULL;
				delete previous;
			}
		}
	}
}

int charvalue(char c)
{
	if (isalpha(c))
	{
		if (isupper(c))
			return (int)c - (int)'A';
		else
			return (int)c - (int)'a' + 26;
	}
	else
		return -1;
}

int RoomDictionary::hash(KeyType key) {
	int total = charvalue(key[0]);

	for (int i = 0; i < 3; i++) {
		if (charvalue(key[i]) == -1) {
			continue;
		}

		total = total * 52 + charvalue(key[i]);
		total = total %= MAX_SIZE;
	}
	return total;
}

void RoomDictionary::add(KeyType newKey, ItemType newRoom) {
	int index = hash(newKey);

	if (items[index] == NULL)
	{
		items[index] = new RoomNode;
		items[index]->key = newKey;
		items[index]->item = newRoom;
		items[index]->next = NULL;
	}
	else
	{
		RoomNode* current = items[index];

		while (current->next != NULL)
		{
			current = current->next;
		}

		RoomNode* newNode = new RoomNode;
		newNode->key = newKey;
		newNode->item = newRoom;
		newNode->next = NULL;
		current->next = newNode;
	}
	size++;
}

int RoomDictionary::getLength() {
	return size;
}