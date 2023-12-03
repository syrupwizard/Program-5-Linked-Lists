//Program 5 by Austin Huerta for CS162
//This program takes input about events from the user, and stores each event as a node of a linear linked list.
//The event is inserted at the end of the list for each new event added. 
//This file contains the implementation of several core functions
#include "list.h"

int main()
{
	node *head = nullptr;
	event an_event;
	welcome();	
	runMenu(an_event, head);
	deleteList(head);
	return 0;
}
