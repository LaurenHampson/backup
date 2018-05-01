#ifndef BST_H

#define BST_H



#include <iostream>

#include <exception>

#include <cstdlib>

#include <utility>

#include <math.h>



/**

* A templated class for a Node in a search tree. The getters for parent/left/right are virtual so that they

* can be overridden for future kinds of search trees, such as Red Black trees, Splay trees, and AVL trees.

*/

template <typename Key, typename Value>

class Node 

{

public:

	Node(const Key& key, const Value& value, Node<Key, Value>* parent);

	virtual ~Node();



	const std::pair<const Key, Value>& getItem() const;

	std::pair<const Key, Value>& getItem();

	const Key& getKey() const;

	const Value& getValue() const;

	Value& getValue();



	virtual Node<Key, Value>* getParent() const;

	virtual Node<Key, Value>* getLeft() const;

	virtual Node<Key, Value>* getRight() const;

	int getHeight() const;



	void setParent(Node<Key, Value>* parent);

	void setLeft(Node<Key, Value>* left);

	void setRight(Node<Key, Value>* right);

	void setValue(const Value &value);

	void setHeight(int height);



protected:

	std::pair<const Key, Value> mItem;

	Node<Key, Value>* mParent;

	Node<Key, Value>* mLeft;

	Node<Key, Value>* mRight;

	int mHeight;

};



/*

	-----------------------------------------

	Begin implementations for the Node class.

	-----------------------------------------

*/



/**

* Explicit constructor for a node.

*/

template<typename Key, typename Value>

Node<Key, Value>::Node(const Key& key, const Value& value, Node<Key, Value>* parent) 

	: mItem(key, value)

	, mParent(parent)

	, mLeft(nullptr)

	, mRight(nullptr)

	, mHeight(1)

{ 



} 



/**

* Destructor, which does not need to do anything since the pointers inside of a node

* are only used as references to existing nodes. The nodes pointed to by parent/left/right

* are freed within the deleteAll() helper method in the BinarySearchTree.

*/

template<typename Key, typename Value>

Node<Key, Value>::~Node() 

{ 



}



/**

* A const getter for the item.

*/

template<typename Key, typename Value>

const std::pair<const Key, Value>& Node<Key, Value>::getItem() const 

{ 

	return mItem; 

}



/**

* A non-const getter for the item. 

*/

template<typename Key, typename Value>

std::pair<const Key, Value>& Node<Key, Value>::getItem() 

{ 

	return mItem; 

}



/**

* A const getter for the key.

*/

template<typename Key, typename Value>

const Key& Node<Key, Value>::getKey() const 

{ 

	return mItem.first; 

}



/**

* A const getter for the value.

*/

template<typename Key, typename Value>

const Value& Node<Key, Value>::getValue() const 

{ 

	return mItem.second; 

}



/**

* A non-const getter for the value.

*/

template<typename Key, typename Value>

Value& Node<Key, Value>::getValue()

{

	return mItem.second;

}



/**

* An implementation of the virtual function for retreiving the parent.

*/

template<typename Key, typename Value>

Node<Key, Value>* Node<Key, Value>::getParent() const 

{ 

	return mParent; 

}



/**

* An implementation of the virtual function for retreiving the left child.

*/

template<typename Key, typename Value>

Node<Key, Value>* Node<Key, Value>::getLeft() const 

{ 

	return mLeft; 

}



/**

* An implementation of the virtual function for retreiving the right child. 

*/

template<typename Key, typename Value>

Node<Key, Value>* Node<Key, Value>::getRight() const 

{ 

	return mRight; 

}



/**

* A const getter for the height.

*/

template<typename Key, typename Value>

int Node<Key, Value>::getHeight() const

{

	return mHeight;

}



/**

* A setter for setting the parent of a node.

*/

template<typename Key, typename Value>

void Node<Key, Value>::setParent(Node<Key, Value>* parent) 

{ 

	mParent = parent; 

}



