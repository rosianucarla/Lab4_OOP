#include "Repository.h"
#include <algorithm>
using namespace std;

void Repository::add_drug(Drug _drug)
{
	lastOperation = "add";
	lastDrug = _drug;
	bool found = false;
	for(std::size_t i=0;i<drug.size();i++)
		if (drug[i] == _drug) {
			drug[i].setQuantity(drug[i].getQuantity() + _drug.getQuantity());
			found = true;
			break;
			
		}
	if (found == false)
		drug.push_back(_drug);
}

void Repository::delete_drug(Drug _drug)
{
	lastOperation = "delete";
	lastDrug = _drug;
	for (std::size_t i = 0; i < drug.size(); i++) {
		if (drug[i] == _drug && _drug.getQuantity() == 1 || drug[i].getQuantity() - _drug.getQuantity() == 0) {
			drug.erase(drug.begin() + i);
			break;
		}
		else {
			drug[i].setQuantity(drug[i].getQuantity() - _drug.getQuantity());
			break;
		}
	}
}
