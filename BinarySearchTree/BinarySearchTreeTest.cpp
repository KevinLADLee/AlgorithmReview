
#include <iostream>
#include <memory>
#include "BinarySearchTree.h"

int main() {

  BinarySerchTree<int> bst(6);
  bst.Insert(2);
  bst.Insert(8);
  bst.Insert(1);
  bst.Insert(4);
  bst.Insert(3);
  bst.Insert(5);
  bst.InOrderTraversal(bst.GetRoot());

  bst.Remove(3);
  bst.InOrderTraversal(bst.GetRoot());
  bst.Remove(8);
  bst.InOrderTraversal(bst.GetRoot());

  std::cout << "Max: " << bst.FinMax() << std::endl;
  std::cout << "Min: " << bst.FinMin() << std::endl;

  std::cout << "Deep Copy BST" << std::endl;
  BinarySerchTree<int> bst_copy(bst);
  bst_copy.InOrderTraversal(bst.GetRoot());

}