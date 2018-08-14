
#include <iostream>
#include <memory>
#include "BinaryTree.h"


int main() {
  auto node1 = std::make_shared<BinaryTreeNode<char>>('F');
  auto node2 = std::make_shared<BinaryTreeNode<char>>('B');
  auto node3 = std::make_shared<BinaryTreeNode<char>>('G');
  auto node4 = std::make_shared<BinaryTreeNode<char>>('A');
  auto node5 = std::make_shared<BinaryTreeNode<char>>('D');
  auto node6 = std::make_shared<BinaryTreeNode<char>>('I');
  auto node7 = std::make_shared<BinaryTreeNode<char>>('C');
  auto node8 = std::make_shared<BinaryTreeNode<char>>('E');
  auto node9 = std::make_shared<BinaryTreeNode<char>>('H');

  node1->left_child_ = node2;
  node1->right_child_ = node3;
  node2->left_child_ = node4;
  node2->right_child_ = node5;
  node3->right_child_ = node6;
  node5->left_child_ = node7;
  node5->right_child_ = node8;
  node6->left_child_ = node9;

  auto bt_tree = BinaryTree<char>(node1);
  std::cout << "PreOrder Traversal" << std::endl;
  bt_tree.PreOrderTraversal(bt_tree.GetRoot());
  std::cout << "InOrder Traversal" << std::endl;
  bt_tree.InOrderTraversal(bt_tree.GetRoot());
  std::cout << "PostOrder Traversal" << std::endl;
  bt_tree.PostOrderTraversal(bt_tree.GetRoot());

  return 0;
}