/*
* Deque.cpp
*
*  Created on: Oct 4, 2015
*      Author: Will
*/
#include <iostream>
#include <stdexcept>
#include "Deque.h"

using std::cout;
using std::endl;

Deque::Deque()
{
	front = NULL;
	back = NULL;
	count = 0;
}
Deque::Deque(const Deque &copy) : front{ NULL }, back{ NULL }, count{ 0 }
{
	*this = copy;
}
Deque::~Deque()
{
	Delete();
}
Deque& Deque::operator=(const Deque &obj)
{
	if (&obj != this) //Avoid self assignement
	{
		//Free current memory held by this
		if (!empty())
			this->Delete();

		//Create copy of obj
		Node* node = obj.front;
		front = node;
		while (node != NULL)
		{
			insert_back(node->data);
			node = node->next;
		}
	}
	return *this;
}
void Deque::insert_front(int element)
{
	Node* node = new Node(element);

	if (empty())
	{
		front = node;
		back = node;
	}
	else
	{
		//Add node to front of deque and fix link
		node->next = front;
		front = node;
	}
	count++;
}
int Deque::remove_front()
{
	if (!check_empty()) {
		int value = front->data;

		Node* tmp;
		//Delete front node from deque and fix link
		if (front->next != NULL) {
			tmp = front;
			front = front->next;
			delete tmp;
		}	
		else {
			delete front;
		}
		count--;
		return value;
	}
}
void Deque::insert_back(int element)
{
	Node* node = new Node(element);

	if (empty())
	{
		front = node;
		back = node;
	}
	else
	{
		//Add node to back of deque and fix link
		back->next = node;
		back = back->next;
	}
	count++;
}
int Deque::remove_back()
{
	if (!check_empty()) {
		int value = back->data;

		//Delete back node from deque and fix link
		Node* node = front;
		Node* tmp = NULL;
		int tmpcount = 1;
		if (node->next == NULL)
		{
			delete front;
		}
		else
		{
			while (tmpcount != count - 1)
			{
				node = node->next;
				tmpcount++;
			}
			back = node;
			tmp = back->next;
			back->next = NULL;
			delete tmp;
		}
		count--;
		return value;
	}
}
int Deque::peek_front() const
{
	if (!check_empty())
		return front->data;
}
int Deque::peek_back() const
{
	if (!check_empty())
		return back->data;
}
bool Deque::empty() const
{
	return count == 0 ? true : false;
}
int Deque::size() const
{
	return count;
}
void Deque::Delete()
{
	Node* tmp;
	while (front != NULL)
	{
		tmp = front->next;
		delete front;
		front = tmp;
	}
	count = 0;
}
void Deque::test_print() const
{
	Node* node = front;
	if (empty())
		cout << "Deque is empty.";
	else
	{
		while (node != NULL)
		{
			cout << node->data << " ";
			node = node->next;
		}
	}
	cout << endl;
}
bool Deque::check_empty() const
{
	try
	{
		if (empty())
			throw std::runtime_error("Deque is empty.");
		else
			return false;
			
	}
	catch (std::runtime_error &e)
	{
		cout << "Caught a runtime_error exception: " << e.what() << endl;
		return true;
	}
}