#include <vector>
#include <iostream>
#include "sort.h"
using namespace yis;
int main()
{
  std::vector<int> data = {629,345,465,24,2,71,630};

  // 1.测试选择排序.
  std::vector<int> unsorted_data = data;
  std::cout << "original sequence:" << std::endl;
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }
  sort::sort_select(unsorted_data);
  std::cout << "result of select sort:" << std::endl;
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }

  // 2.测试插入排序.
  unsorted_data = data;
  std::cout << "original sequence:" << std::endl;
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }
  sort::sort_insert(unsorted_data);
  std::cout << "result of insert sort:" << std::endl;
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }

  // 3.测试冒泡排序.
  unsorted_data = data;
  std::cout << "original sequence:" << std::endl;
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }
  sort::sort_bubble(unsorted_data);
  std::cout << "result of bubble sort:" << std::endl;
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }

  // 4.测试希尔排序.
  unsorted_data = data;
  std::cout << "original sequence:" << std::endl;
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }
  sort::sort_shell(unsorted_data);
  std::cout << "result of shell sort:" << std::endl;
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }
}