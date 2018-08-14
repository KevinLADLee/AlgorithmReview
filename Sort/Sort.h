
#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H

#include <algorithm>
#include <functional>
#include <iterator>

#include <iostream>

template <typename T>
void InsertionSort(std::vector<T> & vec, int left, int right){
  for(int i = left+1; i < right+1; ++i){
    T tmp = std::move(vec[i]);
    int j;
    // Compare part
    for(j = i; j > 0 && tmp < vec[j-1]; --j){
      vec[j] = std::move(vec[j-1]);
    }
    vec[j] = std::move(tmp);
  }
}

template <typename T>
void InsertionSort(std::vector<T> & vec){
  InsertionSort(vec, 0, vec.size()-1);
}

template <typename T>
const T &FindPivot(std::vector<T> & vec, int left, int right){
  int mid = (left + right) / 2;
  if(vec[mid] < vec[left]){
    std::swap(vec[left],vec[mid]);
  }
  if(vec[right] < vec[left]){
    std::swap(vec[left],vec[right]);
  }
  if(vec[right] < vec[mid]){
    std::swap(vec[mid],vec[right]);
  }
  std::swap(vec[mid], vec[right-1]);
  return vec[right-1];
}

#define CUT_OFF_SIZE 10

template <typename T>
void QuickSort(std::vector<T> & vec, int left, int right){
  if(left + CUT_OFF_SIZE <= right){
    const T & pivot = FindPivot(vec, left, right);

    int i = left, j= right-1;
    for(;;){
      while (vec[++i] < pivot){}
      while (pivot < vec[--j]){}
      if(i < j){
        std::swap(vec[i], vec[j]);
      } else{
        break;
      }
    }

    std::swap(vec[i], vec[right-1]);
    QuickSort(vec, left, i-1);
    QuickSort(vec, i+1,right);
  } else{
    InsertionSort(vec, left, right);
  }

}

template <typename T>
void QuickSort(std::vector<T> & vec){
  QuickSort(vec, 0, vec.size()-1);
}


template <typename T>
void Merge(std::vector<T> & vec,std::vector<T> & tmp_vec, int left_pos, int right_pos, int right_end)
{
  int left_end = right_pos - 1;
  int tmp_pos = left_pos;
  int num = right_end - left_pos + 1;
  while (left_pos <= left_end && right_pos <= right_end){
    // Compare part
    if(vec[left_pos] <= vec[right_pos]){
      tmp_vec[tmp_pos++] = std::move(vec[left_pos++]);
    } else{
      tmp_vec[tmp_pos++] = std::move(vec[right_pos++]);
    }
  }
  while (left_pos <= left_end){
    tmp_vec[tmp_pos++] = std::move(vec[left_pos++]);
  }

  while (right_pos <= right_end){
    tmp_vec[tmp_pos++] = std::move(vec[right_pos++]);
  }

  for(int i = 0; i < num; ++i, --right_end){
    vec[right_end] = std::move(tmp_vec[right_end]);
  }

}


template <typename T>
void MergeSort(std::vector<T> & vec,std::vector<T> & tmp_vec, int left, int right){
  if(left < right){
    int mid = (left + right) / 2;
    MergeSort(vec, tmp_vec, left, mid);
    MergeSort(vec, tmp_vec, mid+1, right);
    Merge(vec,tmp_vec,left,mid+1,right);
  }
}


template <typename T>
void MergeSort(std::vector<T> & vec){
  std::vector<T> tmp_vec(vec.size());
  MergeSort(vec, tmp_vec, 0, vec.size()-1);
}

/**
 * Heap Sort
 */
inline int LeftChild(int i){
  return 2 * i + 1;
}

template <typename T>
void Heapify(std::vector<T> & vec, int pos, int size){
  int child;
  T tmp;
  for(tmp = std::move(vec[pos]); LeftChild(pos) < size; pos = child)
  {
    child = LeftChild(pos);
    if(child != size - 1 && vec[child] < vec[child + 1]){
      ++child;
    }
    if(tmp < vec[child]){
      vec[pos] = std::move(vec[child]);
    } else{
      break;
    }
  }
  vec[pos] = std::move(tmp);
}

template <typename T>
void HeapSort(std::vector<T> & vec) {
  for(int i = vec.size() / 2 - 1; i >= 0; --i){
    Heapify(vec, i, vec.size());
  }
  for(int j = vec.size() - 1; j > 0; --j){
    std::swap(vec[0], vec[j]);
    Heapify(vec, 0, j);
  }
}

#endif //ALGORITHM_SORT_H
