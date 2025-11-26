/* Abe Busschau -- busschau@pdx.edu -- Program #1
 *
 * 10/17/25
 *
 * This program will help vendors plan a festival. More tuned for the vendors
 * of Entertainment, Food, and Parking. It will have a customer Interace and a vendor interface
 *
 * This File shows the implementation of the application class
*/

#include "CLL_LLL.h"


// Vendors Main Menu
int application::vendors()
{
	int choice{0}; // For what to return

	do{
		// Main Menu 
		cout << "\n\nMain Menu:\nChoose Vendor:"
		     << "\n\n\t1. Stage\n\t2. Food\n\t3. Parking Lot\n\t4. Quit"
		     << "\n\nEnter: ";
		cin >> choice; cin.ignore(100, '\n');

		// Input Validation
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
			cout << "\n\nMust Enter an Option Above!\n" << endl;
	}while (choice != 1 && choice != 2 && choice != 3 && choice != 4);

	return choice;
}

// Food Menu
int application::food_menu()
{
	int choice{0}; // What choice to return
	
	do{
		// Food Menu
		cout << "\n\nFood Menu:"
		     << "\n\n\t1. Insert Food\n\t2. Remove Food\n\t3. Display All Food"
		     << "\n\t4. Remove All Food\n\t5. Search Food\n\t6. Buy Food"
		     << "\n\t7. Show All within Price Range\n\t8. Gluten Free"
		     << "\n\t9. ID Check\n\t10. Quit\n\nEnter: ";
	        cin >> choice; cin.ignore(100, '\n');

		if (choice < 1 || choice > 10)
			cout << "\n\nMust be between 1 and 10!\n" << endl;	

	}while(choice < 1 || choice > 10);

	return choice;
}

// Stage Menu
int application::stage_menu()
{
	int choice{0}; // What choice to return
	
	do{
		// Stage Menu
		cout << "\n\nStage Menu:"
		     << "\n\n\t1. Insert Act\n\t2. Remove Act\n\t3. Display All Act(s)"
		     << "\n\t4. Remove All Act(s)\n\t5. Search Act\n\t6. Show Time for Act"
		     << "\n\t7. Seating Avialable\n\t8. Reserve Seat\n\t9. Type of Act"
		     << "\n\t10. ID Check\n\t11. Quit\n\nEnter: ";
	        cin >> choice; cin.ignore(100, '\n');

		if (choice < 1 || choice > 11)
			cout << "\n\nMust be between 1 and 11!\n" << endl;	

	}while(choice < 1 || choice > 11);

	return choice;
}

// Parking Lot Menu
int application::lot_menu() 
{
	int choice{0}; // What choice to return
	
	do{
		// Parking Menu
		cout << "\n\nParking Lot Menu:"
		     << "\n\n\t1. Insert Space\n\t2. Remove Space\n\t3. Display All Parking Space(s)"
		     << "\n\t4. Remove All Parking\n\t5. Search Space\n\t6. Display All Open Space"
		     << "\n\t7. Reserve Space\n\t8. Display All Handicap"
		     << "\n\t9. ID Check\n\t10. Quit\n\nEnter: ";
	        cin >> choice; cin.ignore(100, '\n');

		if (choice < 1 || choice > 10)
			cout << "\n\nMust be between 1 and 10!\n" << endl;	

	}while(choice < 1 || choice > 10);

	return choice;
}	
