/* Abe Busschau -- busschau@pdx.edu -- Program #1 
 *
 * 10/17/25
 *
 * This program will help vendors plan a festival. More tuned for the vendors
 * of Entertainment, Food, and Parking. It will have a customer Interace and a vendor interface
 *
 * This File shows the implementation of the CLL Data Structure
*/

#include "CLL_LLL.h"

// Default Constructor
cll::cll(): rear(nullptr) {}


// Copy Constructor
cll::cll(const cll & source): rear(nullptr)
{
	// If there is source
	if (source.rear)
	{
		cnode * temp{nullptr};

		// Recursivly Copy
		copy(rear, source.rear->get_next(), source.rear, temp);

		// Attatch CLL
		temp->set_next(rear);
		rear = temp;
	}
}

// Recursive for Copy Constructor and AO	
void cll::copy(cnode *& rear, cnode * src, cnode * first, cnode *& tail)
{
	// Base Case
	if (src == first)
	{
		// Make Last node
		rear = new cnode(*src);
		tail = rear;
		return;
	}

	// Deep Copy Source into rear
	rear = new cnode(*src);

	copy(rear->get_next(), src->get_next(), first, tail);
}

// Assignment Operator
cll & cll::operator = (const cll & source)
{
	if (this == &source) return *this;

	// If rear, then delete it
	if (rear)
	{
		// Break List
		cnode * empty = nullptr;
		cnode * head = rear->get_next();
		rear->set_next(empty);
		if (!remove_all(head))
			return *this; // Remove Failed
	}

	// If Something there
	if (source.rear)
	{
		// Deep copy
		cnode * tail{nullptr};
		copy(rear, source.rear->get_next(), source.rear, tail);
		tail->set_next(rear);
		rear = tail;
	}

	// Source is Empty
	else
		rear = nullptr;

	return *this;
}

// Destructor
cll::~cll()
{
	// If Something at rear
	if (rear)
	{
		// Break List
		cnode * empty = nullptr;
		cnode * head = rear->get_next();
		rear->set_next(empty);

		if (!remove_all(head))
			cerr << "\n\nError Deleteing\n" << endl;
	}
	rear = nullptr;
}

// Remove All Wrapper
int cll::remove_all()
{
	if (!rear) return 0;

	// Break the List
	cnode * empty = nullptr;
	cnode * head =rear->get_next();
	rear->set_next(empty);

	// Remove Entire list
	int flag =  remove_all(head);
	rear = nullptr;

	return flag;
}

// Remove All (Recursive)
int cll::remove_all(cnode *& head)
{
	// (Base Case)
	if (!head) return 1;

	// Tail Recursion
	int flag = remove_all(head->get_next());

	// Delete Node
	delete head;
	head = nullptr;
	
	return flag;
}

// Insert a Act
int cll::insert() 
{
	// Adding New list
	if (!rear)
	{
		// Creat Rear
		rear = new cnode;
		
		if (rear->set_data())
		{
			// Link it up
			rear->set_next(rear);
			return 1;
		}
		else return 0;
	}

	// Adding at end of list
	else
	{
		cnode * temp = new cnode;
		if (temp->set_data())
		{
			// Add it to list
			temp->set_next(rear->get_next());
			rear->set_next(temp);
			rear = temp;
			return 1;
		}
		else return 0;
	}
}

// Remove Single Act (Wrapper)
int cll::remove()
{
	if (!rear) return 0;

	string find; // String to find
	cout << "\n\nEnter Act Name to Remove. Check Spelling!!\nEnter: ";
	getline(cin, find);

	// Make all Upper case
	for (char &c : find)
		c = toupper(c);

	return remove(rear->get_next(), rear, find);
}

// Remove Single Act (Recursive)
int cll::remove(cnode *& rear, cnode *& prev, const string & find)
{
	// Base Case
	if (this->rear == rear)
	{
		// If Match
		if (rear->name_compare(find))
		{
			// If only 1 Node
			if (rear == rear->get_next())
			{
				delete rear;
				this->rear = nullptr;
			}
			// If Multiple Nodes
			else
			{
				// Delete and Reset Real Rear
				cnode * temp = rear->get_next();
				delete rear;
				rear = temp;
				this->rear = prev;
			}
			return 1;
		}
		else return 0;
	} // End Base Case

	// In Middle of CLL
	if (rear->name_compare(find))
	{
		cnode * temp = rear->get_next();
		delete rear;
		rear = temp;
		return 1;
	}

	// Not Match, move on
	else
	{
		prev = rear;
		return remove(rear->get_next(), prev, find);
	}
}

