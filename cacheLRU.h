#ifndef CACHE_LRU_H
#define CACHE_LRU_H


#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <stdexcept>
//#include <exception>
#include "rotateBST.h"
#include "bst.h"
#include "splayTree.h"

template <typename Key, typename Value>
class cacheLRU : public SplayTree<Key, Value>
{
public:
	cacheLRU(int capacity);
	~cacheLRU();
	void put(const std::pair<const Key, Value>& keyValuePair);
	std::pair<const Key, Value> get(const Key& key);

protected:
private:
	int capacity_;
	Node<Key, Value>* getLeafNode();


	// int size_;
	// std::queue<std::pair<Key,Value> > cache;
	// std::map<Key, Value> nodeMap;




};

template <typename Key, typename Value>
cacheLRU<Key,Value>::cacheLRU(int capacity)
{
	capacity = capacity_;


}
template <typename Key, typename Value>
cacheLRU<Key,Value>::~cacheLRU()
{

}

template <typename Key, typename Value>
std::pair<const Key, Value> cacheLRU<Key, Value>::get(const Key& key)
{
	if(BinarySearchTree<Key,Value>::internalFind(key) == NULL) {
          throw(std::logic_error("Invalid Key"));
        }
      
     else
     {
     	Node<Key, Value>* node = BinarySearchTree<Key, Value>::internalFind(key);
    	std::pair<const Key, Value> keyValuePair(node->getKey(), node->getValue());
    	SplayTree<Key, Value>::splay(node);
    	return keyValuePair;	
     }
     
}
template<typename Key, typename Value>
int inOrderTraversal(Node<Key, Value>* node){
	
	if (node == NULL)
	{
		return 0;
	}
	
        return 1 + inOrderTraversal(node->getLeft()) + inOrderTraversal(node->getRight());
  
      // return 1 + inOrderTraversal(count, node->getRight());
    
}
template<typename Key, typename Value>
Node<Key, Value>* cacheLRU<Key, Value>::getLeafNode() 
{
	Node<Key, Value>* node = BinarySearchTree<Key,Value>::mRoot;

	while(node->getLeft()!=nullptr)
	{
		node = node->getLeft();
	}

	while(node->getLeft()!= NULL && node->getRight() != NULL)
	{
		while(node->getRight()!= NULL)
		{
			node = node->getRight();
		}

		while(node->getLeft()!=NULL)
		{
			node = node->getLeft();
		}
	}

	

	return node;


}  

template <typename Key, typename Value>
void cacheLRU<Key, Value>::put(const std::pair<const Key, Value>& keyValuePair)
{
	//int count = 0;
	int size = inOrderTraversal(BinarySearchTree<Key, Value>::mRoot);
	if (size == capacity_)
	{
		Node<Key, Value>* node = this->getLeafNode();
		BinarySearchTree<Key, Value>::remove(node->getKey());
	}

	SplayTree<Key, Value>::insert(keyValuePair);
	return;

}
#endif