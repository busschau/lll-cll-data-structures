/* Abe Busschau -- busschau@pdx.edu -- Program #1
 *
 * 10/17/25
 *
 * This program will help vendors plan a festival. More tuned for the vendors
 * of Entertainment, Food, and Parking. It will have a customer Interace and a vendor interface
 *
 * This File shows the implementation of the LLL Data Structure
*/

#include "CLL_LLL.h"


// Default Constructor
lll::lll(): head(nullptr) {}

// Copy Constructor
lll::lll(const lll & source): head(nullptr)
{
	// If there is source
	if (source.head)
	{
		// Recursivly Copy
		copy(head, source.head);
	}
}

// Assignment Operator
lll & lll::operator = (const lll & source)
{
	if (this == &source) return *this;

	// If head, then delete it
	if (head)
	{
		if (!remove_all(head))
			return *this; // Remove failed
	}

	// If Something there
	if (source.head)
	{
		// Deep copy
		copy(head, source.head);
	}

	// Source is Empty
	else
		head = nullptr;

	return *this;
}

// Copy Function (Recursive)
void lll::copy(lnode *& head, lnode * src)
{
	// Base Case
	if (!src)
	{
		head = nullptr;
		return;
	}

	// Deep Copy Source into head
	head = new lnode(*src);

	copy(head->get_next(), src->get_next());
}

// Destructor
lll::~lll()
{
	// If Something at head
	if (head)
	{
		if (!remove_all(head))
			cerr << "\n\nError Deleteing\n" << endl;
	}
	head = nullptr;
}

// Remove All Foods (Wrapper)
int lll::remove_all()
{
	if (!head) return 0;

	return remove_all(head);
}
	
// Remove All Nodes (Recursive)
int lll::remove_all(lnode *& head)
{
	if (!head)
		return 1;

	int flag = remove_all(head->get_next());

	delete head;
	head = nullptr;

	return flag;
}

// Insert Food
int lll::insert()
{
	// New List
	if (!head)
	{
		head = new lnode;
		if (head->set_data())
			return 1;
		// Setting Data Failed
		else return 0;
	}

	// Existing List
	else 
	{
		lnode * temp = new lnode;
		if (temp->set_data())
		{
			temp->set_next(head);
			head = temp;
			return 1;
		}

		// Setting Data Failed
		else return 0;
	}
}

// Display All Food (Wrapper)
int lll::display()
{
	if (!head) return 0;

	return display(head);
}

// Display All Food (Recursive)	
int lll::display(lnode *& head)
{
	if (!head) return 1;

	if (head->display())
	{
		cout << "--------------------------------------";
		return display(head->get_next());
	}
	else return 0;
}

// Remove Single Node (Wrapper)
int lll::remove()
{
	if (!head) return 0;

	string find; // Name to find
	
	find = search_name(find);

	return remove(head, find);
}

// Remove Single Food (Recursive)
int lll::remove(lnode *& head, const string & find)
{
	// Base Case
	if (!head) return 0;

	// If Match, Delete
	if (head->name_compare(find))
	{
		lnode * hold = head->get_next();
		delete head;
		head = hold;
		return 1;
	}
	else return remove(head->get_next(), find);
}

// Returns the name the user wants to search for
string & lll::search_name(string & find)
{
	// Get What act to find from user
	cout << "\n\nEnter Food Name to Search. Check Spelling!!\nEnter: ";
	getline(cin, find);

	// Make all Upper case
	for (char &c : find)
		c = toupper(c);

	return find;
}

// Rearch A.K.A. Retrieve Food (Wrapper)
int lll::search()
{
	if (!head) return 0;

	string find; // String to Find
	lnode * temp{nullptr}; // Node to Find

	// Get Name and Node
	find = search_name(find);

	temp = retrieve(head, find);

	// If Found, Display Food
	if (temp)
	{
		cout << "\n\n" << find << " Information:" << endl;
		if (temp->display())
			return 1;
		else return 0;
	}
	else return 0;
}

// Retrieve a Food (Recursive)
lnode* lll::retrieve(lnode *& head, const string & find)
{
	if (!head) return nullptr;

	if (head->name_compare(find))
		return head;
	else return retrieve(head->get_next(), find);
}

// Buys a Food 
int lll::buy_food()
{
	if (!head) return 0;

	string find; // To help find Food
	lnode * temp{nullptr}; // To Hold food node

	// Get Name and Node
	find = search_name(find);

	temp = retrieve(head, find);

	// If Found, Buy Food
	if (temp)
	{
		if (temp->buy())
		{
			// Bought Food!
			cout << "\n\nFood Bought!\n" << endl;
			return 1;
		}

		// No More food avialable
		else 
		{
			cout << "\n\nNo more of this Food!\n" << endl;
			return 1;
		}
	}
	else return 0;
}

// Displays All Food Within Price Range (Wrapper)
int lll::range()
{
	if (!head) return 0;

	float low{}; // Low End
	float high{}; // High End

	// Recieve Prices, Input Validation
	do{
		cout << "\n\nEnter the Lowest Amount: ";
		cin >> low; cin.ignore(100, '\n');

		if (low < 0)
			cout << "\n\nMust be Above 0!\n" << endl;
	}while (low < 0);

	// Get High Price
	do{
		cout << "\n\nEnter the Highest Amount: ";
		cin >> high; cin.ignore(100, '\n');

		if (high <= low)
			cout << "\n\nMust Be Higher than the Lowest Amount!\n" << endl;
	}while (high <= low);

	cout << "\n\nAll Foods in Range:\n" << endl;
	return range(head, low, high);
}

// Range (Recursive)
int lll::range(lnode * head, int low, int high)
{
	// Base Case
	if (!head) return 0;

	if (head->price_range(low, high))
	{
		// Match!
		if (head->display())
		{
			cout << "--------------------------------------";
			return range(head->get_next(), low, high) + 1;
		}
		else return 0;
	}

	// No Match, go to next one
	else return range(head->get_next(), low, high);
}

// Displays All Gluten Free Options (Wrapper)
int lll::gluten_display()
{
	if (!head) return 0;

	return gluten_display(head);
}

// Displays All Gluten Free Options (Recursive)
int lll::gluten_display(lnode * head)
{
	// Base Case
	if (!head) return 0;

	if (head->gluten_free())
	{
		// Is Gluten Free!
		if (head->display())
		{
			cout << "--------------------------------------";
			return gluten_display(head->get_next()) + 1;
		}
		else return 0;
	}
	else return gluten_display(head->get_next());
}

// Checks if ID is in List (Wrapper)
int lll::id_check()
{
	if (!head) return 0;

	int num{}; // Holds User input

	// Gets User ID, Input Validation	
	do{
		cout << "\n\nEnter ID to Check: ";
		cin >> num; cin.ignore(100, '\n');

		if (num < 0)
			cout << "\n\nNumber Must be above 0!\n" << endl;
	}while (num < 0);

	return id_check(head, num);
}

// Checks if ID is in list (Recursive)
int lll::id_check(lnode * head, int id_find)
{
	// Base Case
	if (!head) return 0;

	if (head->valid_id(id_find))
		return 1;
	else return id_check(head->get_next(), id_find);
}
