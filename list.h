//This file contains two structs
//one struct creates the nodes for the linear linked list,
//the other struct contains the information for an event.
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const int NAME = 50;
const int DESC = 250;
const int LOC = 50;
//struct which contains data regarding an event
struct event
{
	char name[NAME];
	char * description;//dynamic memory, must delete;
	char loc[LOC]; //location
	int time; //hhmm
	int date; //mmddyy
	double cost;
};
//struct which creates a node
struct node
{
	event data;
	node *next;
};
void welcome();
void addEvent(event &events);
void timeDateCost(event &events);
void displayEvent(const event &events);
void insert(event &an_event, node *&head);
void displayList(node *&head);
void runMenu(event &an_event,node *&head);
void deleteList(node*&head);
