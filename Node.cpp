/* Abe Busschau -- busschau@pdx.edu -- Program #1
 *
 * 10/17/25
 *
 * This program will help vendors plan a festival. More tuned for the vendors
 * of Entertainment, Food, and Parking. It will have a customer Interace and a vendor interface
 *
 * This file shows the implementation of my node classes. Both for cnode and lnode
*/

#include "CLL_LLL.h"

/* CLL NODE */

// Default Constructor
cnode::cnode(): next(nullptr) {}

// Arguement Constructer
cnode::cnode(const stage & source): stage(source), next(nullptr) {}

// Set Next Node
void cnode::set_next(cnode *& next)
{
	this->next = next;
}

// Get Next Node
cnode *& cnode::get_next()
{
	return next;
}


/* LLL NODE */

// Default Constructor
lnode::lnode(): next(nullptr) {}

// Constructer
lnode::lnode(const food & source): food(source), next(nullptr) {}

// Set Next Node
void lnode::set_next(lnode *& next)
{
	this->next = next;
}

// Get Next Node
lnode *& lnode::get_next()
{
	return next;
}
