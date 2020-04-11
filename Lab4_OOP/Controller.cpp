#include "Controller.h"
#include <string>
#include <iostream>

using namespace std;


Controller::Controller() {
	Repository _repo;
	this->repo = _repo;
}


Controller::Controller(Repository _repo) : repo(_repo) {

}


void Controller::printRepo() const {
	for (std::size_t i = 0; i < repo.getSize(); ++i)
		cout << repo.getDrug_byIndex(i).toString();
	cout << endl << endl;
}


void Controller::amount_s_than(double x) const {
	cout << "\nDrugs which have a smaller quantity than " << x << " are:\n";
	for (std::size_t i = 0; i < repo.getSize(); ++i)
		if (repo.getDrug_byIndex(i).getQuantity() < x)
			cout << repo.getDrug_byIndex(i).toString();
	cout << endl << endl;
}


void Controller::strFind(std::string substr) {
	if (substr == "") { 
		cout << "\nSubstring was empty, this is the list with all the drugs:\n";
		repo.sortByName();
		this->printRepo();
	}
	else { 
		cout << "\nThe drugs which contain '" << substr << "' will be shown:\n";
		for (std::size_t i = 0; i < repo.getSize(); ++i)
			if (repo.getDrug_byIndex(i).getName().find(substr) != string::npos)
				cout << repo.getDrug_byIndex(i).toString();
		cout << endl << endl;
	}
}


void Controller::groupPrice() {
	cout << "\nThese are the drugs, grouped by price :\n";
	repo.sortByPrice();
	this->printRepo();
}