#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <map>
#include <vector>
#include "GroceryTracker.h"


using namespace std;


vector<string> allItems;
vector<string> uniqueItems;

vector<string> GroceryTracker::GetItemList() {

	//Read from file and push all elements into allItems<vec>
	ifstream myInFile;
	myInFile.open("inputFile.txt");

	//Verify input
	if (!myInFile) {
		cout << "File not found";
	}
	//If no error, push item into vector allItems
	else {
		while (myInFile >> item) {
			allItems.push_back(item);
		}
	}

	return allItems;

}

// Create vector of unique items
vector<string> GroceryTracker::GetUniqueItems(vector<string> allItems) {

	//Iterate over allItems<> to push unique elements into uniqueItems<vec>
	for (int i = 0; i < allItems.size(); i++) {
		string item = allItems[i];
		bool unique = true;
		for (int j = 0; j < uniqueItems.size(); j++) {
			// If item in allItems exists in uniqueItems, unique = false, do not push into uniqueItems
			if (allItems[i] == uniqueItems[j]) {
				unique = false;
			}
		}
		// If item is unique, push into uniqueItems
		if (unique == true) {
			uniqueItems.push_back(allItems[i]);
		}
	}
	return uniqueItems;
}

// Create map of item:quantity and create output file simultaneously
map<string, int> GroceryTracker::GetItemQuantity(vector<string> allItems, vector<string> uniqueItems) {

	ofstream myOutFile;
	myOutFile.open("outputFile.txt");
	int count = 0;
	// LOOP if <uniqueItems[i]> == <allItems[j]> { count++ }
	for (int i = 0; i < uniqueItems.size(); i++) {
		for (int j = 0; j < allItems.size(); j++) {
			if (allItems[j] == uniqueItems[i]) {
				count++;
			}
		}
		tolower(uniqueItems[i][0]);
		itemsAndQuantity.emplace(uniqueItems[i], count);
		myOutFile << uniqueItems[i] << " " << count << endl;
		count = 0;
	}
	myOutFile.close();
	return(itemsAndQuantity);
}

void GroceryTracker::PrintInventoryNumber(map<string, int>) {

	for (int i = 0; i < uniqueItems.size(); i++) {
		string item = uniqueItems[i];
		int quantity = itemsAndQuantity[uniqueItems[i]];

		cout << item << " " << quantity << endl;
	}
	cout << endl;
}

void GroceryTracker::PrintInventoryChar(map<string, int>) {

	for (int i = 0; i < uniqueItems.size(); i++) {
		//make code easier to read, and initialize $asterisks as an empty string to push *'s into
		string item = uniqueItems[i],
			asterisks = "";

		//readability. Can get all quantity values from "itemsAndQuantity" map by using "uniqueItems" vector elements as keys
		int quantity = itemsAndQuantity[uniqueItems[i]];

		//add $quantity amount of asterisks to variable
		for (int i = 0; i < quantity; i++) {
			asterisks += "*";
		}
		cout << item << " " << asterisks << endl;
	}
}