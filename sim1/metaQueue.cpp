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

void metaQueue::enqueue(string val, int num){

	metaNode* temp;
	temp = new metaNode(val, num, NULL);
	metaNode* cursor;

	if(head == NULL){
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

int metaQueue:dequeue(){
	metaNode* temp;
	int num;

	temp = head;
	head = head->next;
	num = temp->cycles;
	delete temp;

	return num;

}
