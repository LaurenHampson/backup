#ifndef ROTATEBST_H
#define ROTATEBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>
#include <math.h>
#include "bst.h"
/**
* A templated class for a Node in a search tree. The getters for parent/left/right are virtual so that they
* can be overridden for future kinds of search trees, such as Red Black trees, Splay trees, and AVL trees.
*/
template <typename Key, typename Value>
class rotateBST : public BinarySearchTree<Key,Value> // ask about this 
{
public:
	rotateBST();
	~rotateBST();
	bool sameKeys(const rotateBST& t2) const;
	void transform(rotateBST& t2) const;

protected:
	void leftRotate(Node<Key, Value>* r);
	void rightRotate(Node<Key, Value>* r);
};

/*template<typename Key, typename Value>
std::vector<Key> inOrderTraversal(){
	std::vector<Key> list;
	if(!empty())
		inOrderTraversalHelper(list, this->mRoot);
	return list;
}*/




template<typename Key, typename Value>
void inOrderTraversalHelper(std::vector<Key>& list, Node<Key, Value>* node){
	// TODO
	// implement in order
	   if(node->getLeft() != NULL) {
        inOrderTraversalHelper(list, node->getLeft());
    }
     list.push_back(node->getKey());
    if(node->getRight() != NULL) {
        inOrderTraversalHelper(list, node->getRight());
    }
    //list.push_back(node->val);
}


template<typename Key, typename Value>
bool rotateBST::sameKeys(const rotateBST& t2) const
{
	std::vector<Key> bstList;
	if(!empty())
		inOrderTraversalHelper(bstList, this->mRoot);
	std::vector<Key> rotList;
	if(!empty())
		inOrderTraversalHelper(rotList, t2->mRoot);
	if(bstList.size()!=rotList.size())
	{
		return false;
	}

	for(int i = 0; i < bstList.size(); i++)
	{
		if (bstList[i] != rotList[i])
		{
			return false;
		}
	}

	return true;


}

void transformHelper(Node<Key,Value>* root, Node<Key, Value>* goal) 
{
	if(root == NULL)
	{
		return;
	}
	while(root != goal)
	{
		leftRotate(root);
	}

	transformHelper(root.getLeft(); goal.getLeft());

	transformHelper(root.getRight(); goal.getRight());
}

template<typename Key, typename Value>
void rotateBST::transform(rotateBST& t2) const
{
	if(this.sameKeys(t2) == false)
	{
		return;
	}
	else
	{
		while(t2->mRoot.getLeft()!= NULL)
		{
			rightRotate(t2->mRoot);
		}

		while(this->mRoot != t2->mRoot)
		{
			leftRotate(t2->mRoot);
		}
	}


	this.transformHelper(t2->mRoot.getLeft(), this->mRoot.getLeft());
		this.transformHelper(t2->mRoot.getRight(), this->mRoot.getRight());



	//Recursively do rotations on the left child 
	//and the right child until they match the node at that position of this.
}


//make sure that it is updating the root correctly
template<typename Key, typename Value>
void rotateBST::leftRotate(Node<Key, Value>* r)
{
	if (r->getRight()==NULL)
	{
		return;
	}
	else
	{
		Node<Key, Value>* pred = NULL;
		if (r->getLeft() != NULL)
		{
			pred = r->getLeft();
		}
			r.setParent(r->getParent().getParent());
		

		r->setLeft(r->getParent());
		r->getLeft().setRight(pred);
		r->getLeft().getRight().setParent(r->getLeft());
		r->setParent(r->getLeft().getParent());
		r->getLeft().setParent(r);

		return;
	}
}


template<typename Key, typename Value>
void rotateBST::rightRotate(Node<Key, Value>* r)
{
	// check if root
	//if root parent = NULL set new root
	if (r->getLeft()==NULL)
	{
		return;
	}
	else
	{
		Node<Key, Value>* temp = r->getLeft();
		r->setLeft(temp->getRight());


		//Node<Key, Value>* pred = NULL;

		if (r->getLeft() != NULL)
		{
			r->getLeft()->setParent(r)
			//pred = r->getRight();
		}

		temp->setRight(r);

		temp->setParent(r->getParent());
		r->setParent(temp);

		if(temp->getParent() != NULL)
		{
			Node<Key, Value>* rent = temp->getParent();
			if(temp->getKey()< rent-> getKey())
			{
				rent->setLeft(temp);
			}
			else
			{
				rent->setRight(temp);
			}
		}
		else
		{
			mRoot = temp;
			//figure out how to do this
		}


			//r.setParent(r->getParent().getParent());
		
		// r->setRight(r->getParent());
		// r->getRight().setLeft(pred);
		// r->getRight().getLeft().setParent(r->getRight());
		// r->setParent(r->getRight().getParent());
		// r->getRight().setParent(r);

		return;

		//check to see if it has any right children as well
				//move it to the left child of the parent of the node that you are calling rotate on

		/*else
		{
			r->setRight(r->getParent());
			r->setParent(NULL);
			r->getRight().setParent(r);
			r->getRight().setLeft(NULL);
			r->getRight().setRight(NULL);
		}*/
	}
}





