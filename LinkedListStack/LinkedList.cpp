#include "LinkedList.h"
#include <assert.h>

LinkedList::LinkedList()
    :
    head(new Node(-1)),
    tail(head)
{
}

LinkedList::LinkedList(const LinkedList& resource)
    :
    LinkedList()
{
    *this = resource;
}

LinkedList::~LinkedList()
{
    while (head != tail)
    {
        RemoveLast();
    }
    delete head;
    head = nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& resource)
{
    if (this == &resource)
    {
        return *this;
    }

    while (!Empty())
    {
        RemoveLast();
    }

    delete head;
    head = nullptr;

    head = new Node(-1);
    tail = head;

    Node* p = resource.head->next;
    while (p != nullptr)
    {
        Insert(p->value);
        p = p->next;
    }

    return *this;
}

int LinkedList::Size() const
{
    return size;
}

bool LinkedList::Empty() const
{
    return Size() == 0;
}

void LinkedList::Insert(int value)
{
    assert(head != nullptr && tail != nullptr);
    tail->next = new Node(value);
    tail = tail->next;
    size++;
}

int LinkedList::RemoveLast()
{
    if (Size() > 0)
    {
        const int value = tail->value;

        Node* p = head;
        while (p->next != tail)
        {
            p = p->next;
        }

        delete p->next;
        p->next = nullptr;
        tail = p;
        size--;

        return value;
    }

    return -1;
}

LinkedList::Node::Node(int value)
    :
    value(value),
    next(nullptr)
{

}