/**

* A setter for setting the left child of a node.

*/

template<typename Key, typename Value>

void Node<Key, Value>::setLeft(Node<Key, Value>* left) 

{ 

	mLeft = left; 

}



/**

* A setter for setting the right child of a node.

*/

template<typename Key, typename Value>

void Node<Key, Value>::setRight(Node<Key, Value>* right) 

{ 

	mRight = right; 

}



/**

* A setter for the value of a node.

*/

template<typename Key, typename Value>

void Node<Key, Value>::setValue(const Value& value) 

{ 

	mItem.second = value; 

}



/**

* A setter for the height of a node.

*/

template<typename Key, typename Value>

void Node<Key, Value>::setHeight(int height) 

{ 

	mHeight = height;

}



/*

	---------------------------------------

	End implementations for the Node class.

	---------------------------------------

*/



/**

* A templated unbalanced binary search tree.

*/

template <typename Key, typename Value>

class BinarySearchTree 

{

	public:

		BinarySearchTree(); //TODO

		virtual ~BinarySearchTree(); //TODO

		int height(); //TODO 

		bool isBalanced(); //TODO 

		virtual void insert(const std::pair<const Key, Value>& keyValuePair); //TODO

		virtual void remove(const Key& key); //TODO

		void clear(); //TODO

		void print() const;



	public:

		/**

		* An internal iterator class for traversing the contents of the BST.

		*/

		class iterator 

		{

			public:

				iterator(Node<Key,Value>* ptr);

				iterator();



				std::pair<const Key, Value>& operator*();

				std::pair<const Key, Value>* operator->();



				bool operator==(const iterator& rhs) const;

				bool operator!=(const iterator& rhs) const;

				iterator& operator=(const iterator& rhs);



				iterator& operator++();



			protected:

				Node<Key, Value>* mCurrent;

		};



	public:

		iterator begin();

		iterator end();

		iterator find(const Key& key) const;



	protected:

		Node<Key, Value>* internalFind(const Key& key) const; //TODO

		Node<Key, Value>* getSmallestNode() const; //TODO

		void printRoot (Node<Key, Value>* root) const;



	protected:

		Node<Key, Value>* mRoot;

};



/*

	---------------------------------------------------------------

	Begin implementations for the BinarySearchTree::iterator class.

	---------------------------------------------------------------

*/



/**

* Explicit constructor that initializes an iterator with a given node pointer.

*/

template<typename Key, typename Value>

BinarySearchTree<Key, Value>::iterator::iterator(Node<Key,Value>* ptr)

	: mCurrent(ptr)

{ 



}



/**

* A default constructor that initializes the iterator to nullptr.

*/

template<typename Key, typename Value>

BinarySearchTree<Key, Value>::iterator::iterator()

	: mCurrent(nullptr)

{ 



}



/**

* Provides access to the item.

*/

template<typename Key, typename Value>

std::pair<const Key, Value>& BinarySearchTree<Key, Value>::iterator::operator*() 

{ 

	return mCurrent->getItem();

}



/**

* Provides access to the address of the item.

*/

template<typename Key, typename Value>

std::pair<const Key, Value>* BinarySearchTree<Key, Value>::iterator::operator->() 

{ 

	return &(mCurrent->getItem()); 

}



/**

* Checks if 'this' iterator's internals have the same value

* as 'rhs'

*/

template<typename Key, typename Value>

bool BinarySearchTree<Key, Value>::iterator::operator==(const BinarySearchTree<Key, Value>::iterator& rhs) const

{

	return this->mCurrent == rhs.mCurrent;

}



/**

* Checks if 'this' iterator's internals have a different value

* as 'rhs'

*/

template<typename Key, typename Value>

bool BinarySearchTree<Key, Value>::iterator::operator!=(const BinarySearchTree<Key, Value>::iterator& rhs) const

{

	return this->mCurrent != rhs.mCurrent;

}



/**

* Sets one iterator equal to another iterator.

*/

