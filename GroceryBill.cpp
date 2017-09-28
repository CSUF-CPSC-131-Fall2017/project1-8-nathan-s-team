//***********************
//Nathan Marcos (Section 8)
//Cubi Decastro (Section 4)
//CPSC 131
//Project 1
//***********************

#include "GroceryBill.h"
#include <iostream>
#include<fstream>

using namespace std;

//Default constructor for a GroceryBill class obect
GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {
	pl = priceList;
	bill = new PriceListItem[1000];
	billIndex = 0;
	total = 0;
	_taxRate = taxRate / 100;
}

//Scans a code to see if the code is valid and how many items there are
void GroceryBill::scanItem(string scanCode, double quantity) {
	if (pl->isValid(scanCode) == false)
		throw runtime_error("Item not found");
	PriceListItem temp = pl->getItem(scanCode);
	bill[billIndex] = temp;
	bill[billIndex].setPrice(bill[billIndex].getPrice() * quantity);
	if (temp.isTaxable() == true)
	{
		total += (bill[billIndex].getPrice()*_taxRate) + bill[billIndex].getPrice();
	}
	else
	{
		total += bill[billIndex].getPrice();
	}
	billIndex++;
}

// Scan multiple codes and quantities from the given text file
// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from text file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string code;
		double quantity;
		while (myfile >> code >> quantity) {
			scanItem(code, quantity);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
	
}

//Return the total cost of all items scanned
double GroceryBill::getTotal() {
	return total;
}

//Prints out the bill, if an item is taxed and the total
void GroceryBill::printBill() {
	for (int i = 0; i < billIndex; i++)
	{
		char tax = ' ';
		if (bill[i].isTaxable())
		{
			char tax = 'T';
		}
		else
			char tax = ' ';
		cout << bill[i].getItemName() << "\t" << bill[i].getPrice() << tax << endl;
	}
	cout << "Total: " << "\t" << getTotal() << endl;
}
