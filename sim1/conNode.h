//Header file for the configuration node class

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class conNode
{
	friend class configList;

	private:
		string device;
		int cycleTime;
		conNode* next; 

	public:
		conNode();
		conNode(string, int, conNode*);

};