#endif



	
// template <typename Key, typename Value>
// Node<Key, Value>* insertInTree(Node<Key, Value>* node, const Key& key) {
// 	// TODO
// 	// Feel free to modify any return values or parameters.
// 	// You can also choose to do your work in insert() instead.
// //left right val
	
// 		if (node == NULL)
// 	{
// 		Node<Key, Value>* tempNode = new Node<Key, Value>*(key, );
// 		tempNode->val = value;
// 		tempNode->left = NULL;
// 		tempNode->right= NULL;
// 		node = tempNode;

// 		return node;
// 	}

// 		if (node->getKey() > key)
// 		{
// 			node->getLeft() = insertInTree(node->getLeft(), key);
// 			node->getLeft()->setHeight(node->getLeft()->getHeight() + 1);


// 		}
// 		else if (node->getKey() < key )
// 		{
// 			node->getRight() = insertInTree(node->getRight(), key);
// 			node->getRight()->setHeight(node->getRight()->getHeight() + 1);

		
// 		}
		

// 			return node;

// 	//return new Item<T>();
// }


#ifndef ROTATEBST_H
#define ROTATEBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>
#include <math.h>
#include <vector>
#include "bst.h"
/**
* A templated class for a Node in a search tree. The getters for parent/left/right are virtual so that they
* can be overridden for future kinds of search trees, such as Red Black trees, Splay trees, and AVL trees.
*/

// template <typename Key, typename Value>
// class Node 
// {
// public:
// 	Node(const Key& key, const Value& value, Node<Key, Value>* parent);
// 	virtual ~Node();

// 	const std::pair<const Key, Value>& getItem() const;
// 	std::pair<const Key, Value>& getItem();
// 	const Key& getKey() const;
// 	const Value& getValue() const;
// 	Value& getValue();

// 	virtual Node<Key, Value>* getParent() const;
// 	virtual Node<Key, Value>* getLeft() const;
// 	virtual Node<Key, Value>* getRight() const;
// 	int getHeight() const;

// 	void setParent(Node<Key, Value>* parent);
// 	void setLeft(Node<Key, Value>* left);
// 	void setRight(Node<Key, Value>* right);
// 	void setValue(const Value &value);
// 	void setHeight(int height);

// protected:
// 	std::pair<const Key, Value> mItem;
// 	Node<Key, Value>* mParent;
// 	Node<Key, Value>* mLeft;
// 	Node<Key, Value>* mRight;
// 	int mHeight;
// };

// template <typename Key, typename Value>
// class BinarySearchTree 
// {
// 	public:
// 		BinarySearchTree(); //TODO
// 		virtual ~BinarySearchTree(); //TODO
// 		int height(); //TODO 
// 		bool isBalanced(); //TODO 
// 		virtual void insert(const std::pair<const Key, Value>& keyValuePair); //TODO
// 		virtual void remove(const Key& key); //TODO
// 		void clear(); //TODO
// 		void print() const;

// 	public:
// 		/**
// 		* An internal iterator class for traversing the contents of the BST.
// 		*/
// 		class iterator 
// 		{
// 			public:
// 				iterator(Node<Key,Value>* ptr);
// 				iterator();

// 				std::pair<const Key, Value>& operator*();
// 				std::pair<const Key, Value>* operator->();

// 				bool operator==(const iterator& rhs) const;
// 				bool operator!=(const iterator& rhs) const;
// 				iterator& operator=(const iterator& rhs);

// 				iterator& operator++();

// 			protected:
// 				Node<Key, Value>* mCurrent;
// 		};

// 	public:
// 		iterator begin();
// 		iterator end();
// 		iterator find(const Key& key) const;

// 	protected:
// 		Node<Key, Value>* internalFind(const Key& key) const; //TODO
// 		Node<Key, Value>* getSmallestNode() const; //TODO
// 		void printRoot (Node<Key, Value>* root) const;

// 	protected:
// 		Node<Key, Value>* mRoot;
// };


 // template <typename Key, typename Value>
 // class rotateNode : public Node<Key, Value>
 // {
	
 // }
template <class Key, class Value>
class rotNode : public Node<Key, Value>
{
	public:
	rotNode (Key k, Value v, rotNode<Key, Value> *p)
	: Node<Key, Value> (k, v, p)
	{  }

	virtual ~rotNode(){}

	virtual rotNode<Key, Value> *getParent () const
	{ return (rotNode<Key,Value>*) this->mParent; }

