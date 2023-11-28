#include "list.h"
// LLL functions
void insert(event &an_event, node *&head)
{
	if(!head) //special case empty list
	{
		head = new node;
		head->data = an_event;
		head->next = nullptr;
		return;
	}
	node *temp = new node; 
	temp->data = an_event;
	temp->next = head;
	head = temp;
}
void displayList(node *&head)
{
	node *current = head;
	while(current)
	{
		cout << current->data.name << endl;
		current = current->next;
	}
}

void deleteList(node *&head)
{
	
	node *current;

    while (head)
    {
		current = head->next;
		delete [] head ->data.description;
		delete head;
        head = current;
    }
}

//basic functions
void runMenu(event &an_event, node *&head)
{
    int choice;

    cout << "\nMenu\n";
    cout << "1. Add Event\n";
    cout << "2. Display Events\n";
    cout << "3. Quit\n";

    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(100, '\n');

    while (choice != 3)
    {
        switch (choice)
        {
        case 1:
			addEvent(an_event);
			insert(an_event, head);		
			break;
        case 2:
            displayList(head);
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

        cout << "\nMenu\n";
        cout << "1. Add Event\n";
        cout << "2. Display Events\n";
        cout << "3. Quit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(100, '\n');
    }

    cout << "Have a nice time!" << endl;
}
void addEvent(event &events)
{
	char temp[DESC];
	
	cout << "Name: ";
	cin.get(events.name, NAME, '\n');
	cin.ignore(100,'\n');

	cout << "Description: ";
	cin.get(temp, DESC, '\n');
	cin.ignore(100,'\n');
	events.description = new char [strlen(temp)+1];
	strcpy(events.description, temp);
	
	cout << "Location: ";
	cin.get(events.loc, LOC, '\n');
	cin.ignore(100,'\n');

	timeDateCost(events);
}

void timeDateCost(event &events)
{
	cout << "Time: ";
	cin >> events.time;
	cin.ignore(100,'\n');

	
	while(events.time < 0 || events.time > 1259)
	{
		cout << "Enter time in hhmm format only" << endl;
		cout << "Time: ";
		cin >> events.time; cin.ignore(100,'\n'); } cout << "Date: "; cin >> events.date; cin.ignore(100,'\n'); while(events.date < 10123 || events.date > 123130) { cout << "Enter date in mmddyy format." << endl; cout << "Date: ";
		cin >> events.date;
		cin.ignore(100,'\n');
	}

	cout << "Cost:$";
	cin >> events.cost;
	cin.ignore(100,'\n');
	
	while(events.cost < 0)
	{
		cout << "Cost must be a postive value." << endl;
		cout << "Cost:$";
		cin >> events.cost;
		cin.ignore(100,'\n');
	}
}

/*
 *struct event
{
	char name[NAME];
	char * description;
	char loc[LOC]; //location
	int time; //hhmm
	int date; //mmddyy
	double cost;
};
*/


void displayEvent(const event &events)
{
	cout << "Name: " << events.name << endl;
	cout << "Description: " << events.description << endl;
	cout << "Location: " << events.loc << endl;
	cout << "Time: " << (events.time/100) << ":" << (events.time%100) << endl;
	cout << "Date: " << events.date << endl;
	cout << setprecision(2) << showpoint;

	cout << "Cost:$ " << events.cost << endl;
}
