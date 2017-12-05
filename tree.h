#ifndef TREE_H
#define TREE_H

#include <fstream>
#include <iostream>
using namespace std;
#include "Treend.h"
template<class ItemType>
class TreeType 
{

   public:
      TreeType();
      TreeType (const TreeType &original);
      void operator=(TreeType &orginal);
      bool Search(ItemType &value);
      bool Insert(ItemType value);
      void Print() ;
     ~TreeType();
      bool isEmpty(); 
      bool DeleteItem(ItemType value);
      ItemType getCurrentData();
      void moveCurrentLeft();
      void moveCurrentRight();
      void setCurrentToRoot();
  
      
   private:
      TreeNode<ItemType>* current;
      TreeNode<ItemType>* root;
      void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* original);
      bool BinarySearch(TreeNode<ItemType>* root, ItemType &value);
      bool InsertItem(TreeNode<ItemType>*&  root, ItemType value);
      void PrintTree(TreeNode<ItemType>* root);
      void Destroy(TreeNode<ItemType>*& root); 
      bool Delete(TreeNode<ItemType>*& root, ItemType data);
      void FindMin(TreeNode<ItemType>* root, ItemType &data);


};

#include "tree.cpp"
#endif