	virtual rotNode<Key, Value> *getLeft () const
	{ return (rotNode<Key,Value>*) this->mLeft; }

	virtual rotNode<Key, Value> *getRight () const
		{ return (rotNode<Key,Value>*) this->mRight; }


		protected:
	std::pair<const Key, Value> mItem;
	Node<Key, Value>* mParent;
	Node<Key, Value>* mLeft;
	Node<Key, Value>* mRight;
	int mHeight;

};




template <typename Key, typename Value>
class rotateBST : public BinarySearchTree<Key,Value> // ask about this 
{
public:
	rotateBST();
	~rotateBST();
	bool sameKeys(const rotateBST& t2) const;
	void transform(rotateBST& t2) const;
	void transformHelper(Node<Key,Value>* root, Node<Key, Value>* goal);
protected:
		Node<Key, Value>* internalFind(const Key& key) const; //TODO
		Node<Key, Value>* getSmallestNode() const; //TODO
		void printRoot (Node<Key, Value>* root) const;


	Node<Key, Value>* mRoot;

protected:
	void leftRotate(Node<Key, Value>* r);
	void rightRotate(Node<Key, Value>* r);
};


template<typename Key, typename Value>
rotateBST<Key, Value>::rotateBST()
{
	mRoot = NULL;
}


template<typename Key, typename Value>
void inOrderTraversalHelper(std::vector<Key>& list, Node<Key, Value>* node){
	// TODO
	// implement in order
	   if(node->getLeft() != NULL) {
        inOrderTraversalHelper(list, node->getLeft());
    }
     list.push_back(node->getKey());
    if(node->getRight() != NULL) {
        inOrderTraversalHelper(list, node->getRight());
    }
    //list.push_back(node->val);
}

//make sure that it is updating the root correctly
template<typename Key, typename Value>
void rotateBST<Key, Value>::leftRotate(Node<Key, Value>* r)
{
		if (r->getLeft()==NULL)
	{
		return;
	}
	else
	{
		Node<Key, Value>* temp = r->getRight();
		r->setRight(temp->getLeft());


		//Node<Key, Value>* pred = NULL;

		if (r->getLeft() != NULL)
		{
			r->getLeft()->setParent(r);
			//pred = r->getRight();
		}

		temp->setLeft(r);

		temp->setParent(r->getParent());
		r->setParent(temp);

		if(temp->getParent() != NULL)
		{
			Node<Key, Value>* rent = temp->getParent();
			if(temp->getKey()< rent-> getKey())
			{
				rent->setLeft(temp);
			}
			else
			{
				rent->setRight(temp);
			}
		}
		else
		{
			mRoot = temp;
			//figure out how to do this
		}


		return;

		//check to see if it has any right children as well
				//move it to the left child of the parent of the node that you are calling rotate on

	}
}


template<typename Key, typename Value>
void rotateBST<Key, Value>::rightRotate(Node<Key, Value>* r)
{
	// check if root
	//if root parent = NULL set new root
	if (r->getLeft()==NULL)
	{
		return;
	}
	else
	{
		Node<Key, Value>* temp = r->getLeft();
		r->setLeft(temp->getRight());


		//Node<Key, Value>* pred = NULL;

		if (r->getLeft() != NULL)
		{
			r->getLeft()->setParent(r);
			//pred = r->getRight();
		}

		temp->setRight(r);

		temp->setParent(r->getParent());
		r->setParent(temp);

		if(temp->getParent() != NULL)
		{
			Node<Key, Value>* rent = temp->getParent();
			if(temp->getKey()< rent-> getKey())
			{
				rent->setLeft(temp);
			}
			else
			{
				rent->setRight(temp);
			}
		}
		else
		{
			mRoot = temp;
			//figure out how to do this
		}


		return;

		//check to see if it has any right children as well
				//move it to the left child of the parent of the node that you are calling rotate on

		
	}
}
template<typename Key, typename Value>
bool rotateBST<Key,Value>::sameKeys(const rotateBST& t2) const
{
	std::vector<Key> bstList;
	if(mRoot!= NULL)
		inOrderTraversalHelper(bstList, mRoot);
	std::vector<Key> rotList;
	if(t2.mRoot != NULL)
		inOrderTraversalHelper(rotList, t2.mRoot);
	if(bstList.size()!=rotList.size())
	{
		return false;
	}

	for(unsigned int i = 0; i < bstList.size(); i++)
	{
		if (bstList[i] != rotList[i])
		{
			return false;
		}
	}

	return true;


}

template<typename Key, typename Value>
void rotateBST<Key, Value>::transformHelper(Node<Key,Value>* root, Node<Key, Value>* goal) 
{
	if(root == NULL)
	{
		return;
	}
	while(root != goal)
	{
		leftRotate(root);
	}

	transformHelper(root->getLeft(), goal->getLeft());

	transformHelper(root->getRight(), goal->getRight());
}