template<typename Key, typename Value>

typename BinarySearchTree<Key, Value>::iterator &BinarySearchTree<Key, Value>::iterator::operator=(const BinarySearchTree<Key, Value>::iterator& rhs)

{

	this->mCurrent = rhs.mCurrent;

	return *this;

}



/**

* Advances the iterator's location using an in-order traversal.

*/

template<typename Key, typename Value>

typename BinarySearchTree<Key, Value>::iterator& BinarySearchTree<Key, Value>::iterator::operator++()

{

	if(mCurrent->getRight() != nullptr)

	{

		mCurrent = mCurrent->getRight();

		while(mCurrent->getLeft() != nullptr)

		{

			mCurrent = mCurrent->getLeft();

		}

	}

	else if(mCurrent->getRight() == nullptr)

	{

		Node<Key, Value>* parent = mCurrent->getParent();

		while(parent != nullptr && mCurrent == parent->getRight())

		{

			mCurrent = parent;

			parent = parent->getParent();

		}

		mCurrent = parent;

	}

	return *this;

}



/*

	-------------------------------------------------------------

	End implementations for the BinarySearchTree::iterator class.

	-------------------------------------------------------------

*/



/*

	-----------------------------------------------------

	Begin implementations for the BinarySearchTree class.

	-----------------------------------------------------

*/



/**

* Default constructor for a BinarySearchTree, which sets the root to nullptr.

*/

template<typename Key, typename Value>

BinarySearchTree<Key, Value>::BinarySearchTree() 

{ 

	mRoot = nullptr;

}



template<typename Key, typename Value>

BinarySearchTree<Key, Value>::~BinarySearchTree() 

{ 

	// EDITED

	clear();

}



template<typename Key, typename Value>

void BinarySearchTree<Key, Value>::print() const

{ 

	printRoot(mRoot);

	std::cout << "\n";

}



/**

* Returns an iterator to the "smallest" item in the tree

*/

template<typename Key, typename Value>

typename BinarySearchTree<Key, Value>::iterator BinarySearchTree<Key, Value>::begin()

{

	BinarySearchTree<Key, Value>::iterator begin(getSmallestNode());

	return begin;

}



/**

* Returns an iterator whose value means INVALID

*/

template<typename Key, typename Value>

typename BinarySearchTree<Key, Value>::iterator BinarySearchTree<Key, Value>::end()

{

	BinarySearchTree<Key, Value>::iterator end(nullptr);

	return end;

}



/**

* Returns an iterator to the item with the given key, k

* or the end iterator if k does not exist in the tree

*/

template<typename Key, typename Value>

typename BinarySearchTree<Key, Value>::iterator BinarySearchTree<Key, Value>::find(const Key& key) const 

{

	Node<Key, Value>* curr = internalFind(key);

	BinarySearchTree<Key, Value>::iterator it(curr);

	return it;

}



/**

* An method to return the height of the BST.

*/

//isLeaf**************

template<typename Key, typename Value>

int getMaxHeight(Node<Key, Value>* node)

{

	int rHeight = 0;

	int lHeight = 0;



	if(node->getRight() != NULL)

	{

		rHeight = node->getRight()->getHeight();

	}



	if(node->getLeft() != NULL)

	{

		lHeight = node->getLeft()->getHeight();

	}



	if (rHeight >= lHeight)

	{

		return rHeight;

	}

	else 

	{

		return lHeight;

	}

}

template<typename Key, typename Value>

void heightUpdate(Node<Key, Value>* node, int h)

{

	node->setHeight(h);



	Node<Key, Value>* temp = node->getParent();

	while(temp != NULL)

	{

		temp->setHeight(getMaxHeight(temp)+1);

		temp = temp->getParent();

	}

}



template<typename Key, typename Value>

int BinarySearchTree<Key, Value>::height()

{

	// EDITED

	if(mRoot == nullptr)

	{

		return 0;

	}

	else

	{

		return mRoot->getHeight();

	}

}









