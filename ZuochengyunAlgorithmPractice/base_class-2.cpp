//
// Created by Gavyn on 2020/12/14.
//
#include <bits/stdc++.h>
using namespace std;

/******************************************************************************
 * 荷兰国旗问题引入，
 * 经典快排，
 * 荷兰国旗改进快排，
 * 随机快排
 ******************************************************************************/
/**
  * @brief 荷兰国旗问题引入
  *        给定一个数组arr，和一个数num，请把小于等于num的数放在数组的左边，大于num的数放在数组的右边。
  *        要求额外空间复杂度O(1)，时间复杂度O(N)
  * @param[in] arr 输入数组
  * @param[in] num 需要比较的值
  * @return void
  */
void partition(vector<int> &arr, int num)
{
    int x = -1; //代表小于区域的位置
    int cur = 0; //变量cur作为遍历的位置
    while (cur < arr.size()) {
        if (num >= arr[cur]) {
            swap(arr[cur++], arr[++x]);
        } else { //num < arr[cur]
            cur++;
        }
    }
}

 /**
  * @brief   问题二（荷兰国旗问题）
  *          给定一个数组arr，和一个数num，请把小于num的数放在数组的左边，
  *          等于num的数放在数组的中间，大于num的数放在数组的右边。
  *          要求额外空间复杂度O(1)，时间复杂度O(N)
  * @param[in] arr 输入数组
  * @param[in] l  需要处理区间的最小值
  * @param[in] r 需要处理区间的最大值
  * @param[in] num 需要比较的值
  * @return 存放等于num值的索引最小值最大值的数组
  */
 vector<int> partition(vector<int> &arr, int l, int r, int num)
 {
    int less = l - 1; //变量less代表小于区域的位置
    int more = r + 1; //变量more代表大于num的区域
    int cur = l; //变量cur作为遍历的位置
    while (cur < more) {
        if (num > arr[cur]) {
            swap(arr[++less], arr[cur++]);
        } else if (num < arr[cur]) {
            swap(arr[cur], arr[--more]);
        } else { // == num
            cur++;
        }
    }
    return vector<int> {less + 1, more - 1};
 }

 // for test
 int main ()
 {
     vector<int> input{2,5,9,6,2,3,4,2,7,1,3,0,0};
     vector<int> res;
     res = partition(input,0,12,3);
     for (int i = 0; i < input.size(); ++i) {
         cout << input[i] << " ";
     }
     cout<< endl;
     cout << res[0] << endl << res[1] <<endl;
 }

/**
 * brief 经典快速排序，基准数据找其正确索引位置的过程
 *       partition 函数找到分区后的第一个元素正确索引的位置
 * @param[in] arr 输入数组
 * @param[in] low 需要排序区间的下限值
 * @param[in] high 需要排序区间的上限值
 */
int partition(vector<int> arr, int low, int high);
void QuikSort(vector<int> arr, int low, int high)
{
    if (low < high) {
        int pivot = partition(arr, low, high); // 找arr[low]正确索引的位置
        QuikSort(arr, low, pivot); // 分治法递归左半部分
        QuikSort(arr, pivot + 1, high); // 分治法递归右半部分
    }
}

int partition(vector<int> arr, int low, int high)
{
    int pivot = arr[low]; // 设最开始的基准数据为数组第一个元素arr[low],则首先用一个临时变量去存储基准数据
    while (low < high) {
        while (low < high & arr[high] > pivot) { // 当队尾的元素大于等于基准数据时,向前挪动high指针
            high--;
        }
        arr[low] = arr[high]; // 如果队尾元素小于基准数据了,需要将其赋值给low
        while (low < high & arr[low] <= pivot) { // 当队首元素小于等于pivot时,向前挪动low指针
            low++;
        }
        arr[high] = arr[low]; // 当队首元素大于pivot时,需要将其赋值给high
    }
    arr[low] = pivot; // 跳出循环时low和high相等,此时的low或high就是pivot的正确索引位置
    return low; // 返回pivot的正确位置
}

/**
 * brief 经典快速排序，思路和荷兰国旗问题中的预备题目一样。
 *       1.首先在数组[l,r]中把最后一个元素作为num进行比较，得到两段区域，分别为小于等于最后一个数的区域和大于最后一个数的区域。
         2.在上述第一段区域内，最后一个数的值为num保留不动，倒数第二个数重新命名为num，接着继续比较，不断迭代。
         3.在上述1的第二段区域内，把最后一个数命名为num，接着继续比较，不断迭代。
         4.迭代继续的条件是if(l<r)
 * @param[in] arr 输入数组
 * @param[in] l  需要处理区间的最小值
 * @param[in] r 需要处理区间的最大值
 * return 返回值为x-1：返回小于等于范围内倒数第二个位置的位置，最后一个位置就是原来的num，下次直接用倒数第二个位置作为下一次的num。
 */