template<typename Key, typename Value>
void rotateBST<Key, Value>::transform(rotateBST& t2) const
{
	if(sameKeys(t2) == false)
	{
		return;
	}
	else
	{
		while(t2.mRoot->getLeft()!= NULL)
		{
			t2.rightRotate(mRoot);
		}

		while(mRoot != t2.mRoot)
		{
			t2.leftRotate(mRoot);
		}
	}

	Node<Key,Value>* root = t2.mRoot->getLeft();
	Node<Key,Value>* goal = this->mRoot->getLeft();

	transformHelper(root, goal);

	root = t2.mRoot->getRight();
	goal = this->mRoot->getRight();
	transformHelper(root, goal);


	//Recursively do rotations on the left child 
	//and the right child until they match the node at that position of this.
}








#endif



Node<Key, Value>* temp = internalFind(key);
	if (temp == nullptr)
	{
		return;
	}

	if (temp->getRight() == nullptr && temp->getLeft() == nullptr)
	{
		if(temp == mRoot)
		{
			delete temp;
			mRoot = NULL;
			return;
		}
		else if (temp->getParent()->getKey()> key)
		{
			temp->getParent()->setLeft(nullptr);
			delete temp;
		}
		else
		{
			temp->getParent()->setRight(nullptr);
			delete temp;
		}
		return;
	}

	if (temp->getRight() == nullptr && temp->getLeft() != nullptr)
	{
			if(temp == mRoot)
		{
				Node<Key, Value>* rent = nullptr;
				mRoot = temp->getLeft();
				mRoot->setParent(rent);
			
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
				Node<Key, Value>* rent = nullptr;
				mRoot = temp->getLeft();
				mRoot->setLeft(temp->getLeft()->getLeft());
				temp->getRight()->setParent(mRoot);
				mRoot->setParent(rent);
			
			delete temp;
			return;
		}
		
		Node<Key, Value>* rent = temp->getParent();
		Node<Key, Value>* pred = temp->getLeft();
		if (pred->getRight() == nullptr)
		{
			pred->setRight(temp->getRight());
			pred->setLeft(nullptr);
			/*if (temp == mRoot)
			{
				pred->setParent(NULL);

			}
			
			else
			{*/
				pred->setParent(rent);
				rent->setLeft(pred);
			//}
			
		//	temp->getLeft()->getParent()->setLeft(pred);

			delete temp;
			return;

		}
		else
		{
			while(pred->getRight() != nullptr)
		
			{
				pred = pred->getRight();
			
			}

			pred->setRight(temp->getRight());
			pred->setLeft(temp->getLeft());
			/*if (temp == mRoot)
			{
				pred->setParent(NULL);

			}*/
			
			//else
			//{
				pred->setParent(rent);
								rent->setLeft(pred);

		//	}
			

			delete temp;
			return;
		}


		}


	return;


	emplate<typename Key, typename Value>
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
			return;
		}

		else if (temp->getParent()->getKey()> key)
		{
			temp->getParent()->setLeft(nullptr);
			delete temp;
		}
		else
		{
			temp->getParent()->setRight(nullptr);
			delete temp;
		}
		return;
	}

//one child
	if (temp->getRight() == nullptr && temp->getLeft() != nullptr)
	{
			if(temp == mRoot)
		{
				Node<Key, Value>* rent = nullptr;
				mRoot = temp->getLeft();
				mRoot->setParent(rent);
			
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
		
		Node<Key, Value>* rent = temp->getParent();

		Node<Key, Value>* pred = temp->getLeft();


		// if (pred->getRight() == nullptr)
		// {
		// 	pred->setRight(temp->getRight());
		// 	pred->setLeft(nullptr);
		// 	if (temp == mRoot)
		// 	{
		// 		pred->setParent(NULL);

		// 	}
			
		// 	else
		// 	{
		// 		pred->setParent(rent);
		// 		rent->setLeft(pred);
		// 	//}
			
		// //	temp->getLeft()->getParent()->setLeft(pred);

		// 	delete temp;
		// 	return;

			//Find predecessor
			while(pred->getRight() != nullptr)
		
			{
				pred = pred->getRight();
			
			}

			//At this point, pred is the rightmost node in left subtree
			pred->setRight(temp->getRight());

			if(pred = temp->getLeft())
			{
				pred->setLeft(nullptr);
			}

			else
			{
				pred->setLeft(temp->getLeft());
			}
			
			/*if (temp == mRoot)
			{
				pred->setParent(NULL);

			}*/
			
			//else
			//{
				pred->setParent(rent);
				rent->setLeft(pred);

		//	}
			

			delete temp;
			return;
		


		}


	return;
	 
}


