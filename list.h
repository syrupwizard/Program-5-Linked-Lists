#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const int NAME = 50;
const int DESC = 250;
const int LOC = 50;

struct event
{
	char name[NAME];
	char * description;
	char loc[LOC]; //location
	int time; //hhmm
	int date; //mmddyy
	double cost;
};

struct node
{
	event data;
	node *next;
};

void addEvent(event &events);
void timeDateCost(event &events);
void displayEvent(const event &events);
void insert(event &an_event, node *&head);
void displayList(node *&head);
void runMenu(event &an_event,node *&head);
void deleteList(node*&head);
