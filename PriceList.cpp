//***********************
//Nathan Marcos (Section 8)
//Cubi Decastro (Section 4)
//CPSC 131
//Project 1
//***********************

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PriceList.h"
#include "PriceListItem.h"

using namespace std;

//Default constructor for a PriceList class object
PriceList::PriceList()
{
	list = NULL;
	index = 0;
}

//This is the copy constructor which copies the value of one Pricelist class object into another one
PriceList::PriceList(const PriceList &priceList) {

	list = new PriceListItem[1000000];
	index = priceList.index;

	for (int i = 0; i < index; i++)
	{
		list[i] = PriceListItem(priceList.list[i].getItemName(), priceList.list[i].getCode(), priceList.list[i].getPrice(), priceList.list[i].isTaxable());
	}
}

//This is the assignment operator which assigns values to a PriceList class object
PriceList& PriceList::operator=(const PriceList& priceList) {
	if (this != &priceList)
	{
		delete[] list;
		index = priceList.index;
		list = new PriceListItem[1000000];
		for (int i = 0; i < index; i++)
		{
			list[i] = priceList.list[i];
		}
		return(*this);
	}
}

void PriceList::createPriceListFromDatafile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		string code;
		double price;
		bool taxable;
		while (myfile >> name >> code >> price >> taxable) {
			// cout << code << " " << taxable << endl;
			addEntry(name, code, price, taxable);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

//Return true only if the code is valid
bool PriceList::isValid(string code) const {
	for (int i = 0; i < index; i++)
	{
		if (list[i].getCode() == code)
		{
			return true;
		}
	}
	return false;
}

//Return price, item name, taxable? as an ItemPrice object; throw exception if code is not found
PriceListItem PriceList::getItem(string code) const {
	for (int i = 0; i < index; i++)
	{
		if (list[i].getCode() == code)
		{
			return list[i];
		}
	}
	throw runtime_error("Code does not exist");
}

//Add to the price list information about a new item
void PriceList::addEntry(string itemName, string code, double price, bool taxable) {
	if (index == 0)
	{
		list = new PriceListItem[1000000];
	}
	PriceListItem pli = PriceListItem(itemName, code, price, taxable);
	list[index] = pli;
	index++;
}
