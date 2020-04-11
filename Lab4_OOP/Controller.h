#pragma once
#include "Repository.h"
#include <string>

class Controller {
public:
	Repository repo;
public:
	// Default constructor
	Controller();

	// Constructor
	Controller(Repository repo);

	// Prints the list with medications
	void printRepo() const;

	// Shows only the medications, which have the amount smaller than x
	void amount_s_than(double x) const;

	// Shows only the medications, which contain the substring "substring", sorted after name of the medication
	void strFind(std::string substring);

	// Shows the list with medications grouped by price
	void groupPrice();
};