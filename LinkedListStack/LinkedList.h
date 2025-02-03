#pragma once

class LinkedList
{
private:
	struct Node
	{
		Node(int value);
		int value;
		Node* next;
	};

public:
	LinkedList();
	LinkedList(const LinkedList& resource);
	~LinkedList();
	LinkedList& operator=(const LinkedList& resource);
	int Size() const;
	bool Empty() const;
	void Insert(int value);
	int RemoveLast();

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;
};