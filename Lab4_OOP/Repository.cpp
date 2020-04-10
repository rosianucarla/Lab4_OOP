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
	for(std::size_t i=0;i<drug.size();i++)
		if (drug[i] == _drug) {
			drug[i].setQuantity(drug[i].getQuantity() + _drug.getQuantity());
			found = true;
			break;
			
		}
	if (found == false)
		drug.push_back(_drug);
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
	for(std::size_t i=0;i<drug.size();++i)
		if (drug[i] == _drug) {
			drug[i].setName(newDrug.getName());
			drug[i].setConcentration(newDrug.getConcentration());
			drug[i].setPrice(newDrug.getPrice());
			drug[i].setQuantity(newDrug.getQuantity());
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


