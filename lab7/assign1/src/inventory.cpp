

#include "inventory.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;



	Inventory::Inventory() 
	{

	}

	/* Add an item to the inventory with the given name and amount. */
	void Inventory::addItem(string str, int num)
	{
		if (getNumItems(str) > 0)
		{
			for (unsigned int i = 0; i < this->size(); i++)
			{
				if (this->at(i).name == str)
				{
					this->at(i).amount += num;
					break;
				}
			}


		}
		else
		{this->push_back(Item(str, num));}
	}
	
	/* Remove all items with this name from the inventory 
	   while preserving the order of other items in the inventory.*/
	void Inventory::removeItem(string str)
	{
		for (unsigned int i = 0; i < this->size(); i++)
		{
			if (this->at(i).name == str)
			{
				this->erase(this->begin() + i);
			}
		}
	}
	/* Return the number of items with this name from the inventory. */
	int Inventory :: getNumItems(string str)
	{
		 int count = 0;
		for (unsigned int i = 0; i < this->size(); i++)
		{
			if (this->at(i).name == str)
			{
				count+= this->at(i).amount;
			}
		}
		return count;
	}

	/* Print all the items in this format:
		name amount
		name amount
		name amount
	*/
	void Inventory::printAllItems()
	
	{
		for (unsigned int i = 0; i < this->size(); i++)
		{
			cout << this->at(i).name << " " << this->at(i).amount << endl;
		}

	}