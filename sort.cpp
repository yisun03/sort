//
// Created by yis on 2020/7/1.
//

#include "sort.h"

namespace yis
{
  void sort::sort_select(std::vector<int>& data)
  {
    // 思想：
    // 在原始待排序列上做修改;
    // 首先找出待排序列中最小的数,然后用这个数和原序列中的第一个数交换位置;
    // 其次,找出第二小的和原第二个数交换位置;
    // 依次顺序直到找到第二大的数,之后原数列完全变成有序数列.

    //获取待排序列的长度,长度小于2则序列肯定为有序的.
    auto length = data.size();
    if(length < 2)
    {
      return;
    }
    //开始选择
    for(unsigned long i = 0; i < length - 1; i++)
    {
      // 找到无序序列中最小的数的下标.
      unsigned long min = i;
      for(unsigned long j = i + 1; j < length; j++)
      {
        if(data.at(min) > data.at(j))
        {
          min = j;
        }
      }
      // 此时的min是无序序列中最小值的下标,将其放入有序序列区.
      auto temp = data.at(i);
      data.at(i) = data.at(min);
      data.at(min) = temp;
    }
  }

  void sort::sort_insert(std::vector<int>& data)
  {
    // 思想：
    // 在原始待排序列上做修改;
    // 将待排序序列分为有序区和无序区;
    // 最开始的待排序列只有第一个元素是有序的;
    // 从第二个元素开始,向有序区往前查找合适的位置插入;
    // 直到最后一个元素找到了合适的位置插入时原待排序列变为有序序列.

    // 获取待排序列的长度,长度小于2则序列肯定为有序的.
    auto length = data.size();
    if(length < 2)
    {
      return;
    }
    // 从序列中第二个元素开始遍历
    for(unsigned long i = 1; i < length; i++)
    {
      // 本轮要插入的元素.
      int key = data.at(i);
      // k从最后一个有序元素（i前一个)往前遍历查找插入位置.
      // 此处k的类型不能是unsigned long,因为k可能会等于-1,
      // 如何为unsigned long的话会出现out of range 的错误.
      int k = i - 1;
      while(k >= 0 && data.at(k) > key)
      {
        // 将大于key的元素往后移,给key腾出位置插入.
        data.at(k+1) = data.at(k);
        k--;
      }
      // 已经找到要插入的位置为k+1,将key插入.
      data.at(k+1) = key;
    }
  }

  void sort::sort_bubble(std::vector<int> &data)
  {
    // 思想：
    // 在原始待排序序列上操作;
    // 将原始待排序序列分成无序区和有序区两部分;
    // 初始状态下整个原始序列为无序区,每遍历一遍就浮现出无序区最大的元素放在有序区;
    // 随着遍历,最终无序区长度变为0,整个原始序列变为有序序列.

    // 设置一个监控位,用于记录是否无序区碰巧为有序的,那么便免于对已经有序的序列排序.
    int flag = 0;

    // 获取序列元素个数.
    auto length = data.size();
    if(length < 2)
    {
      return;
    }
    // 开始遍历查找无序区最大值.
    for(unsigned long i = 0; i < length; i++)
    {
      flag = 0;
      for(unsigned long j = 0; j < length-i-1; j++)
      {
        if(data.at(j+1) < data.at(j))
        {
          // 无序区前一个元素大于它的后一个元素,需要交换位置以及设置本轮的监控位.
          flag = 1;
          auto temp = data.at(j);
          data.at(j) = data.at(j+1);
          data.at(j+1) = temp;
        }
      }
      if(flag == 0)
      {
        // 如果监控位为0,则说明无序区已经是有序的了,排序完毕.
        return;
      }
    }
  }
}
