#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "conNode.h"

using namespace std;

class conNode;
class configList
{
	private:
		conNode* root;
		conNode* cursor;
	public:
		configList();
		~configList();
		void addNode(string, int, conNode*);
		void traverseList();	
		string getDevice();
		int getTime();
		void setDevice(string);
		void setTime(int);

};
