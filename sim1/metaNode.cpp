#include "metaNode.h"

metaNode::metaNode()
{

	task = "";
	cycle = 0;
	next = NULL;

}

metaNode::metaNode(string val, int num, metaNode* ptr)
{

	task = val;
	cycle = num;
	next = ptr;

}
