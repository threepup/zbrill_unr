#pragma once

#include <string>
#include <iostream>

using namespace std;

class metaNode
{
	friend class metaQueue;	

	private:
		string task;
		int cycles;
		metaNode* next;
	public:
		metaNode();
		metaNode(string, int, metaNode*);

};
