/* Abe Busschau -- busschau@pdx.edu -- Program #1
 *
 * 10/17/25
 *
 * This program will help vendors plan a festival. More tuned for the vendors
 * of Entertainment, Food, and Parking. It will have a customer Interace and a vendor interface
 *
 * This File shows the implementation for the derived Lot class
*/

#include "vendor.h"


// Default Constructor
lot::lot(): open(true), handicap(false) {}

// Arguement Constructor
lot::lot(bool copy_open, bool copy_handicap, string & copy_location, const lot & source): vendor(source), open(true), handicap(false)
{
	// Copy Open
	open = copy_open;

	// Copy String
	location.clear();
	location = copy_location;

	// Copy Handicap Status
	handicap = copy_handicap;
}

// Returns true if parking spot is open
int lot::is_open() const
{
	if (open) return 1;
	else return 0;
}

// Reserves parking for you
int lot::reserve()
{
	if (!open) return 0;

	// Reserve
	open = false;

	// Display some info
	cout << "\n\nHandicap: " << handicap
	     << "\nLocation: " << location << endl;
	return 1;
}

// Shows if spot is handicap
int lot::handicap_open() const
{
	if (handicap) return 1;
	else return 0;
}

// Display All Contents
int lot::display() const
{
	// Display Parent First
	if (vendor::display())
	{
		cout << "\n\nOpen: " << (open ? "Yes" : "No")
		     << "\nHandicap: " << (handicap ? "Yes" : "No")
		     << "\nLocation: " << location << endl;
		return 1;
	}
	else return 0;
}

// Sets All data for class
int lot::set_data()
{
	// Set Base Info First
	if (vendor::set_data())
	{
		int choice{}; // For open and handicap
		do{
			// Get Open Status
			cout << "\nOpen:\n\t1. Yes\n\t2. No\nEnter: ";
			cin >> choice; cin.ignore(100, '\n');

			// Error Check
			if (choice != 1 && choice != 2)
			       cout << "\n\nPlease Enter 1 or 2!\n" << endl;

		}while (choice != 1 && choice != 2);

		if (choice == 1) open = true;
		else open = false;

		do{
			// Get Handicap Status
			cout << "\nHandicap Accessible:\n\t1. Yes\n\t2. No\nEnter: ";
			cin >> choice; cin.ignore(100, '\n');

			// Error Check
			if (choice != 1 && choice != 2)
				cout << "\n\nPlease Enter 1 or 2!\n" << endl; 

		}while (choice != 1 && choice != 2);

		if (choice == 1) handicap = true;
		else handicap = false;

		// Get Location info
		cout << "\nEnter Description of where it is in the lot: ";
		getline(cin, location);

		return 1;
	}
	else return 0;
}
