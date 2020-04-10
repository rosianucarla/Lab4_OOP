#pragma once
#include <vector>
#include "Drug.h"
#include <utility>

/// <summary>	A repository. </summary>
///
/// <remarks>	Administrator, 4/10/2020. </remarks>

class Repository
{
private:
	std::vector <Drug> drugs;
	std::string lastOperation = "";
	std::string lastUndo = "";
	Drug lastDrug = Drug("", 0, 0, 0);
	Drug newDrug = Drug("", 0, 0, 0);

public:

	/// <summary>	Adds a drug. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <param name="drug">	The drug. </param>

	void add_drug(Drug drug);

	/// <summary>	Deletes the drug described by drug. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <param name="drug">	The drug. </param>

	void delete_drug(Drug drug);

	/// <summary>	Edit drug. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <param name="drug">   	The drug. </param>
	/// <param name="newDrug">	The new drug. </param>

	void edit_drug(Drug drug, Drug newDrug);

	/// <summary>	Undoes this.  </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>

	void undo();

	/// <summary>	Redoes this. 
	/// 			
	/// 			 
	///  </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>

	void redo();

	/// <summary>	Gets the drug. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <returns>	The drug. </returns>

	std::vector<Drug> getDrugs() const;

	/// <summary>	Gets drug by index. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <param name="index">	Zero-based index of the. </param>
	///
	/// <returns>	The drug by index. </returns>

	Drug getDrug_byIndex(int index) const;

	/// <summary>	Gets the size. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <returns>	The size. </returns>

	double getSize()const;

	/// <summary>	Sort by name. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>

	void sortByName();

	/// <summary>	Sort by preis. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>

	void sortByPrice();
};

