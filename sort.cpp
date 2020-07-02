//
// Created by yis on 2020/7/1.
//

#include <iostream>
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

  void sort::sort_merge_non_recursive(std::vector<int> &data)
  {
    // 思想：
    // 归并排序这里不再是直接在原始序列上进行操作;
    // 归并排序利用的是分而治之的思想,将序列分成两个子序列,将两个子序列排好序后合并为有序的序列;
    // 而对两个子序列进行排序同样用分而治之,如此递归下去;
    // 归并分为三步：分,治,合;治是关键,而治又是最简单的,将序列分为只有一个元素的两个子序列后自然变得有序;
    // 所以归并可以分为两步：将序列一直分成只有一个元素的子序列,然后将这些有序的子序列合并.

    // 获取序列长度.
    int length = data.size();
    // 开始合并子序列,子序列长度为1,2,4,8....成倍增长(初始子序列长度必须为1,思考为什么).
    for(int i = 1; i < length; i *= 2)
    {
      // 划分子序列.
      int left = 0;
      int mid = left + i - 1;
      int right = mid + i;
      // 开始合并.
      // 注意此处while语句的结合条件,思考有什么问题.
      while(right < length)
      {
        // 合并函数和递归实现的合并函数一样.
        merge(data, left, mid, right);
        // 更新left,mid,right以合并下一对序列.
        left = right +1;
        mid = left + i -1;
        right = mid + i;
      }
      // while条件是有问题的,因为right = mid + i,随意可能出现情况： right < length < right + i;
      // 这样会导致right后面到length可能有元素被遗漏,没有对他们进行排序,此处要单独处理.
      if((left < length) && (mid < length))
      {
        merge(data,left,mid,length - 1);
      }
    }
  }

  void sort::sort_quick_recursive(std::vector<int> &data, int left, int right)
  {
    // 思想：
    // 在元素序列上直接操作;
    // 每次在无序序列中选取一个数,一般称之为中轴数,
    // 将元素序列分成两个部分,使得一部分的元素全都小于等于另一部分的所有元素;
    // 也就是说将序列分成小于等于中轴数和大于等于中轴数的两部分,使得中轴数变为有序;
    // 再递归的对分成的两部分进行划分操作.

    if(left < right)
    {
      // 找到中轴数的索引.
      int index = partition(data,left,right);
      // 以中轴数的索引为界递归处理两个部分的序列.
      sort_quick_recursive(data,left,index - 1);
      sort_quick_recursive(data,index + 1,right);
    }
  }

  int sort::partition(std::vector<int> &data, int left, int right)
  {
    // 找到中轴数的正确位置,同时将序列划分为两部分.
    // 中轴数有很多种取法,我们这里采用《算法导论》里的选取方法,即取序列最后一个元素.
    int key = data.at(right);
    // 此处设置两个索引i和j,区间[left,i]为小于中轴数的序列,
    // 区间[j,right-1]为大于中轴数的序列.
    int i = left - 1;
    for(int j = left; j < right; j++)
    {
      if(data.at(j) <= key)
      {
        // 大于中轴数的元素让它继续待在[j,right-1]区间什么也不做;
        // 小于中轴数的元素全部从[j,right-1]区间放到[left,i]区间去.
        ++i;
        int temp = data.at(i);
        data.at(i) = data.at(j);
        data.at(j) = temp;
      }
    }
    // 此时中轴数的正确位置应该在i+1,将其归位.
    // 思考为什么是i+1而不是i.
    int temp = data.at(i+1);
    data.at(i+1) = data.at(right);
    data.at(right) = temp;
    // 返回中轴数的正确索引.
    return i+1;
  }

  void sort::sort_quick_non_recursive(std::vector<int> &data, int left, int right)
  {
    // 思想：
    // 在元素序列上直接操作;
    // 每次在无序序列中选取一个数,一般称之为中轴数,
    // 将元素序列分成两个部分,使得一部分的元素全都小于等于另一部分的所有元素;
    // 也就是说将序列分成小于等于中轴数和大于等于中轴数的两部分,使得中轴数变为有序;
    // 再递归的对分成的两部分进行划分操作.

    // 非递归利用栈来实现.
    // 利用栈来存储子序列的起点后终点(其实递归也是通过调用系统堆栈来保护调用现场的).
    std::stack<int> s;
    if(left < right)
    {
      // 找到中轴数的索引.
      int index = partition(data, left, right);
      // 如果中轴数索引两个分区存在,则将起点和终点入栈.
      if(index - 1 > left)
      {
        // 下面的入栈顺序要和此处一致.
        s.push(left);
        s.push(index - 1);
      }
      if(index + 1 < right)
      {
        s.push(index + 1);
        s.push(right);
      }
      // 从栈里面取出序列并找到该序列中轴数的正确索引.
      while(!s.empty())
      {
        // 注意顺序.
        int r = s.top();
        s.pop();
        int l = s.top();
        s.pop();
        index = partition(data, l, r);
        // 将新的序列区间入栈.
        if(index - 1 > l)
        {
          s.push(l);
          s.push(index - 1);
        }
        if(index + 1 < r)
        {
          s.push(index + 1);
          s.push(r);
        }
      }
    }
  }

  void sort::sort_heap(std::vector<int> &data)
  {
    // 思想：
    // 在原始序列上直接操作.
    // 利用二叉堆的数据结构来实现排序,二叉堆是一个完全二叉数.
    // 二叉堆的特点是堆顶元素是一个最值(大顶堆的堆顶为最大值,小顶堆的堆顶为最小值);
    // 大顶堆：任意节点的元素都要大于他的子节点元素,小顶堆：任意节点的元素都要小于他的子节点元素.
    // 排序方法是将堆顶元素和最后一个元素交换,然后恢复大/小顶堆;再将堆顶元素和最后第二个元素交换,以此类推.
    // 排序第一步是需要将原始数据构建乘二叉堆(升序排序构建大顶堆,降序排序构建小顶堆),我们升序排序所以构建大顶堆;
    // 第二步是调整使之重新成为大顶堆,我们使用从最后一个非叶子节点往上进行下沉处理(down_adjust()).
    // 此处我们提供了二叉堆的插入元素后维护二叉堆的操作,采用上浮处理(up_adjust).

    // 建堆：从最后一个非叶子节点往上做下沉操作.
    int length = data.size();
    // 思考为什么是减2.
    for(int i = (length - 2)/2; i >= 0; i--)
    {
      down_adjust(data,i,length -1);
    }
    // 开始堆排序
    for(int i = length -1; i > 0; i--)
    {
      // 将堆顶节点与节点i交换.
      int temp = data.at(0);
      data.at(0) = data.at(i);
      data.at(i) = temp;
      // 恢复二叉堆.
      down_adjust(data,0,i - 1);
    }
  }

  void sort::down_adjust(std::vector<int> &data, int parent, int length)
  {
    // 对parent节点做下沉操作.
    // 临时保存要下沉的节点.
    int key = data.at(parent);
    // 定位左子节点.
    int child = 2 * parent + 1;
    while(child <= length)
    {
      // 定位parent的较大的子节点.
      if(child + 1 <= length && data.at(child) < data.at(child + 1))
      {
        ++child;
      }
      // 如果parent节点的元素大于子节点的元素,则下沉完成.
      if(key >= data.at(child))
      {
        // 注意此处是break而不是return(想想为什么).
        break;
      }
      // 需要下沉,将child节点放到父节点.
      data.at(parent) = data.at(child);
      // 更新parent和child,以便继续下沉操作.
      parent = child;
      child = 2 * parent +1;
    }
    // 找到下沉位置后将下沉元素放到正确位置上后完成操作.
    data.at(parent) = key;
  }

  void sort::up_adjust(std::vector<int> &data, int length)
  {
    // 将末节点上浮到适当位置.
    // 定位父子节点.
    int child = length - 1;
    int parent = (child - 1)/2;
    // 临时保存需要上浮的节点.
    int key = data.at(child);
    // 开始上浮(大顶堆)
    while(child > 0 && key > data.at(parent))
    {
      // 如果要上浮的节点元素大于父节点,则将parent节点放到其子节点上.
      data.at(child) = data.at(parent);
      // 更新parent和child,以继续上浮操作.
      child = parent;
      parent = (child - 1)/2;
    }
    // 找到上浮位置后,将要上浮的节点放进去.
    data.at(child) = key;
  }
}













