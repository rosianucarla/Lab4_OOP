#include "Repository.h"
#include <algorithm>
using namespace std;

/// <summary>	Adds a drug. </summary>
///
/// <remarks>	Administrator, 4/10/2020. </remarks>
///
/// <param name="_drug">	The drug. </param>

void Repository::add_drug(Drug _drug)
{
	lastOperation = "add";
	lastDrug = _drug;
	bool found = false;
	for(std::size_t i=0;i<drugs.size();i++)
		if (drugs[i] == _drug) {
			drugs[i].setQuantity(drugs[i].getQuantity() + _drug.getQuantity());
			found = true;
			break;
			
		}
	if (found == false)
		drugs.push_back(_drug);
}

/// <summary>	Deletes the drug described by _drug. </summary>
///
/// <remarks>	Administrator, 4/10/2020. </remarks>
///
/// <param name="_drug">	The drug. </param>

void Repository::delete_drug(Drug _drug)
{
	lastOperation = "delete";
	lastDrug = _drug;
	for (std::size_t i = 0; i < drugs.size(); i++) {
		if (drugs[i] == _drug && _drug.getQuantity() == 1 || drugs[i].getQuantity() - _drug.getQuantity() == 0) {
			drugs.erase(drugs.begin() + i);
			break;
		}
		else {
			drugs[i].setQuantity(drugs[i].getQuantity() - _drug.getQuantity());
			break;
		}
	}
}

/// <summary>	Edit drug. </summary>
///
/// <remarks>	Administrator, 4/10/2020. </remarks>
///
/// <param name="_drug">  	The drug. </param>
/// <param name="newDrug">	The new drug. </param>

void Repository::edit_drug(Drug _drug, Drug newDrug)
{
	lastOperation = "edit";
	lastDrug = _drug;
	for(std::size_t i=0;i<drugs.size();++i)
		if (drugs[i] == _drug) {
			drugs[i].setName(newDrug.getName());
			drugs[i].setConcentration(newDrug.getConcentration());
			drugs[i].setPrice(newDrug.getPrice());
			drugs[i].setQuantity(newDrug.getQuantity());
		}
}

/// <summary>	Undoes this.  </summary>
///
/// <remarks>	Administrator, 4/10/2020. </remarks>

void Repository::undo()
{
	if (lastOperation == "add") {
		delete_drug(lastDrug);
		lastOperation = "";
		lastUndo = "delete";
	}
	if (lastOperation == "delete") {
		add_drug(lastDrug);
		lastOperation = "";
		lastUndo = "add";
	}
	if (lastOperation == "edit") {
		edit_drug(newDrug, lastDrug);
		lastOperation = "";
		lastUndo = "edit";
	}
}

/// <summary>	Redoes this.  </summary>
///
/// <remarks>	Administrator, 4/10/2020. </remarks>

void Repository::redo()
{
	if (lastUndo == "add") {
		delete_drug(lastDrug);
		lastOperation = "";
		lastUndo = "";
	}
	if (lastUndo == "delete") {
		add_drug(lastDrug);
		lastOperation = "";
		lastUndo = "";
	}
	if (lastUndo == "edit") {
		edit_drug(newDrug,lastDrug);
		lastOperation = "";
		lastUndo = "";
	}
	
}

std::vector<Drug> Repository::getDrugs() const
{
	return this->drugs;
}

Drug Repository::getDrug_byIndex(int index) const
{
	return this->drugs[index];
}

double Repository::getSize() const
{
	return this->drugs.size();
}

bool compareName(Drug d1, Drug d2) {
	return d1.getName() < d2.getName();
}

void Repository::sortByName()
{
	sort(drugs.begin(), drugs.end(), compareName);
}

bool comparePrice(Drug d1, Drug d2) {
	return d1.getPrice() < d2.getPrice();

}

void Repository::sortByPrice(){
	sort(drugs.begin(), drugs.end(), comparePrice);
}


