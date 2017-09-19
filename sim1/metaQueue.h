#pragma once

#include <string>
#include <iostream>

using namespace std;

class metaNode;
class metaQueue{

	private:
		metaNode head;
	public:
		metaQueue();
		~metaQueue();
		void enqueue(string, int, metaNode*);
		int dequeue();
		

};
