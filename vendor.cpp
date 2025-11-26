/* Abe Busschau -- busschau@pdx.edu -- Program #1
 *
 * 10/17/25
 *
 * This program will help vendors plan a festival. More tuned for the vendors
 * of Entertainment, Food, and Parking. It will have a customer Interace and a vendor interface
 *
 * This File shows the implementation for the all of my classes involved with vendor
 * and its inheritance
*/

#include "vendor.h"

// Default Constructor
vendor::vendor(): date(nullptr), id(0) {}

// Arguement Constructor
vendor::vendor(string & name_copy, char * date_copy, int id_copy): date(nullptr), id(0)
{
	// Clear out the string
	name.clear(); 
	name = name_copy;

	// Deep copy Date
	date = new char[strlen(date_copy) + 1];
	strcpy(date, date_copy);

	// Copy id
	id = id_copy;
}

// Copy Constructor
vendor::vendor(const vendor & copy): date(nullptr), id(0)
{
	// Copy string
	name = copy.name;

	// Deep copy date
	date = new char[strlen(copy.date) + 1];
	strcpy(date, copy.date);

	// Copy id
	id = copy.id;
}

// Assignment Operator
vendor & vendor::operator = (const vendor & source)
{
	if (this == &source) return *this;

	if (date) delete [] date;

	date = new char[strlen(source.date) + 1];
	strcpy(date, source.date);
	
	// Copy name and id
	name.clear();
	name = source.name;

	id = source.id;

	return *this;
}

// Destructor
vendor::~vendor()
{
	// Deallocate Date
	if (date) delete [] date;
	
	// Clear Name
	name.clear();

	// Reset id
	id = 0;
}

// Returns whether or not this is the same name
int vendor::name_compare(const string & to_compare) const
{
	if (to_compare == name) return 1;
	else return 0;
}

// Displays the dates a vendor is open
int vendor::open_date() const
{
	cout << "\n\n" << name << " is Open: " << date << endl;
	return 1;
}

// Verify if ID is correct
int vendor::valid_id(const int id_check) const
{
	if (id_check == id)
		return 1;
	else
		return 0;
}

// Displays all info
int vendor::display() const
{
	cout << "\n\nName:     " << name
	     << "\nDates Open: " << date
	     << "\nID:         " << id << endl;
	return 1;
}

// Sets Name, Date, and ID
int vendor::set_data()
{
	char temp[SIZE]; // Temp array for Dates
	
	// Get Name
	cout << "\n\nPlease Enter Name: ";
	getline(cin, name);

	// Make it all Upper case for Retrievals
	for (char &c : name)
		c = toupper(c);

	// Get Dates open
	cout << "\nEnter Dates open (MM/DD - MM/DD): ";
	cin.getline(temp, SIZE);

	date = new char[strlen(temp) + 1];
	strcpy(date, temp);

	// Get ID
	cout << "\nEnter ID: ";
	cin >> id; cin.ignore(100, '\n');

	return 1;
}
	

