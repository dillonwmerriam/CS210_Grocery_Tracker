#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class GroceryTracker {
public:
	//Create vector of all items in file
	vector<string> GetItemList();

	//Create vector of all unique items in file
	vector<string> GetUniqueItems(vector<string> allItems);

	//Create map of item:quantity
	map<string, int> GetItemQuantity(vector<string> allItems, vector<string> uniqueItems);

	//Print name of item followed by quantity in digits
	void PrintInventoryNumber(map<string, int> itemsAndQuantity);

	//Print name of item followed by quantity in asterisks (*)
	void PrintInventoryChar(map<string, int> itemsAndQuantity);


	//Vector of all items in list (with duplicates)
	vector<string> allItems;
	//Vector of all unique items in list (no duplicates)
	vector<string> uniqueItems;
	//Map of unique items and their quantity from list
	map<string, int> itemsAndQuantity;
private:
	//Item from list
	string item;
	//Quantity of item
	int quantity;

};