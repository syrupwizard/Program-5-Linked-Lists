//this file contains the bulk of the program. There are two sets of functions, those which interact with the linear linked list,
// and those which interact with the user and get input.
#include "list.h"
void welcome()
{
	cout << "Event Planner 2000 loading...\n";
	cout << "Please insert event...\n";

}
// LLL functions
// this function inserts the first node created at the head of the list, the second node following it, and any further nodes
// also at the end of the list
void insert(event &an_event, node *&head)
{
	if(!head) //special case empty list, create new node
	{
		head = new node;
		head->data = an_event;
		head->next = nullptr;
		return;
	}

	node *temp = new node;
	temp->data = an_event;
	temp->next = nullptr;

	if(!head->next)
	{
		head->next = temp;
	}
	else
	{
		node *current = head;
		while(current->next)
		{
			current = current->next;
		}
		current->next = temp;

	}

/*code for inserting at beginning
	node *temp = new node; 
	temp->data = an_event;
	temp->next = head;
	head = temp;	*/

}

//This function takes input of a pointer to the head of the LLL and iterates through the list calling the display function with a
//pointer to the current node
void displayList(node *&head)
{
	node *current = head;
	while(current)
	{
		displayEvent(current->data);
		current = current->next;
	}
}

//this function deletes each node starting from head, iteratively, as well as freeing the dynamically allocated arrays within the node
//while there is no logic to ensure that data.description is not null, it should not be able to be null in the context of this program
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
//allows user to choose the function of their choosing. quits program when prompted
//validates user choice
void runMenu(event &an_event, node *&head)
{
    int choice;

    cout << "\nMenu\n";
    cout << "1. Add Event\n";
    cout << "2. Display Events\n";
    cout << "3. Quit\n";
	cout << "\n\n";

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

//takes user input into struct (no buffers), as well as dynamically allocating the size of the array of chars
//which holds description. calls timeDateCost to get those specific inputs
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

//this function is really not that great. There's a right way, and then there's the quick way.
//This is not how time and date should be handled
//validates some stuff and passes time date and cost into event struct
void timeDateCost(event &events)
{
	cout << "Time: ";
	cin >> events.time;
	cin.ignore(100,'\n');

	
	while(events.time < 0 || events.time > 1259)
	{
		cout << "Enter time in hhmm format only" << endl;
		cout << "Time: ";
		cin >> events.time;
		cin.ignore(100,'\n');
	}

	cout << "Date: "; cin >> events.date; cin.ignore(100,'\n'); 

	while(events.date < 10123 || events.date > 123130)
	{ 
		cout << "Enter date in mmddyy format." << endl; cout << "Date: ";
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

//displays the entirety of the LLL of events input by the user. 
//this function is called by display least on each node iteratively.
void displayEvent(const event &events) {
    cout << "\n\n";
    cout << "Name: " << events.name << endl;
    cout << "Description: " << events.description << endl;
    cout << "Location: " << events.loc << endl;
    cout << "Time: " << (events.time / 100) << ":" << (events.time % 100) << endl;
    cout << "Date: " << events.date << endl;
    cout << setprecision(2) << fixed << showpoint;
    cout << "Cost: $ " << events.cost << endl;
}

