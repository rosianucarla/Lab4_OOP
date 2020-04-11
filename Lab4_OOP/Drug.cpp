#include "Drug.h"
#include <exception>

using namespace std;

Drug::Drug(std::string name, double concentration, int quantity, double price)
{
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




void Drug::setQuantity(int _quantity)
{ 
	this->quantity = _quantity;
}

void Drug::setName(std::string _name)
{
	this->name = _name;
}

void Drug::setConcentration(double _concentration)
{
	this->concentration = _concentration;
}

void Drug::setPrice(double _price)
{
	this->price = _price;
}

bool operator==(const Drug& d1, const Drug& d2)
{
	return (d1.name == d2.name && d1.concentration == d2.concentration);
}
