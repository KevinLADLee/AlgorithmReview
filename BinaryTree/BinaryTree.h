
#ifndef ALGORITHM_BINARYTREE_H
#define ALGORITHM_BINARYTREE_H

#include <memory>
#include <ostream>
#include <iostream>

template <typename T>
class BinaryTreeNode{
 public:
  BinaryTreeNode(T data) : data_(data){
    left_child_ = nullptr;
    right_child_ = nullptr;
  };

  friend std::ostream &operator<<(std::ostream &os, const BinaryTreeNode &node) {
    os << node.data_;
    return os;
  }

 public:
  T data_;
  std::shared_ptr<BinaryTreeNode> left_child_, right_child_;
};

template <typename T>
using BinaryTreeNodePtr = std::shared_ptr<BinaryTreeNode<T>>;

template <typename T>
class BinaryTree {

 public:
  BinaryTree():root_(nullptr){};

  BinaryTree(std::shared_ptr<BinaryTreeNode<T>> root){
    root_ = root;
  };

  BinaryTreeNodePtr<T> GetRoot(){
    return root_;
  }

  void PreOrderTraversal(BinaryTreeNodePtr<T> node_ptr){
    if(node_ptr == nullptr){
      return;
    }
    std::cout << *node_ptr << std::endl;
    PreOrderTraversal(node_ptr->left_child_);
    PreOrderTraversal(node_ptr->right_child_);
  };

  void InOrderTraversal(BinaryTreeNodePtr<T> node_ptr){
    if(node_ptr == nullptr){
      return;
    }
    InOrderTraversal(node_ptr->left_child_);
    std::cout << *node_ptr << std::endl;
    InOrderTraversal(node_ptr->right_child_);
  };

  void PostOrderTraversal(BinaryTreeNodePtr<T> node_ptr){
    if(node_ptr == nullptr){
      return;
    }
    PostOrderTraversal(node_ptr->left_child_);
    PostOrderTraversal(node_ptr->right_child_);
    std::cout << *node_ptr << std::endl;
  };


 private:
  std::shared_ptr<BinaryTreeNode<T>> root_;
};

#endif //ALGORITHM_BINARYTREE_H
