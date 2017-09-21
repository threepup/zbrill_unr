//implementation for the meta node class

#include "metaNode.h"

metaNode::metaNode()
{
	type = '\0';
	task = "";
	cycles = 0;
	next = NULL;

}

metaNode::metaNode(char n, string val, int num, metaNode* ptr)
{
	type = n;
	task = val;
	cycles = num;
	next = ptr;

}
