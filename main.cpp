#include <vector>
#include <iostream>
#include "sort.h"
using namespace yis;
int main()
{
  std::vector<int> data = {629,345,465,24,2,71,630};

  //测试选择排序.
  std::vector<int> unsorted_data = data;
  sort::sort_select(unsorted_data);
  for(auto value : unsorted_data)
  {
    std::cout << value << std::endl;
  }
}