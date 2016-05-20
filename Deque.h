/*
* Deque.h
*
*  Created on: Oct 4, 2015
*      Author: Will
*/

#ifndef DEQUE_H_
#define DEQUE_H_

#include <iostream>

using std::cout;
using std::endl;

//Each node in singly linked list
class Node
{
public:
	int data;
	Node* next;

	Node() //No argument constructor
	{
		next = NULL;
	}
	Node(const int element) //Constructor
	{
		data = element;
		next = NULL;
	}
};

class Deque
{
public:
	Deque(); //Default constructor
	Deque(const Deque&); //Copy constructor
	~Deque(); //Destructor
	Deque& operator=(const Deque&); //Overloaded assignment operator
	void insert_front(int); //Insert parameter at front of deque
	void insert_back(int); //Insert parameter at back of deque
	int remove_front(); //Remove and return parameter from front of deque
	int remove_back(); //Remove and return parameter from back of deque
	int peek_front() const; //Look at and return parameter at front of deque
	int peek_back() const; //Look at and return parameter at back of deque
	bool empty() const; //Check for empty deque, return true if deque is empty
	int size() const; //Return number of elements stored in deque
	void test_print() const; //Print linked list
	bool check_empty() const;

private:
	Node* front;
	Node* back;
	int count;
	void Delete();
};

#endif /* DEQUE_H_ */
