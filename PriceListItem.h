//***********************
//Nathan Marcos (Section 8)
//Cubi Decastro (Section 4)
//CPSC 131
//Project 1
//***********************

#pragma once
#include <string>
#include <stdexcept>
#include "PriceListItem.h"

using namespace std;

//Description for each function in the .cpp file

class PriceList {
public:

	void createPriceListFromDatafile(string filename);
	void addEntry(string itemName, string code, double price, bool taxable);
	bool isValid(string code) const;
	PriceListItem getItem(string code) const;

	PriceList::PriceList();
	PriceList::PriceList(const PriceList &priceList);
	PriceList& PriceList::operator=(const PriceList& priceList);

private:
	PriceListItem *list;
	int index;
};
