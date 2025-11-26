/* Abe Busschau -- busschau@pdx.edu -- Program #1 
 *
 * 10/17/25
 *
 * This program will help vendors plan a festival. More tuned for the vendors
 * of Entertainment, Food, and Parking. It will have a customer Interace and a vendor interface
 *
 * This is the Header file for the Data Structure classes and their Nodes. It shows the prototypes of 
 * the Four classes: CLL, LLL, and their respective Nodes. It shows the prototypes of the two types of Nodes: CLL and LLL. 
 * One for Stage and one for Food. Parking lot will be held
 * in a Vector 
*/

#include "vendor.h"

// Class for Node CLL
class cnode : public stage
{
	public:
		cnode(); // Default Constructor
		cnode(const stage & source); // Arguement Constructor
		void set_next(cnode *& next); // Set Next Node
		cnode *& get_next(); // Get Next Node
	private:
		cnode * next; // Next Pointer
};


// Class for Node LLL
class lnode : public food
{
	public:
		lnode(); // Default Constructor
		lnode(const food & source); // Constructor
		void set_next(lnode *& next); // Set Next Node
		lnode *& get_next(); // Get Next Node
	private:
		lnode * next; // Next Pointer
};

//************************************************************

// Class for the CLL with Entertainment(Stage)
class cll
{
	public:
		cll(); // Default Constructor
		cll(const cll & source); // Copy Constructor
		cll & operator = (const cll &); // Assignment Operator
		~cll(); // Destructor
		int insert(); // Insert a act
		int remove(); // Remove a band/dance based on name
		int remove_all(); // Remove entire list
		int search(); // Retrieve a Band/Dance
		int display(); // Display Everything in List

		// Functions to help with derived functions
		int show_time(); // Displays the time for a searched act
		int seating_open(); // Seating Still open for a act
		int reserve_seat(); // Reserves Seat at the act
		int show_act(); // Shows what the act is for a group
		int id_check(); // Checks if id is in List

	private:
		cnode * rear; // Rear pointer to Stage CLL

		// Recursive Functions for the public wrappers
		void copy(cnode *& rear, cnode * src, cnode * first, cnode *& temp); // For the copy constructor and AO
		int remove(cnode *& rear, cnode *& prev, const string & to_remove); // Remove an Act
		int remove_all(cnode *& rear); // Remove all Nodes
		cnode* retrieve(cnode * rear, const string & name) const; // Retrieve a Act
		int display(cnode *& rear); // Display All Nodes 
		string & search_name(string &); // Returns the name the user wants to search for
		int id_check(cnode * rear, int id_to_find); // Checks if ID is in list
};


// Class for the LLL with Food
class lll 
{
	public:
		lll(); // Default Constructor
		lll(const lll & source); // Copy Constructor
		lll & operator = (const lll &); // Assignment Operator
		~lll(); // Destructor
		int insert(); // Insert a Food
		int remove(); // Remove Food Item
		int remove_all(); // Remove entire list
		int search(); // Retrieve a Food
		int display(); // Display Everything in List

		// Functions to Help with derived Functions
		int buy_food(); // Buys a food Product
		int range(); // Displays all food within Price Range
		int gluten_display(); // Displays All gluten free foods
		int id_check(); // Checks if ID is in list

	private:
		lnode * head; // Head pointer to Stage LLL

		// Recursive Functions for the public wrappers
		void copy(lnode *& head, lnode * src); // Copy function for Copy Constructor and AO
		int remove(lnode *& head, const string & to_remove); // Remove a Food
		int remove_all(lnode *& head); // Remove all Nodes
		lnode* retrieve(lnode *& head, const string & find); // Retrieve a Food
		int display(lnode *& head); // Display All Nodes 
		string & search_name(string &); // Returns the name the user wants to search for
		int range(lnode * head, int low, int high); // Recursive loop to display all Price range
		int gluten_display(lnode * head); // Displays all gluten free foods
		int id_check(lnode * head, int id_to_check); // Checks if ID is in list
};
