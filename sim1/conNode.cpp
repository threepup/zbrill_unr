//implementation file for conNode.h

#include conNode.h
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

conNode:conNode()
{
}

conNode:conNode(string d, int i, conNode* n)
{
	device = d;
	cycleTime = i;
	next = n;
}
