#include "order.h"
#include <iostream>

Order::Item::Item(const std::string& n, int c)
: name(n)
, count(c)
{
}

// Constructor
Order::Order()
{
}

// Constructor which allocates one item
Order::Order(const std::string& name)
{
	mItems.push_back(new Item(name, 1));
}

// Copy Constructor - Part 3
Order::Order(const Order &rhs)
{
	for (size_t i = 0; i < rhs.mItems.size(); ++i)
	{
		mItems.push_back(new Item (*rhs.mItems[i]));
	}
}

Order::~Order()
{
	clearOrder();
}

// Prints all items and their amounts.
void Order::displayOrder() const
{
	std::cout << "The current order is: " << std::endl;
	std::cout << "cur size" << mItems.size() << std::endl;

	// Check if empty
	if(mItems.empty())
	{
		std::cout << "Empty" << std::endl;
		return;
	}

	// Display each item and its amount
	for (size_t i = 0; i < mItems.size(); ++i)
	{
		std::cout << mItems[i]->name << " " << mItems[i]->count << std::endl;
	}
}

// Deletes all items in variable ITEMS. - Part 2
void Order::clearOrder()
{
	for (size_t i = 0; i <mItems.size(); i++)
	{
		delete mItems[i];
	}

	mItems.clear();
}

// Assigns Order RHS values to the current Order's values - Part 4
Order& Order::operator=(const Order &rhs)
{
	// Starter code: self-assignment can cause unseen problems. It won't
		// happen in this program, but let's get you in the habit early.
	if(this == &rhs)
		return *this;

	//todo

	clearOrder();	

	for (size_t i = 0; i < rhs.mItems.size(); ++i)
	{
		mItems.push_back(new Item (*rhs.mItems[i]));
	}

	std::cout << "in assignment" << mItems.size() << std::endl;	

	
		return *this;
}

/* 
Part 4
This operator should create a new Order that represents the
combined outcome of the current Order and the Order passed in via
parameter.
Note: It should not directly modify the current Order, but return
a copy of the combined Order instead. 
*/
Order Order::operator+(const Order &rhs) const
{
	// Starter code: operator+ should not modify THIS, so we make a copy
	Order result(*this);

	
	
	// TODO


	unsigned int counts = 0;

	for (unsigned int i = 0; i < rhs.mItems.size(); i++)
	{
		for (unsigned int x = 0; x < result.mItems.size(); x++)
		{
			if (result.mItems[x]->name == rhs.mItems[i]->name)
			{
				result.mItems[x]->count += rhs.mItems[i]->count;

				counts++;
			}
		}

		if (counts == 0)
		{
			std::cout << "pushing back" << rhs.mItems[i]->name << std::endl;
			result.mItems.push_back(new Item (*rhs.mItems[i]));
		}

		counts = 0;
	}



	std::cout << "size result" << result.mItems.size() << std::endl;



	return result;
}