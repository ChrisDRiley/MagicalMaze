#ifndef TREE_CPP
#define TREE_CPP

#include "tree.h"
#include <fstream>
#include <iostream>
using namespace std;

// Creates a new tree with an empty root
template<class ItemType>
TreeType<ItemType>::TreeType(){ root = NULL; }

// Destructor for tree
template<class ItemType>
TreeType<ItemType>::~TreeType(){ Destroy(root); }

// Copy constructor for tree
template<class ItemType>
TreeType<ItemType>::TreeType (const TreeType &original){ CopyTree(root, original.root); }
      
// Calls the CopyTree method to let a tree contain the elements of another
template<class ItemType>
void TreeType<ItemType>::operator=(TreeType<ItemType> &original){
      if(original == this)
            return;
      Destroy(root);
      CopyTree(root, original.root);
}

// Calls the BinarySearch method to find if a node is in the tree
template<class ItemType>
bool TreeType<ItemType>::Search(ItemType &value) { BinarySearch(root, value); }

// Calls the InsertItem method to add a node to the tree
template<class ItemType>
bool TreeType<ItemType>::Insert(ItemType value) { InsertItem(root, value); }

// Calls the PrintTree method to print the tree
template<class ItemType>
void TreeType<ItemType>::Print() { PrintTree(root); }

// Checks if a binary search tree contains nothing
template<class ItemType>
bool TreeType<ItemType>::isEmpty() { return root==0; }

// Calls the Delete method to remove a node if found
template<class ItemType>
bool TreeType<ItemType>::DeleteItem(ItemType value) { return Delete(root, value); }

// Copies one tree to another by copying nodes for each root in order
template<class ItemType>
void TreeType<ItemType>::CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* original){
      if (original != NULL){
            copy = new TreeNode<ItemType>;
            copy->data = original->data;
            CopyTree(copy->left, original->left);
            CopyTree(copy->right, original->right);
      }
}

// Searches through the tree going down the left or right branches until it finds a matching node
// If it reaches the end and no node is found, returns false
template<class ItemType>
bool TreeType<ItemType>::BinarySearch(TreeNode<ItemType>* root, ItemType &value){
      if (root == NULL || root->data == value){
            return true; } 
      if (root->data < value) return BinarySearch(root->right, value);
      return BinarySearch(root->left, value);
      return false;
}

// Adds nodes to tree in order by sorting down the branches until an empty node is found
template<class ItemType>
bool TreeType<ItemType>::InsertItem(TreeNode<ItemType>*&  root, ItemType value){
      if (root == NULL){
            root = new TreeNode<ItemType>;
      if (root == NULL){
            cout<<"Not enough memory\n";
            return false;
      }
      root->data = value;
      root->left = NULL;
      root->right = NULL;
      return true;
      } else if (value < root->data){
            return InsertItem(root->left, value);
      } else if (value >= root->data){
            return InsertItem(root->right, value);
      }
      return false;
}

// Prints all nodes in order
template<class ItemType>
void TreeType<ItemType>::PrintTree(TreeNode<ItemType>* root){
      if (root != NULL){
            PrintTree(root->left);
            cout << root->data << endl;
            PrintTree(root->right);
      } //cout << root->data << endl;
}

// Deletes all nodes in order
template<class ItemType>
void TreeType<ItemType>::Destroy(TreeNode<ItemType>*& root){
      if(root != NULL){
            Destroy(root->left);
            Destroy(root->right);
            delete root;
      }
}

/* Returns false if there is nothing in the BST
*  Moves left or right depending on the value of the 
*  node that you are trying to find
*  Once it matches, it checks the number of children 
*  and adjusts to replace the node
*/
template<class ItemType>
bool TreeType<ItemType>::Delete(TreeNode<ItemType>*& root, ItemType data){
      TreeNode<ItemType> *temp;
      if (root == NULL){
            return false;
      } else if (data < root->data){
            return Delete(root->left,data);
      } else if (data > root->data){
            return Delete(root->right, data);
      } else {
            if (root->left == NULL && root->right == NULL){
                  data = root->data;
                  delete root;
                  root = NULL;
                  return true;
            } else if (root->left != NULL && root->right == NULL){
                  data = root->data;
                  temp = root;
                  root = root->left;
                  delete temp;
                  return true;
            } else if (root->right != NULL && root->left == NULL){
                  data = root->data;
                  temp = root;
                  root = root->right;
                  delete temp;
                  return true;
            } else if (root->right != NULL && root->left != NULL){
                  data = root->data;
                  FindMin(root->right, root->data);
                  Delete(root->right, root->data);
            }
      }
      return false;
   }

// Moves all the way left down the BST until the smallest value node is found
template<class ItemType>
void TreeType<ItemType>::FindMin(TreeNode<ItemType>* root, ItemType &data){
      while (root->left != NULL){
            root = root->left;
      }
      data = root->data;
}
template<class ItemType>
ItemType TreeType<ItemType>::getCurrentData(){
	return current->data;
}
template<class ItemType>
void TreeType<ItemType>::moveCurrentLeft(){
	if(current->left != NULL){
		current = current->left;
	}
}
template<class ItemType>
void TreeType<ItemType>::moveCurrentRight(){
	if(current->right != NULL){
		current = current->right;
	}
}
template<class ItemType>
void TreeType<ItemType>::setCurrentToRoot(){
	if(root != NULL){
		current = root;
	}
}


#endif
