// 冒泡排序，作者：C语言技术网（www.freecplus.net）码农有道。
#include <stdlib.h>
#include <stdio.h>

// 采用两层循环实现的方法。
// 参数arr是待排序数组的首地址，len是数组元素的个数。
void bubblesort1(int *arr,unsigned int len)
{
  if (len<2) return; // 数组小于2个元素不需要排序。

  int ii;    // 排序的趟数的计数器。
  int jj;    // 每趟排序的元素位置计数器。
  int itmp;  // 比较两个元素大小时交换位置用到的临时变量。

  // 44,3,38,5,47,15,36,26,27,2,46,4,19,50,48  
  for (ii=len-1;ii>0;ii--)  // 一共进行len-1趟比较。
  {
    for (jj=0;jj<ii;jj++)  // 每趟只需要比较0......ii之间的元素，ii之后的元素是已经排序好的。
    {
      if (arr[jj]>arr[jj+1])  // 如果前面的元素大于后面的元素，则交换它位的位置。
      {
        itmp=arr[jj+1];
        arr[jj+1]=arr[jj];
        arr[jj]=itmp;
      }
    }
  }
}

// 采用递归实现的方法。
// 参数arr是待排序数组的首地址，len是数组元素的个数。
void bubblesort2(int *arr,unsigned int len)
{
  if (len<2) return; // 数组小于2个元素不需要排序。

  int ii;    // 排序的元素位置计数器。
  int itmp;  // 比较两个元素大小时交换位置用到的临时变量。

  for (ii=0;ii<len-1;ii++)  // 每趟只需要比较0......len-1之间的元素，len-1之后的元素是已经排序好的。
  {
    if (arr[ii]>arr[ii+1])  // 如果前面的元素大于后面的元素，则交换它位的位置。
    {
      itmp=arr[ii+1];
      arr[ii+1]=arr[ii];
      arr[ii]=itmp;
    }
  }

  bubblesort2(arr,--len);
}

int main(int argc,char *argv[])
{
  int arr[]={44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
  int len=sizeof(arr)/sizeof(int);

  bubblesort1(arr,len);

  // 显示排序结果。
  int ii;
  for (ii=0;ii<len;ii++) printf("%2d ",arr[ii]);

  printf("\n");

  // system("pause");  // widnows下的C启用本行代码。

  return 0;
}
