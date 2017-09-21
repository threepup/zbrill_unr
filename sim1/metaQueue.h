//header file for the meta queue

#pragma once

#include <string>
#include <iostream>

using namespace std;

class metaNode;
class metaQueue{

	private:
		metaNode* head;
	public:
		metaQueue();
		~metaQueue();
		void enqueue(char, string, int);
		int dequeue();
		char checkType();
		string checkTask();
		int checkCycles();
		bool isEmpty();
		

};
