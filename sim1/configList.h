//header file for the configuration list

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class conNode;
class configList
{
	private:
		conNode* head;
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
