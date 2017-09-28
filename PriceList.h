//***********************
//Nathan Marcos (Section 8)
//Cubi Decastro (Section 4)
//CPSC 131
//Project 1
//***********************

#pragma once
#include <string>

using namespace std;

//Description for each function in the .cpp file

class PriceListItem {
public:
	PriceListItem();
	PriceListItem(const string &itemName, const string &code, double price, bool taxable);
	string getItemName();
	string getCode();
	double getPrice();
	bool isTaxable();
	void PriceListItem::setPrice(double billPrice);

private:
	string _itemName;
	string _code;
	double _price;
	bool _taxable;
};
