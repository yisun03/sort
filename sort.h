//
// Created by yis on 2020/7/1.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H

#include <vector>

namespace yis
{
  class sort
  {
    // 十种排序算法
    // 算法实现的都是升序排序

  public:
    // 选择排序
    static void sort_select(std::vector<int>& data);

    // 插入排序
    static void sort_insert(std::vector<int>& data);
  };
}


#endif //SORT_SORT_H
