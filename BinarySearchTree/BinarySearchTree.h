
#ifndef ALGORITHM_BINARYSERCHTREE_H
#define ALGORITHM_BINARYSERCHTREE_H

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

  BinaryTreeNode(const T & data,
                 std::shared_ptr<BinaryTreeNode> left_child,
                 std::shared_ptr<BinaryTreeNode> right_child):
                 data_(data),left_child_(left_child),right_child_(right_child)
                 {};

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
class BinarySerchTree {
 public:
  BinarySerchTree():root_(nullptr){};

  BinarySerchTree(T key){
    root_ = std::make_shared<BinaryTreeNode<T>>(key);
  }

  BinarySerchTree(BinaryTreeNodePtr<T> root):root_(root){
    root_->left_child_.reset();
    root_->right_child_.reset();
  };

  BinarySerchTree(const BinarySerchTree & rhs){
    root_ = Clone(rhs.root_);
  };

  const BinaryTreeNodePtr<T> &GetRoot() const {
    return root_;
  }

  bool Find(T key){
    return Find(key, root_);
  }

  const T &FinMax() const{
    return FindMaxNode(root_)->data_;
  };

  const T &FinMin() const{
    return FindMinNode(root_)->data_;
  };

  bool Insert(T key){
    return Insert(key, root_);
  };

  bool Remove(T key){
    Remove(key,root_);
  };

  void InOrderTraversal(BinaryTreeNodePtr<T> node_ptr){
    if(node_ptr == nullptr){
      return;
    }
    InOrderTraversal(node_ptr->left_child_);
    std::cout << *node_ptr << std::endl;
    InOrderTraversal(node_ptr->right_child_);
  };

 private:
  BinaryTreeNodePtr<T> Clone(BinaryTreeNodePtr<T> node_ptr) const{
    return node_ptr == nullptr ? nullptr : std::make_shared<BinaryTreeNode<T>>(node_ptr->data_,
                                                                                Clone(node_ptr->left_child_),
                                                                                Clone(node_ptr->right_child_));
  }

  bool Find(T key, const BinaryTreeNodePtr<T> &node_ptr){
    if(node_ptr == nullptr){
      return false;
    } else if(key < node_ptr->data_){
      return Find(key, node_ptr->left_child_);
    } else if(key > node_ptr->data_){
      return Find(key, node_ptr->right_child_);
    } else{
      std::cout << "Found: " << key << std::endl;
      return true;
    }
  };

  BinaryTreeNodePtr<T> FindMinNode(BinaryTreeNodePtr<T> node_ptr) const {
    if(node_ptr == nullptr){
      return nullptr;
    }
    if(node_ptr->left_child_ == nullptr){
      return node_ptr;
    }
    return FindMinNode(node_ptr->left_child_);
  }

  BinaryTreeNodePtr<T> FindMaxNode(BinaryTreeNodePtr<T> node_ptr) const {
    if(node_ptr == nullptr){
      return nullptr;
    }
    if(node_ptr->right_child_ == nullptr){
      return node_ptr;
    }
    return FindMaxNode(node_ptr->right_child_);
  }

  bool Insert(T key, BinaryTreeNodePtr<T> & node_ptr){
    if(node_ptr == nullptr){
      node_ptr = std::make_shared<BinaryTreeNode<T>>(key);
    } else if(key < node_ptr->data_){
      Insert(key, node_ptr->left_child_);
    } else if(key > node_ptr->data_){
      Insert(key, node_ptr->right_child_);
    } else{
      return false;
    }
  };

  bool Remove(T key, BinaryTreeNodePtr<T> & node_ptr){
    if(node_ptr == nullptr){
      return false;
    } else if(key < node_ptr->data_){
      Remove(key, node_ptr->left_child_);
    } else if(key > node_ptr->data_){
      Remove(key, node_ptr->right_child_);
    } else if(node_ptr->left_child_ != nullptr && node_ptr->right_child_!=nullptr){
      node_ptr->data_ = FindMinNode(node_ptr)->data_;
      Remove(node_ptr->data_, node_ptr->right_child_);
    } else {
      auto backup_node = &node_ptr;
      node_ptr.swap(node_ptr->left_child_ != nullptr ? node_ptr->left_child_ : node_ptr->right_child_);
      std::cout << "Removed: " << key << std::endl;
      backup_node->reset();
      return true;
    }
  };

 private:
  BinaryTreeNodePtr<T> root_;
};

#endif //ALGORITHM_BINARYSERCHTREE_H
