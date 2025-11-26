/* Abe Busschau -- busschau@pdx.edu -- Program #1
 *
 * 10/17/25
 *
 * This program will help vendors plan a festival. More tuned for the vendors
 * of Entertainment, Food, and Parking. It will have a customer Interace and a vendor interface
 *
 * This File shows the implementation for the derived Stage class
*/

#include "vendor.h"


// Default Constructor
stage::stage(): seats(0), act(nullptr), time(0) {}

// Arguement Constructor
stage::stage(int seats_copy, char * act_copy, int time_copy): seats(0), act(nullptr), time(0)
{
	// Copy Seats
	seats = seats_copy;

	// Deep Copy Act
	act = new char[strlen(act_copy) + 1];
	strcpy(act, act_copy);

	// Copy time
	time = time_copy;
}

// Copy Constructor
stage::stage(const stage & copy): vendor(copy), seats(0), act(nullptr), time(0)
{
	// Copy Seats
	seats = copy.seats;

	// Deep Copy Act
	act = new char[strlen(copy.act) + 1];
	strcpy(act, copy.act);

	// Copy time
	time = copy.time;
}

// Assignment Operator
stage & stage::operator = (const stage & source)
{
	if (this == &source) return *this;

	if (act) delete [] act;

	// Call Parent AO
	vendor::operator=(source);

	act = new char[strlen(source.act) +1];
	strcpy(act, source.act);

	// Copy Seats and time
	seats = source.seats;
	time = source.time;

	return *this;
}

// Destructor
stage::~stage()
{
	if (act) delete [] act;

	seats = 0;
	time = 0;
}

// Displays what time the band will go on stage
int stage::time_search() const
{
	cout << "\n\nTime on Stage: " << time << endl;
	return 1;
}

// Displays # of seats left
int stage::seating()const
{
	cout << "\n\nSeats Remaining: " << seats << endl;
	return 1;
}

// Reserves seats
int stage::reserve(const int amount)
{
	if (amount > seats || amount < 1) return 0;

	else 
	{
		seats -=amount;
		cout << "\n\nSeats Reserved!\n" << endl;
		return 1;
	}
}

// Displays what act the group is doing
int stage::type() const 
{
	cout << "\n\nAct: " << act << endl;
	return 1;
}

// Display
int stage::display() const
{
	// Display Parent First
	if (vendor::display())
	{
		cout << "\nSeats Avialable: " << seats
		     << "\nAct: " << act
		     << "\nTime Start: " << time << endl;
		return 1;
	}
	else return 0;
}

// Set All the data in class
int stage::set_data()
{
	char temp[SIZE]; // Temp array for act

	// Set Base Info First
	if (vendor::set_data())
	{
		do{
			// Get Seats Avialable
			cout << "\n\nSeats Avialable: ";
			cin >> seats; cin.ignore(100, '\n');

			// Error Check
			if (seats < 1)
			       cout << "\n\nMust be at Least 1!\n" << endl;

		}while (seats < 1);

		// Get Act info
		cout << "\nEnter Act (Band, Dance, etc): ";
		cin.getline(temp, SIZE);

		act = new char[strlen(temp) + 1];
		strcpy(act, temp);

		do{
			// Get Time Starting
			cout << "\nTime Start (24h, NO COLON). Example, if start at 5:00pm, Enter 1700\nEnter: ";
			cin >> time; cin.ignore(100, '\n');
			
			// Error Check
			if (time < 0)
			       cout << "\n\nCan't be Negative!\n" << endl;

		}while (time < 0);

		return 1;
	}
	else return 0;
}