/**

* An method to checks if the BST is balanced. This method returns true if and only if the BST is balanced.

*/

template<typename Key, typename Value>

bool BinarySearchTree<Key, Value>::isBalanced()

{

	// EDITED

	return isBalance(mRoot);



}



template<typename Key, typename Value>

bool isBalance(Node<Key, Value>* node_)

{

	if (node_ == nullptr)

	{

		return true;

	}

	

	else if (isBalance(node_->getLeft()) == false)

	{

		return false;

	}	

	else if (isBalance(node_->getRight()) == false)

	{

		return false;

	}

	else

	{

		if ((node_->getLeft()) == nullptr && (node_->getRight()) == nullptr)

		{

			return true;

		}

		else if((node_->getLeft()) == nullptr)

		{

			return ((node_->getRight())->getHeight()<=1);

		}



		else if ((node_->getRight()) == nullptr)

		{

			return ((node_->getLeft())->getHeight()<=1);

			/* code */

		}



		int x = abs((node_->getLeft())->getHeight() - (node_->getRight())->getHeight());



		return (x <= 1);

	}

}



/**

* An insert method to insert into a Binary Search Tree. The tree will not remain balanced when 

* inserting.

*/

/////*******************************ADD AN UPDATE FOR HEIGHT FOR INSERT IN TREE AND INSERT







template<typename Key, typename Value>

void BinarySearchTree<Key, Value>::insert(const std::pair<const Key, Value>& keyValuePair)

{

	

	if (mRoot == nullptr)

	{

		Node<Key, Value>* temp = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, nullptr);

		

		mRoot = temp;

	

		return;

	}

	

	else

	{

		Node<Key, Value>* prev = mRoot;

		Node<Key, Value>* curr = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, nullptr);



		if (prev->getKey() > keyValuePair.first)

		{

			curr = prev->getLeft();

			

		}

		else if (prev->getKey() < keyValuePair.first )

		{

			curr = prev->getRight();

		

		}





			while(curr != nullptr && (mRoot->getKey() != keyValuePair.first))

			{

				prev = curr;

				if(curr->getKey() == keyValuePair.first)

				{

					return;

				}

				else

				{

					if (prev->getKey() > keyValuePair.first)

					{

						curr = prev->getLeft();

						

					}

					else if (prev->getKey() < keyValuePair.first )

					{

						curr = prev->getRight();

					

					}	

				}

			}





			Node<Key, Value>* pairNode = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, prev);



			if(prev->getKey() > keyValuePair.first)

			{

				 

				prev->setLeft(pairNode);

				

			}

			else if(prev->getKey()<keyValuePair.first)

			{

				prev->setRight(pairNode);

			}





			

			heightUpdate(pairNode, 1);



			return;





	}



		

}



/**

* An remove method to remove a specific key from a Binary Search Tree. The tree may not remain balanced after

* removal.

*/

template<typename Key, typename Value>

Node<Key, Value>* getPredecessor(Node<Key, Value>* node)

{



	Node<Key, Value>* temp1 = node;



	Node<Key, Value>* temp2 = node;



			//Find predecessor

			if (temp1->getRight() != nullptr)

		    {

				temp1 = temp1->getRight();



				while(temp1->getLeft()!= NULL)

				{

					temp1 = temp1->getLeft();

				}

			

			}





			if(temp2->getLeft()!= NULL)

			{

				temp2 = temp2->getLeft();

				while(temp2->getRight()!=NULL)

				{

					temp2 = temp2->getRight();

				}

			}



			if(temp1->getKey() < temp2->getKey() && temp2->getKey() < node->getKey())

			 {

				return temp2;

			 }

			 else //if(temp2->getKey() < temp1->getKey() && temp1->getKey() < node->getKey())

			{

			 	return temp1;

			 }





}







template<typename Key, typename Value>

void removeNode(Node<Key, Value>* node1, Node<Key, Value>* node2, Node<Key, Value>* mRoot)

