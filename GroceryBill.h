//***********************
//Nathan Marcos (Section 8)
//Cubi Decastro (Section 4)
//CPSC 131
//Project 1
//***********************

#pragma once

#include "PriceList.h"

//Description for each function in the .cpp file

class GroceryBill {
public:
	GroceryBill(const PriceList *priceList, double taxRate);
	void scanItem(string scanCode, double quantity);
	void scanItemsFromFile(string filename);
	double getTotal();
	void printBill();

private:
	const PriceList *pl;
	PriceListItem *bill;
	double _taxRate;
	int billIndex;
	double total;
};
