//implentation for the meta queue

#include "metaQueue.h"
#include "metaNode.h"

metaQueue::metaQueue()
{

	head = NULL;

}

metaQueue::~metaQueue()
{
	metaNode* temp;

	if(head != NULL){
	
		while(head->next != NULL){
		
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	delete head;
}

void metaQueue::enqueue(char n, string val, int num){

	metaNode* temp;
	temp = new metaNode(n, val, num, NULL);
	metaNode* cursor;

	if(head == NULL)
		head = temp;

	else{
		if(head->next == NULL)
			head->next = temp;
		else{
			cursor = head;
			while(cursor->next != NULL)
				cursor = cursor->next;
			cursor->next = temp;
		}
		
	}

	temp = NULL;

}

int metaQueue::dequeue(){
	metaNode* temp;
	int num;

	if(head == NULL)
		return -1;

	temp = head;
	head = head->next;
	num = temp->cycles;
	delete temp;

	return num;

}

char metaQueue::checkType()
{
	return head->type;
}

string metaQueue::checkTask()
{
	return head->task;
}

int metaQueue::checkCycles()
{
	return head->cycles;
}

bool metaQueue::isEmpty()
{
	if(head == NULL)
		return true;
	else
		return false;
}

