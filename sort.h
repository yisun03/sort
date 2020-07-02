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
    // 1.选择排序
    static void sort_select(std::vector<int>& data);

    // 2.插入排序
    static void sort_insert(std::vector<int>& data);

    // 3.冒泡排序
    static void sort_bubble(std::vector<int>& data);

    // 4.希尔排序
    static void sort_shell(std::vector<int>& data);
    static void insert_i(std::vector<int>& data,int h,int i);

    // 5.1归并排序-递归实现
    static void sort_merge_recursive(std::vector<int>& data,int left,int right);
    static void merge(std::vector<int>& data,int left,int mid,int right);
  };
}


#endif //SORT_SORT_H
