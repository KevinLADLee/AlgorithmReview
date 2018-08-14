
#include <iostream>
#include <memory>
#include "Sort.h"

int main() {

  std::vector<int> vec;
  vec.push_back(34);
  vec.push_back(8);
  vec.push_back(64);
  vec.push_back(51);
  vec.push_back(32);
  vec.push_back(21);
  vec.push_back(12);
//  vec.push_back(67);
//  vec.push_back(76);
//  vec.push_back(11);
//  vec.push_back(12);
//  vec.push_back(16);

  std::cout << "Insertion Sort: " << std::endl;
  auto vec1 = vec;
  InsertionSort(vec1);
  for(auto it : vec1){
    std::cout << it << " ";
  }
  std::cout << std::endl;

  std::cout << "Quick Sort: " << std::endl;
  auto vec2 = vec;
  QuickSort(vec2);
  for(auto it : vec2){
    std::cout << it << " ";
  }
  std::cout << std::endl;

  std::cout << "Merge Sort: " << std::endl;
  auto vec3 = vec;
  MergeSort(vec3);
  for(auto it : vec3){
    std::cout << it << " ";
  }
  std::cout << std::endl;

  std::cout << "Heap Sort: " << std::endl;
  auto vec4 = vec;
  HeapSort(vec4);
  for(auto it : vec4){
    std::cout << it << " ";
  }


}