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
        // 如果监控位为0,则说明无序区已经是有序的了,排序完毕 .
        return;
      }
    }
  }

  void sort::sort_shell(std::vector<int> &data)
  {
    // 思想：
    // 还是在原待排序序列上进行操作;
    // 该算法是插入排序的变种和优化,当无序序列不理想,简单的插入排序会有很多的交换操作,影响效率;
    // 希尔排序做的改进是将原始待排序序列以一个偏移量h进行逻辑上的分组,对组内的元素采用插入排序,使得原始序列基本有序;
    // 偏移量逐渐减小,每减小一次进行组内插入排序,最后一轮则以1为偏移量,也就是将原书待排序列分为同一组进行组内排序,也就是简单的插入排序;
    // 该排序算法对于无序序列很不理想的情况有利.
    // 注：一般将h初始值设为length/2,h逐倍递减直至1,其实还有更理性的分组方法,对最终效率也有所优化.
    // 对于分组方法,可以戳链接：https://mp.weixin.qq.com/s/4kJdzLB7qO1sES2FEW0Low

    int length = data.size();
    if(length < 2)
    {
      return;
    }
    // 组内排序,注意排序方法是对各个分组进行交替排序.
    for(int h = length/2; h > 0; h /= 2)
    {
      // 对偏移量为h的分组交替进行插入排序.
      // i = h是第一组的第二个元素,仔细想想.
      for(int i = h; i < length; i++)
      {
        insert_i(data,h,i);
      }
    }
  }

  void sort::insert_i(std::vector<int> &data, int h, int i)
  {
    // 该部分代码其实就是插入排序的代码.
    // 将第i个元素插入到以h为偏移量分的组的有序区的适当位置.
    int temp = data.at(i);
    int k;
    for(k = i - h; k >= 0 && data.at(k) > temp; k -= h)
    {
      // 腾出插入位置.
      data.at(k+h) = data.at(k);
    }
    // 已找到要插入的位置为k+h,插入.
    data.at(k+h) = temp;
  }

  void sort::sort_merge_recursive(std::vector<int> &data, int left, int right)
  {
    // 思想：
    // 归并排序这里不再是直接在原始序列上进行操作;
    // 归并排序利用的是分而治之的思想,将序列分成两个子序列,将两个子序列排好序后合并为有序的序列;
    // 而对两个子序列进行排序同样用分而治之,如此递归下去;
    // 归并分为三步：分,治,合;治是关键,而治又是最简单的,将序列分为只有一个元素的两个子序列后自然变得有序;
    // 所以归并可以分为两步：将序列一直分成只有一个元素的子序列,然后将这些有序的子序列合并.

    if(left < right)
    {
      // 将序列一分为二并获取中间位置.
      int mid = (left + right)/2;
      // 递归处理两个子序列使之有序.
      sort_merge_recursive(data, left, mid);
      sort_merge_recursive(data, mid + 1, right);
      // 合并两个有序子序列后结束归并排序.
      merge(data, left, mid, right);
    }
  }

  void sort::merge(std::vector<int> &data, int left, int mid, int right)
  {
    // 将有序的两个子序列合并.
    // 获取两个子序列的第一个元素.
    int i = left;
    int j = mid + 1;
    // 创建临时容器来保存合并结果,同时指定容器大小.
    std::vector<int> temp;
    temp.resize(right - left + 1);
    // 开始合并.
    int k = 0;
    while((i <= mid) && (j <= right))
    {
      if(data.at(i) <= data.at(j))
      {
        temp.at(k++) = data.at(i++);
      }
      else
      {
        // data.at(j) < data.at(i);
        temp.at(k++) = data.at(j++);
      }
    }
    // 到此为止肯定有一个子序列已经完全放到临时容器里,现在将另子序列的元素放入临时容器.
    while(i <= mid)
    {
      temp.at(k++) = data.at(i++);
    }
    while(j <= right)
    {
      temp.at(k++) = data.at(j++);
    }
    // 最后将临时容器里的元素复制到原容器完成合并.
    // 切记这里不能直接使用赋值：data = temp;
    // 因为这是递归操作,如果这样赋值,那么data的长度会变成2(思考一下为什么是2),
    // 那么后续操作中会导致"std::out_of_range"错误.
    for(int n = 0; n < k; n++)
    {
      data.at(left++) = temp.at(n);
    }
  }
}
