//***********************
//Nathan Marcos (Section 8)
//Cubi Decastro (Section 4)
//CPSC 131
//Project 1
//***********************

#include "PriceListItem.h"

//Constructor for a PriceListItem class object
PriceListItem::PriceListItem(const string &itemName, const string &code, double price, bool taxable) {
	_itemName = itemName;
	_code = code;
	_price = price;
	_taxable = taxable;
}

//Default constructor for a PriceListItem class object
PriceListItem::PriceListItem() {
	_itemName = " ";
	_code = " ";
	_price = 0;
	_taxable = false;
}

//Returns the item name
string PriceListItem::getItemName() {
	return _itemName;
}

//Returns the item code
string PriceListItem::getCode() {
	return _code;
}

//Returns the item price
double PriceListItem::getPrice() {
	return _price;
}

//Returns true if the item is taxable and false if the item is not taxable
bool PriceListItem::isTaxable() {
	return _taxable;
}

//Sets the price of the item
void PriceListItem::setPrice(double billPrice) {
	_price = billPrice;
}