{if((node1 == NULL)|| ( node2 == NULL) || (node1 = node2))

	{

		return;

	}





	Node<Key, Value>* predParent = node1->getParent();

    Node<Key, Value>* predRight = node1->getRight();

    Node<Key, Value>* predLeft = node1->getLeft();

    Value predVal = node1->getValue();

    int predHeight = node1->getHeight();



    bool predisLeft = false;

	    if(predParent != NULL && (node1 == predParent->getLeft())) 

	    {

	    	predisLeft = true;

	    }



    Node<Key, Value>* tempParent = node2->getParent();



    Node<Key, Value>* tempRight = node2->getRight();



    Node<Key, Value>* tempLeft = node2->getLeft();

    Value tempVal = node2->getValue();

    int tempHeight = node2->getHeight();



    



    node2->setParent(predParent);

    node2->setLeft(predLeft);

    node2->setRight(predRight);

    node2->setValue(predVal);

    node2->setHeight(predHeight);





    node1->setParent(tempParent);

    node1->setLeft(tempLeft);

    node1->setRight(tempRight);

    node1->setValue(tempVal);

    node1->setHeight(tempHeight);





    if(node1->getLeft()!= NULL && !predisLeft)

    {

    	node1->getParent()->setRight(node1->getLeft());

    	node1->getLeft()->setRight(node1->getRight());

    	node1->getLeft()->setParent(node1->getParent());

    	heightUpdate(node1, 0);

    	delete node1;

    	return;

    }



    else if (node1->getLeft() ==NULL && node1->getRight() != NULL && !predisLeft)

    {

    	node1->getParent()->setRight(node1->getRight());

    	node1->getRight()->setLeft(NULL);

    	node1->getRight()->setParent(node1->getParent());

    	heightUpdate(node1,0);

    	delete node1;

    	return;

    }



    else if(node1->getLeft()!= NULL && predisLeft)

    {

    	node1->getParent()->setLeft(node1->getLeft());

    	node1->getLeft()->setRight(node1->getRight());

    	node1->getLeft()->setParent(node1->getParent());

    	heightUpdate(node1, 0);

    	delete node1;

    	return;

    }



    else if (node1->getLeft() ==NULL && node1->getRight() != NULL && predisLeft)

    {

    	node1->getParent()->setLeft(node1->getRight());

    	node1->getRight()->setLeft(NULL);

    	node1->getRight()->setParent(node1->getParent());

    	heightUpdate(node1,0);

    	delete node1;

    	return;

    }

    else if(node1->getLeft() == NULL && node1->getRight() == NULL)

    {

    	if(predisLeft)

    	{

    		node1->getParent()->setLeft(NULL);

    			node1->setParent(NULL);

    		heightUpdate(node1, 0);

    		delete node1;

    		return;

    	}

    	else if(!predisLeft)

    	{

    		node1->getParent()->setRight(NULL);

    		node1->setParent(NULL);

    		heightUpdate(node1, 0);

    		delete node1;

    		return;

    	}

    }



   







}



template<typename Key, typename Value>

void BinarySearchTree<Key, Value>::remove(const Key& key)