// Search A.K.A Retrieve (Wrapper)
int cll::search()
{
	if (!rear) return 0;
	
	string find; // String to find
	cnode * temp{nullptr}; // Node Found

	// Get Name to find
	find = search_name(find);

	temp = retrieve(rear->get_next(), find);

	// Display search results
	if (temp)
	{
		cout << "\n\n" << find << " Information:" << endl;
		if (temp->display())
			return 1;
		else return 0;
	}
	else return 0;
}

// Retrieve (Recursive)
cnode* cll::retrieve(cnode * rear, const string & find) const
{
	// Base Case
	if (this->rear == rear)
	{
		// If Match, return node. If not, return nullptr
		if (rear->name_compare(find))
			return rear;
		else return nullptr;
	}

	// If Match, return node
	if (rear->name_compare(find))
		return rear;
	else return retrieve(rear->get_next(), find);
}

// Display All (Wrapper)
int cll::display() 
{
	// Empty List
	if (!rear) return 0;

	return display(rear->get_next());
}

// Display All (Recursive)
int cll::display(cnode *& rear) 
{
	// Base Case
	if (this->rear == rear)
	{
		if (rear->display())
			return 1;
		else return 0;
	}

	if (rear->display())
	{
		cout << "--------------------------------------";
		return display(rear->get_next());
	}
	else return 0;
}

// Displays the time for a searched act
int cll::show_time()
{
	if (!rear) return 0;
	
	string find; // String to find
	cnode * temp{nullptr}; // Node Found
	
	// Get Name to find
	find = search_name(find);

	temp = retrieve(rear->get_next(), find);

	// If found, Display time
	if (temp)
	{
		if (temp->time_search())
			return 1;
		else return 0;
	}

	else return 0;
}

// Seating still open for an act
int cll::seating_open()
{
	if (!rear) return 0;

	string find; // String to find
	cnode * temp{nullptr}; // Node Found

	// Get Name to find
	find = search_name(find);

	temp = retrieve(rear->get_next(), find);

	// If found, Display Seating Avialable
	if (temp)
	{
		if (temp->seating())
			return 1;
		else return 0;
	}
	else return 0;
}

// Returns the name the user wants to search for
string & cll::search_name(string & find)
{
	// Get What act to find from user
	cout << "\n\nEnter Act Name to Search. Check Spelling!!\nEnter: ";
	getline(cin, find);

	// Make all Upper case
	for (char &c : find)
		c = toupper(c);

	return find;
}

// Reserves Seat at the act
int cll::reserve_seat()
{
	if (!rear) return 0;

	string find; // String to find
	int num{}; // Number of Seats wanting to reserve
	cnode * temp{nullptr};

	// Get Name to find
	find = search_name(find);

	temp = retrieve(rear->get_next(), find);

	// Reserve seat
	if (temp)
	{
		// Number of seats to reserve
		do{
			cout << "\n\nEnter # of Seats to Reserve: ";
			cin >> num; cin.ignore(100, '\n');

			if (num < 1)
				cout << "\n\nMust be at Least 1!\n" << endl;
		}while(num < 1);

		// reserve them
		if (temp->reserve(num))
			return 1;
		else
		{
			cout << "\n\nReserve Amount to much or No more Seats Avialable!\n" << endl;
			return 1;
		}
	}
	else return 0;
}

// Shows what the act is for a group
int cll::show_act()
{
	if (!rear) return 0;

	string find; // String to find
	cnode * temp{nullptr}; // Node to find

	// Get Name from user
	find = search_name(find);

	temp = retrieve(rear->get_next(), find);

	// If Found, Display act
	if (temp)
	{
		if (temp->type())
			return 1;
		else return 0;
	}
	else return 0;
}

// Checks if ID is in List (Wrapper)
int cll::id_check()
{
	if (!rear) return 0;

	int num{}; // Holds User input

	// Gets ID to Check	
	do{
		cout << "\n\nEnter ID to Check: ";
		cin >> num; cin.ignore(100, '\n');

		if (num < 0)
			cout << "\n\nNumber Must be above 0!\n" << endl;
	}while (num < 0);

	return id_check(rear->get_next(), num);
}

// Checks if ID is in list (Recursive)
int cll::id_check(cnode * rear, int id_find)
{
	// Base Case
	if (this->rear == rear)
	{
		if (rear->valid_id(id_find))
			return 1;
		else return 0;
	}

	// If ID is true, then its is List!
	if (rear->valid_id(id_find))
		return 1;
	else return id_check(rear->get_next(), id_find);
}
