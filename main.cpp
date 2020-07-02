#include <vector>
#include <iostream>
#include "sort.h"
using namespace yis;
int main()
{
  std::vector<int> data = {629,345,465,24,2,71,630};
  std::vector<int> unsorted_data = data;

  // 1.测试选择排序.
//  std::cout << "original sequence:" << std::endl;
//  for(auto value : unsorted_data)
//  {
//    std::cout << value << std::endl;
//  }
//  sort::sort_select(unsorted_data);
//  std::cout << "result of select sort:" << std::endl;
//  for(auto value : unsorted_data)
//  {
//    std::cout << value << std::endl;
//  }

  // 2.测试插入排序.
//  unsorted_data = data;
//  std::cout << "original sequence:" << std::endl;
//  for(auto value : unsorted_data)
//  {
//    std::cout << value << std::endl;
//  }
//  sort::sort_insert(unsorted_data);
//  std::cout << "result of insert sort:" << std::endl;
//  for(auto value : unsorted_data)
//  {
//    std::cout << value << std::endl;
//  }

  // 3.测试冒泡排序.
//  unsorted_data = data;
//  std::cout << "original sequence:" << std::endl;
//  for(auto value : unsorted_data)
//  {
//    std::cout << value << std::endl;
//  }
//  sort::sort_bubble(unsorted_data);
//  std::cout << "result of bubble sort:" << std::endl;
//  for(auto value : unsorted_data)
//  {
//    std::cout << value << std::endl;
//  }

  // 4.测试希尔排序.
//  unsorted_data = data;
//  std::cout << "original sequence:" << std::endl;
//  for(auto value : unsorted_data)
//  {
//    std::cout << value << std::endl;
//  }
//  sort::sort_shell(unsorted_data);
//  std::cout << "result of shell sort:" << std::endl;
//  for(auto value : unsorted_data)
//  {
//    std::cout << value << std::endl;
//  }

  // 5.1 测试归并排序的递归实现
  unsorted_data = data;
  std::cout << "original sequence:" << std::endl;
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }
  sort::sort_merge_recursive(unsorted_data,0,6);
  std::cout << "result of recursive merge sort:" << std::endl;
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }

  // 5.2 测试归并排序的非递归实现
  unsorted_data = data;
  std::cout << "original sequence:" << std::endl;
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }
  sort::sort_merge_non_recursive(unsorted_data);
  std::cout << "result of non recursive merge sort:" << std::endl;
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }

}