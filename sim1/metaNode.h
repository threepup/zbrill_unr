//Header file for the meta node class

#pragma once

#include <string>
#include <iostream>

using namespace std;

class metaNode
{
	friend class metaQueue;	

	private:
		char type;
		string task;
		int cycles;
		metaNode* next;
	public:
		metaNode();
		metaNode(char, string, int, metaNode*);

};