{

	// TODO

	//see if key existss

	Node<Key, Value>* temp = internalFind(key);

	if (temp == nullptr)

	{

		return;

	}

//no children

	if (temp->getRight() == nullptr && temp->getLeft() == nullptr)

	{

		if(temp == mRoot)

		{

			delete temp;

			mRoot = NULL;

			//mRoot->setHeight(0);

			return;

		}



		else if (temp->getParent()->getKey()> key)

		{

			temp->getParent()->setLeft(nullptr);

			temp->setParent(nullptr);

			heightUpdate(temp, 0);

			delete temp;

		}

		else

		{

			temp->getParent()->setRight(nullptr);

			temp->setParent(nullptr);

			heightUpdate(temp, 0);

			delete temp;

		}

		return;

	}



//one child

	if (temp->getRight() == nullptr && temp->getLeft() != nullptr)

	{

		if(temp == mRoot)

		{

				mRoot = temp->getLeft();

				mRoot->setParent(nullptr);

			

			delete temp;

			return;

		}



		Node<Key, Value>* rent = temp->getParent();

		temp->getLeft()->setParent(rent);

		if (rent->getKey()> temp->getKey())

		{

				rent->setLeft(temp->getLeft());

		}

		else

		{

				rent->setRight(temp->getLeft());

		}



	

		delete temp;

		return;

	}

	if (temp->getRight() != nullptr && temp->getLeft() == nullptr)

	{



			if(temp == mRoot)

		{

				Node<Key, Value>* rent = nullptr;

				mRoot = temp->getRight();

				mRoot->setParent(rent);

			

			delete temp;

			return;

		}

		Node<Key, Value>* rent = temp->getParent();

		temp->getRight()->setParent(rent);

		if (rent->getKey()> temp->getKey())

		{

				rent->setLeft(temp->getRight());

		}

		else

		{

			rent->setRight(temp->getRight());



		}

		delete temp;

		return;

	}



	if (temp->getRight() != nullptr && temp->getLeft() != nullptr)

	{

		if(temp == mRoot)

		{

				mRoot = temp->getLeft();

				mRoot->setLeft(temp->getLeft()->getLeft());

				temp->getRight()->setParent(mRoot);

				mRoot->setParent(nullptr);

			

			delete temp;

			return;

		}

		

		Node<Key, Value>* predecessor = getPredecessor(temp);



		

		removeNode(predecessor, temp, mRoot);		

		





 }



	return;

	 

}



/**

* A method to remove all contents of the tree and reset the values in the tree 

* for use again.

*/

template<typename Key, typename Value>

void BinarySearchTree<Key, Value>::clear()

{

	clearHelper(mRoot);	

	mRoot = nullptr;

}

template<typename Key, typename Value>

void clearHelper(Node<Key, Value>* node)

{

	if (node == nullptr)

	{

		return;

	}

	// EDITED

	if(node->getLeft() != nullptr) {

        clearHelper(node->getLeft());

    }

    if(node->getRight() != nullptr) {

        clearHelper(node->getRight());

    }





    node->setParent(nullptr);

    node->setRight(nullptr);

    node->setLeft(nullptr);



    delete node;

}

/**

* A helper function to find the smallest node in the tree.

*/



template<typename Key, typename Value>

Node<Key, Value>* BinarySearchTree<Key, Value>::getSmallestNode() const

{

	// EDITED

	Node<Key, Value>* node = mRoot;



	while(node->getLeft()!=nullptr)

	{

		node = node->getLeft();

	}



	return node;





}  



/**

* Helper function to find a node with given key, k and 

* return a pointer to it or nullptr if no item with that key

* exists

*/

template<typename Key, typename Value>

Node<Key, Value>* BinarySearchTree<Key, Value>::internalFind(const Key& key) const 

{

	Node<Key, Value>* temp = mRoot;

	while(temp)

	{

		if (key == temp->getKey())

		{

			return temp;

		}



		else if (key < temp->getKey())

		{

			temp = temp->getLeft();



		}

		else 

		{

			temp = temp->getRight();

		}



	}



	// if key is not found return a nullptr pointer

	return NULL; // should I just return nullptr???	

}



/**

* Helper function to print the tree's contents

*/

template<typename Key, typename Value>

void BinarySearchTree<Key, Value>::printRoot (Node<Key, Value>* root) const

{

	if (root != nullptr)

	{

		std::cout << "[";

		printRoot (root->getLeft());

		std::cout << " (" << root->getKey() << ", " << root->getValue() << ") ";

		printRoot (root->getRight());

		std::cout << "]";

	}

}



/*

	---------------------------------------------------

	End implementations for the BinarySearchTree class.

	---------------------------------------------------

*/



#endif