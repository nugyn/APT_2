#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{

public:
	LinkedList();
	~LinkedList();

	void insertFront(Tile* tile);	
	void insertBack(Tile* tile);
	void insertPosition(int pos, Tile* tile);

	void deleteFront();
	void deleteBack();
	void deleteNode(Tile * tile);
	void deletePosition(int pos);

	Tile* getTile(Tile* tile);
	Tile* getTile(int pos);

	void clear();
	int size();
	void display();



private:
	Node* head;
	Node* tail;
};

#endif // LINKEDLIST_H