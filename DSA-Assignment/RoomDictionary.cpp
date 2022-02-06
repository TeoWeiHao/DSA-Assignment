#include "RoomDictionary.h"

RoomDictionary::RoomDictionary() {
	for (int i = 0; i < MAX_SIZE; i++)
		items[i] = NULL;
	size = 0;
}

int RoomDictionary::hash(std::string key) {

}

void RoomDictionary::add(std::string newKey, Room newRoom) {
	int index = hash(newKey);

	if (items[index] == NULL)
	{
		items[index] = new Node;
		items[index]->key = newKey;
		items[index]->item = newRoom;
		items[index]->next = NULL;
	}
	else
	{
		Node* current = items[index];

		while (current->next != NULL)
		{
			current = current->next;
		}

		Node* newNode = new Node;
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