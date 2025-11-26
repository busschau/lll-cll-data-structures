/* Abe Busschau -- busschau@pdx.edu -- Program #1
 *
 * 10/17/25
 *
 * This program will help vendors plan a festival. More tuned for the vendors
 * of Entertainment, Food, and Parking. It will have a customer Interace and a vendor interface
 *
 * This is the Header file for the Vendor classes. It shows the prototypes of 
 * the four classes: Base class, Entertainment(Stage), Food, and Parking(lot). Use these classes when wanting to
 * use these vendors in your festival
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int SIZE {105};


// Vender Class (Base Class)
class vendor
{
	public:
		vendor(); // Default Constructor
		vendor(string & name_copy, char * date_copy, int id_copy); // Arguement Constructor
		vendor(const vendor & copy); // Copy Constructor
		vendor & operator = (const vendor &); // Assignment Operator
		~vendor(); // Destructor
		int name_compare(const string & to_compare) const; // Returns whether or not this is the same name
		int open_date() const; // Display the dates that the vendor's are open
		int valid_id(const int id_check) const; // Verifies who ID this is
		int display() const; // Displays Name, Dates, and ID code
		int set_data(); // Sets all the data in Vendor class

	private:
		string name; // Name of Band, Food, or Merch
		char * date; // Dates the vendor is avialable
		int id; // ID code that every vendor will have
};

// Class for the Entertainment (stage)
class stage : public vendor
{
	public:
		stage(); // Default Constructor
		stage(int seats_copy, char * act_copy, int time_copy); // Arguement Constructor
		stage(const stage & copy); // Copy Constructor
		stage & operator = (const stage &); // Assignment Operator
		~stage(); // Destructor
		int time_search() const; // Displays what time a certain band will go one stage
		int seating()const; // Displays how much seating is left for a certain band 
		int reserve(const int amount_to_reserve); // reserves seat
		int type() const; // Displays The act of the band
		int display() const; // Displays all contents
		int set_data(); // Set all the data in class
		
	private:
		int seats; // Seating avialable 
		char * act; // Whether they are dancing or a Band
		int time; // What time they are on stage (24 hour)
};

// Class for Food provided
class food : public vendor
{
	public: 
		food(); // Default COnstructor
		food(float copy_price, bool copy_gluten, int copy_amount, const food & source); // Arguement Constructor
		int buy(); // Buy food from vendor and manage Inventory
		int gluten_free() const; // Returns true if gluten free
		int price_range(const float low, const float high) const; // Returns true if food is between price range
		int display() const; // Displays all contents
		int set_data(); // Sets all data for class

	private:
		float price; // Price of food item
		bool gluten; // Has gluten or not
		int amount; // Amount left of that food
};

// Class for Parking lot. Each class is 1 Parking spot
class lot : public vendor
{
	public:
		lot(); // Default Constructor
		lot(bool open, bool handicap, string & location, const lot & source); // Arguement Constructor
		int is_open() const; // Returns whether the parking spot is open or not
		int reserve(); // Reserves a parking spot for you, also tells if handicap and where it is
		int handicap_open() const; // Shows handicap spots available
		int display() const; // Displays All its contents
		int set_data(); // Sets all data for class

	private:
		bool open; // Whether the parking spot is open or not
		bool handicap; // Whether it is handicap spot or not
		string location; // General location of where it is
};

// Menu Class
class application
{
	public:
		int vendors(); // Choose whcih vendor to access

		// Vendor Menu's
		int food_menu();
	        int stage_menu();
		int lot_menu(); 
};
