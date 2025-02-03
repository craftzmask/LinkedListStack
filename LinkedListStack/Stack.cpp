#include "Stack.h"

void Stack::Push(int val)
{
	ll.Insert(val);
}

int Stack::Pop()
{
	return ll.RemoveLast();
}

int Stack::Size() const
{
	return ll.Size();
}

bool Stack::Empty() const
{
	return ll.Empty();
}
