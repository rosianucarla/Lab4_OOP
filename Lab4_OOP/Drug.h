#pragma once
#include <string>

/// <summary>	Class storing information about a drug </summary>
///
/// <remarks>	Administrator, 4/10/2020. </remarks>

class Drug
{
private:
	std::string name;
	double concentration;
	int quantity;
	double price;

public:

	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <param name="name">		   	The name. </param>
	/// <param name="concetration">	The concetration. </param>
	/// <param name="quantity">	   	The quantity. </param>
	/// <param name="price">	   	The price. </param>

	Drug(std::string name, double concetration, int quantity, double price);

	/// <summary>	Gets the name. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <returns>	The name. </returns>

	std::string getName();

	/// <summary>	Gets the concentration. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <returns>	The concentration. </returns>

	double getConcentration();

	/// <summary>	Gets the quantity. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <returns>	The quantity. </returns>

	int getQuantity();

	/// <summary>	Gets the price. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <returns>	The price. </returns>

	double getPrice();

	/// <summary>	Convert this  into a string representation
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <returns>	A std::string that represents this. </returns>

	std::string toString();

	/// <summary>	Addition assignment operator. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <param name="quantity">	The quantity. </param>
	///
	/// <returns>	The result of the operation. </returns>

	Drug& operator+=(int quantity);

	/// <summary>	Subtraction assignment operator. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <param name="quantity">	The quantity. </param>
	///
	/// <returns>	The result of the operation. </returns>

	Drug& operator-=(int quantity);

	/// <summary>	Equality operator. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <param name="d1">	The first instance to compare. </param>
	/// <param name="d2">	The second instance to compare. </param>
	///
	/// <returns>	True if the parameters are considered equivalent. </returns>

	friend bool operator ==(const Drug& d1, const Drug& d2);

	/// <summary>	Sets a quantity. </summary>
	///
	/// <remarks>	Administrator, 4/10/2020. </remarks>
	///
	/// <param name="_quantity">	The quantity. </param>

	void setQuantity(double _quantity);



};

