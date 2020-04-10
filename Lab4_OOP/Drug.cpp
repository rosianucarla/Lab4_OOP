#include "Drug.h"
#include <exception>

using namespace std;

Drug::Drug(std::string name, double concetration, int quantity, double price)
{
	if (concetration <= 0)
		throw exception("The concentration must be a positive number");

	if (quantity < 0)
		throw exception("The quantity must be a positive number");

	if (price <= 0)
		throw exception("The prince must be a positive number");

	this->name = name;
	this->concentration = concentration;
	this->quantity = quantity;
	this->price = price;
}

std::string Drug::getName()
{
	return this->name;
}

double Drug::getConcentration()
{
	return this->concentration;
}

int Drug::getQuantity()
{
	return this->quantity;
}

double Drug::getPrice()
{
	return this->price;
}

std::string Drug::toString()
{
	return this->name + " " + std::to_string(this->concentration) + " " +std::to_string(this->quantity) + " " + std::to_string(this->price);
}

Drug& Drug::operator+=(int quantity)
{
	this->quantity += quantity;
	return *this;
}

Drug& Drug::operator-=(int quantity)
{
	if (this->quantity < quantity) {
		throw exception("You can not subtract the provided quantity");
	}
	this->quantity -= quantity;
	return *this;
}


