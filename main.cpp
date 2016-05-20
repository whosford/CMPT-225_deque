/*
* main.cpp
*
*  Created on: Oct 4, 2015
*      Author: Will
*/
#include <iostream>
#include "Deque.h"

using std::cout;
using std::endl;

int main()
{
	Deque dq1;
	dq1.remove_back();
	cout << dq1.empty() << " - 1" << endl;

	dq1.insert_front(42);
	dq1.insert_back(216);
	dq1.insert_back(105);

	dq1.test_print();

	cout << dq1.peek_front() << " - 42" << endl;
	cout << dq1.peek_back() << " - 105" << endl;
	cout << dq1.size() << " - 3" << endl;

	dq1.test_print();

	Deque dq2;
	dq2 = dq1;
	dq2.test_print();


	Deque dq3(dq1);
	dq3.test_print();
	dq1.insert_back(387);
	dq1.test_print();
	dq3.test_print();

	cout << dq1.remove_front() << " - 42" << endl;
	dq1.test_print();
	cout << dq1.remove_back() << " - 387" << endl;
	dq1.test_print();

	cout << dq2.peek_front() << " - 42" << endl;
	cout << dq2.peek_back() << " - 105" << endl;

	cout << dq3.peek_front() << " - 42" << endl;
	cout << dq3.peek_back() << " - 105" << endl;

	cout << dq3.remove_front() << " - 42" << endl;
	dq3.test_print();
	cout << dq3.remove_back() << " - 105" << endl;
	dq3.test_print();

	return 0;
}