/*
Dillon Merriam
10/05/2023

CS210 Project 3: Grocery Tracker

Reads a .txt file containing a list of grocery items,
Outputs how many times each unique item appears in list
which can be considered the store's "stock and inventory"
*/


#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "GroceryTracker.h";

using namespace std;

int main() {
	//Create object "itemList" from Class "GroceryTracker" 
	GroceryTracker itemList;

	//Create vector of all items in file
	itemList.GetItemList();

	//Create vector of all unique items in file
	itemList.GetUniqueItems(itemList.allItems);

	//Create map of item:quantity from comparing how many of each element in vector $uniqueItems is present in vector $itemList
	itemList.GetItemQuantity(itemList.allItems, itemList.uniqueItems);

	//Print name of item followed by quantity in digits
	itemList.PrintInventoryNumber(itemList.itemsAndQuantity);

	//Print name of item followed by quantity in asterisks (*)
	itemList.PrintInventoryChar(itemList.itemsAndQuantity);
	return 0;
}


/*
*
  OVERVIEW:
*
  Create a vector of all unique items in grocery store
*
  Iterate over each item in new vector and count how many time it occurs in all grocery store items
* and assign those counts to their respective variables (ie: numApples = 5)

* Print list of all items with their quantity in numbers #.

* Print list of all items with their quantity in asterisks
------------------------------------------------------------------------------------------------------------------------------------------
* Function GetItemQuantity

*	  Read data from Input_File and store each item in a single vector

*	  Iterate over itemsVector to get all unique items and store them in uniqueItemsVector

*	  Nested FOR loop: count how many times each element[i] of uniqueItemsVector == element[j] of itemsVector
	  and store counts in variable
*
	  On each $i loop, create a new variable to create a map (itemName : itemCount)
*

*
  Function printGroceryStock
*
	  LOOP: cout << uniqueItemsVector[i] << " " << itemsMap[ uniqueItemsVector[i] ] << endl;
*/