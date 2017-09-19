#include "configList.h"
#include "conNode.h"

configList::configList()
{
	head = NULL;
	cursor = NULL;
}

configList::~configList()
{

	conNode* temp;

	while(head->next != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}

	delete head;

}

void configList::addNode(string val, int num, conNode* ptr)
{

	conNode* temp;
	temp = new conNode(val, num, ptr);
	
	if(cursor->next == NULL)
		cursor->next = temp;
	else
	{
		temp->next = cursor->next;
		cursor->next = temp;
	}

}

void configList::traverseList()
{

	if(cursor->next == NULL)
		cursor = head;
	else
		cursor = cursor->next;

}

string configList::getDevice()
{

	return cursor->device;

}

int configList::getTime()
{

	return cursor->cycleTime;

}

void configList::setDevice(string val)
{

	cursor->device = val;

}

void configList::setTime(int num)
{

	cursor->cycleTime = num;

}


