/* Abe Busschau -- busschau@pdx.edu -- Program #1
 *
 * 10/17/25
 *
 * This program will help vendors plan a festival. More tuned for the vendors
 * of Entertainment, Food, and Parking. It will have a customer Interace and a vendor interface
 *
 * This File shows the implementation for the derived Food class
*/

#include "vendor.h"

// Default Constructor
food::food(): price(0.0), gluten(false), amount(0) {}

// Arguement Constructor
food::food(float copy_price, bool copy_gluten, int copy_amount, const food & source): vendor(source), price(0.0), gluten(false), amount(0)
{
	price = copy_price;
	gluten = copy_gluten;
	amount = copy_amount;
}

// Buy Food from vendor and manage inventory
int food::buy()
{
	if (amount == 0) return 0;
	else 
	{
		--amount;
		return 1;
	}
}

// Returns true if it is Gluten Free
int food::gluten_free() const
{
	if (gluten) return 0;
	else return 1;
}

// Returns true if in price range
int food::price_range(const float low, const float high) const
{
	if (high < 0.0 || low >= high) return 0;

	if (price >= low && price <= high) return 1;
	else return 0;
}

// Displays All contents
int food::display() const
{
	// Display Parent First
	if (vendor::display())
	{
		cout << "\nPrice: " << price
		     << "\nHas Gluten: " << (gluten ? "Yes" : "No")
		     << "\nAmount left: " << amount << endl;
		return 1;
	}
	else return 0;
}

// Sets all data for class
int food::set_data()
{
	// Set Base Info First
	if (vendor::set_data())
	{
		int choice{}; // For Gluten
		do{
			// Get Price of food
			cout << "\n\nPrice: ";
			cin >> price; cin.ignore(100, '\n');

			// Error Check
			if (price < 0.0)
			       cout << "\n\nMust be a Positive Number!\n" << endl;

		}while (price < 0.0);

		do{
			// Get Gluten Status
			cout << "\nGluten:\n\t1. Yes\n\t2. No\nEnter: ";
			cin >> choice; cin.ignore(100, '\n');

			// Error Check
			if (choice != 1 && choice != 2)
				cout << "\n\nPlease Enter 1 or 2!\n" << endl; 

		}while (choice != 1 && choice != 2);

		if (choice == 1) gluten = true;
		else gluten = false;

		do{
			// Get Amount of Food
			cout << "\nAmount of Food: ";
			cin >> amount; cin.ignore(100, '\n');
			
			// Error Check
			if (amount < 0)
			       cout << "\n\nCan't be Negative!\n" << endl;

		}while (amount < 0);

		return 1;
	}
	else return 0;
}
