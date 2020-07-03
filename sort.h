//
// Created by yis on 2020/7/1.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H

#include <vector>
#include <stack>
#include <list>
#include <cmath>

namespace yis
{
  class sort
  {
    // 十种排序算法
    // 算法实现的都是升序排序

  public:
    // 1 选择排序.
    static void sort_select(std::vector<int>& data);

    // 2 插入排序.
    static void sort_insert(std::vector<int>& data);

    // 3 冒泡排序.
    static void sort_bubble(std::vector<int>& data);

    // 4 希尔排序.
    static void sort_shell(std::vector<int>& data);
    static void insert_i(std::vector<int>& data,int h,int i);

    // 5.1 归并排序-递归实现.
    static void sort_merge_recursive(std::vector<int>& data,int left,int right);
    static void merge(std::vector<int>& data,int left,int mid,int right);

    // 5.2 归并排序-非递归实现.
    static void sort_merge_non_recursive(std::vector<int>& data);
    // 非递归用到的merge()函数和递归使用的merge()是一样的.

    // 6.1 快速排序-递归实现.
    static void sort_quick_recursive(std::vector<int>& data, int left, int right);
    static int partition(std::vector<int>& data, int left, int right);

    // 6.2 快速排序-非递归实现.
    static void sort_quick_non_recursive(std::vector<int>& data, int left, int right);
    // 非递归用到的partition()函数和递归使用的partition()是一样的.

    // 7 堆排序.
    static void sort_heap(std::vector<int>& data);
    static void down_adjust(std::vector<int>& data, int parent, int length);
    // 堆排序没有用到上浮函数,它用于在堆尾插入元素后进行上浮以维护二叉堆的特性.
    static void up_adjust(std::vector<int>& data, int length);

    // 8 计数排序.
    static void sort_count(std::vector<int>& data);

    // 9 桶排序.
    static void sort_bucket(std::vector<int>& data);
    // 会用到非递归快速排序函数：sort_quick_non_recursive().

    // 10 基数排序.
    static void sort_radix(std::vector<int>& data);
  };
}


#endif //SORT_SORT_H
