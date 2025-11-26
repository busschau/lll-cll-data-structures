/* Abe Busschau -- busschau@pdx.edu -- Program #1 
 *
 * 10/17/25
 *
 * This program will help vendors plan a festival. More tuned for the vendors
 * of Entertainment, Food, and Parking. It will have a customer Interace and a vendor interface
 *
 * This file shows the main function. This is where it all happens
*/

#include "CLL_LLL.h"

int main()
{
	int choice {}; // Choice fo User for main menu
	application menu; // Holds all my menu options
	cll performance; // CLL of all the stage acts  
	lll eat; // LLL of all the Foods
	vector<lot> parking; // Vector Structure holding Parking Spaces
	string find; // Find Vector Spots
	int id{}; // For ID Check
	bool flag{false}; // Helps with finding vectors
	int i{}; // Helps with vector indexing

	
	// Main Menu Loop
	do {
		// Returns which vendor menu we should Access
		choice = menu.vendors();

		// Stage Menu
		if (choice == 1)
		{
			// Loop to stay in Stage menu until quit
			do {
				choice = menu.stage_menu();

				/* Based on choice */

				// Insert Act
				if (choice == 1)
				{
					if (performance.insert())
						cout << "\n\nAct Added!\n" << endl;
					else
						cout << "\n\nAct Failed to Add!\n" << endl;
				}

				// Remove Singular Act
				else if (choice == 2)
				{
					if (performance.remove())
						cout << "\n\nAct Removed!\n" << endl;
					else
						cout << "\n\nAct Not in List!\n" << endl;
				}	


				// Display All Acts
				else if (choice == 3)
				{
					if (performance.display())
						cout << "\n\nAll Displayed!\n" << endl;
					else
						cout << "\n\nNo Acts Avialable!\n" << endl;
				}

				// Remove All Acts
				else if (choice == 4)
				{
					if (performance.remove_all())
						cout << "\n\nAll Act(s) Removed!\n" << endl;
					else
						cout << "\n\nList Already Empty!\n" << endl;
				}

				// Search Act
				else if (choice == 5)
				{
					if (performance.search())
						cout << "\n\nAct Displayed!\n" << endl;
					else
						cout << "\n\nAct not in List!\n" << endl;
				}

				// Time Search
				else if (choice == 6)
				{
					if (!performance.show_time())
						cout << "\n\nList Empty or Act not in List!\n" << endl;
				}

				// Display Amount of Seats Avialable
				else if (choice == 7)
				{
					if (!performance.seating_open())
						cout << "\n\nList Empty or Act not in List!\n" << endl;
				}

				// Reserve a Seat
				else if (choice == 8)
				{
					if (!performance.reserve_seat())
						cout << "\n\nList Empty or Act not in List!\n" << endl;
				}

				// Show Act of a group
				else if (choice == 9)
				{
					if (!performance.show_act())
						cout << "\n\nList Empty or Act not in List!\n" << endl;
				}

				// ID Check
				else if (choice == 10)
				{
					if (performance.id_check())
						cout << "\n\nID in List!\n" << endl;
					else
						cout << "\n\nID Not in List!\n" << endl;
				}
			} while (choice != 11);
		}

		// Food Menu
		else if (choice == 2)
		{
			// Loop to stay in Food menu until quit
			do {
				choice = menu.food_menu();

				/* Based off Choice */

				// Insert Food
				if (choice == 1)
				{
					if (eat.insert())
						cout << "\n\nFood Added!\n" << endl;
					else
						cout << "\n\nError Adding Food\n" << endl;
				}

				// Remove Single Food
				if (choice == 2)
				{
					if (eat.remove())
						cout << "\n\nFood Removed!\n" << endl;
					else
						cout << "\n\nList is Empty!\n" << endl;
				}

				// Displaying All Food
				else if (choice == 3)
				{
					if (eat.display())
						cout << "\n\nAll Food Displayed!\n" << endl;
					else
						cout << "\n\nList is Empty!\n" << endl;
				}

				// Remove All foods
				else if (choice == 4)
				{
					if (eat.remove_all())
						cout << "\n\nAll Foods Removed!\n" << endl;
					else
						cout << "\n\nList Already Empty!\n" << endl;
				}

				// Search for Food
				else if (choice == 5)
				{
					if (eat.search())
						cout << "\n\nFood Displayed!\n" << endl;
					else
						cout << "\n\nList Empty or Food not in List!\n" << endl;
				}

				// Buy Food
				else if (choice == 6)
				{
					if (!eat.buy_food())
						cout << "\n\nList Empty or Food not in List!\n" << endl;
				}

				// Show all in price range
				else if (choice == 7)
				{
					if (!eat.range())
						cout << "\n\nList Empty or No food in Price Range!\n" << endl;
				}

				// Show All Gluten Free Options
				else if (choice == 8)
				{
					if (!eat.gluten_display())
						cout << "\n\nList Empty or No Gluten Free Options!\n" << endl;
				}

				// ID Check
				else if (choice == 9)
				{
					if (eat.id_check())
						cout << "\n\nID in List!\n" << endl;
					else
						cout << "\n\nID Not in List!\n" << endl;
				}
			}while (choice != 10);
		}

		// Parking lot Menu
		else if (choice == 3)
		{
			// Loop to stay in parking lot menu
			do {
				choice = menu.lot_menu();

				/* Based off Choice */

				// Insert new Spot
				if (choice == 1)
				{
					// Add to Back
					parking.emplace_back();

					// Set Data
					if (parking.back().set_data())
						cout << "\n\nParking Space Added!\n" << endl;
					else 
						cout << "\n\nError Adding Parking Spot!\n" << endl;
				}

				// Remove Single
				else if (choice == 2)
				{
					if (parking.empty())
						cout << "\n\nList Empty\n" << endl;
					else
					{
						cout << "\n\nEnter Lot Name to Search. Check Spelling!!\nEnter: ";
						getline(cin, find);

						// Make all Upper case
						for (char &c : find)
							c = toupper(c);

						// Find in vector list
						for (lot & space : parking)
						{
							if (space.name_compare(find))
							{
								flag = true;
								break;
							}
							++i;
						}

						// Delete if found
						if (flag)
						{
							parking.erase(parking.begin() + i);
							cout << "\n\nLot Earased!\n" << endl;
						}
						else
							cout << "\n\nLot not in List!\n" << endl;

						// Reset
						flag = false;
						i = 0;
					}
				}
			
				// Display All Spaces
				else if (choice == 3)
				{
					if (parking.empty())
						cout << "\n\nList Empty!\n" << endl;
					else
					{
						// Display Everything in Vector
						for (lot & space : parking)
						{
							// If Display Fails
							if (!space.display())
								break;
							cout << "--------------------------------------";
						}
						cout << "\n\nAll Spaces Displayed!\n" << endl;
					}
				}

				// Remove All
				else if (choice == 4)
				{
					parking.clear();
					cout << "\n\nList Empty!\n" << endl;
				}

				// Search Lot
				else if (choice == 5)
				{
					if (parking.empty())
						cout << "\n\nList Empty!\n" << endl;
					else
					{
						cout << "\n\nEnter Lot Name to Search. Check Spelling!!\nEnter: ";
						getline(cin, find);

						// Make all Upper case
						for (char &c : find)
							c = toupper(c);

						// Find in vector list
						for (lot & space : parking)
						{
							if (space.name_compare(find))
							{
								flag = true;
								break;
							}
							++i;
						}

						// Display if found
						if (flag)
						{
							if (parking[i].display())
								cout << "\n\nLot Displayed!\n" << endl;
							else 
								cout << "\n\nError Displaying!\n" << endl;
						}

						// Not Found
						else
							cout << "\n\nLot not in List!\n" << endl;

						// Reset
						flag = false;
						i = 0;
					}
				}		

				// Display All open Spaces
				else if (choice == 6)
				{
					if (parking.empty())
						cout << "\n\nList Empty!\n" << endl;
					else
					{
						// Display Every Open Space
						for (lot & space : parking)
						{
							if (space.is_open())
							{
								if (!space.display())
									break; // If Display fails
								cout << "--------------------------------------";
								++i;
							}
						}

						// Never Displayed an Open Spot
						if (!i)
							cout << "\n\nNo Open Spots Avialable!\n" << endl;
					}
					// Reset
					i = 0;
				}

				// Reserve a Spot
				else if (choice == 7)
				{
					if (parking.empty())
						cout << "\n\nList Empty!\n" << endl;
					else
					{
						cout << "\n\nEnter Lot Name to Search. Check Spelling!!\nEnter: ";
						getline(cin, find);

						// Make all Upper case
						for (char &c : find)
							c = toupper(c);

						// Find in vector list
						for (lot & space : parking)
						{
							if (space.name_compare(find))
							{
								flag = true;
								break;
							}
							++i;
						}

						// Reserve if found
						if (flag)
						{
							if (parking[i].reserve())
								cout << "\n\nLot Reserved!\n" << endl;
							else 
								cout << "\n\nLot Not Open!\n" << endl;
						}
						else
							cout << "\n\nLot not in List!\n" << endl;

						// Reset
						flag = false;
						i = 0;
					}
				}

				// Show All Handicap Spots
				else if (choice == 8)
				{
					if (parking.empty())
						cout << "\n\nList Empty!\n" << endl;
					else
					{
						// Display Every Handicap Spot
						for (lot & space : parking)
						{
							if (space.handicap_open())
							{
								if (!space.display())
									break; // If Display fails
								cout << "--------------------------------------";
								++i;
							}
						}
						if (!i)
							cout << "\n\nNo Handicap Spots Avialable!\n" << endl;
					}
					// Reset
					i = 0;
				}

				// ID Check
				else if (choice == 9)
				{
					if (parking.empty())
						cout << "\n\nList Empty!\n" << endl;
					else
					{
						// Get ID to compare to
						cout << "\n\nEnter ID to Check: ";
						cin >> id; cin.ignore(100, '\n');

						// Check for ID in every lot
						for (lot & space : parking)
						{
							if (space.valid_id(id))
							{
								cout << "\n\nID in List!\n" << endl;
								++i;

								// Break if you Found at least 1
								break;
							}
						}
						// Never Displayed a Spot
						if (!i)
							cout << "\n\nID not in List!\n" << endl;
					}
					// Reset
					i = 0;
				}
			}while (choice != 10);
		}

		// Quits
		else
			cout << "\n\n\n\nHave a Nice Festival! See You Soon!\n" << endl;


	}while (choice != 4);	

	return 0;
}
