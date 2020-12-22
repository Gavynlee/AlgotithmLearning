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
 vector<int> partition(vector<int> &arr, int l, int r, int num) // partition返回等于num的区间索引
 {
    int less = l - 1; // 变量less代表小于区域的位置
    int more = r + 1; // 变量more代表大于num的区域
    int cur = l; // 变量cur作为遍历的位置
    while (cur < more) {
        if (num > arr[cur]) {
            swap(arr[++less], arr[cur++]); // 两头向中间压缩
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
 * brief  经典快速排序，思路和荷兰国旗问题中的预备题目一样：
 *           1.首先在数组[l,r]中把最后一个元素作为num进行比较，得到两段区域，分别为小于等于最后一个数的区域和大于最后一个数的区域。
             2.在上述第一段区域内，最后一个数的值为num保留不动，倒数第二个数重新命名为num，接着继续比较，不断迭代。
             3.在上述1的第二段区域内，把最后一个数命名为num，接着继续比较，不断迭代。
             4.迭代继续的条件是if(l<r)
 * @param[in] arr 输入数组
 * @param[in] l  需要处理区间的最小值
 * @param[in] r 需要处理区间的最大值
 * return 返回值为less：返回小于等于num的范围内最后一个元素的位置（最后一个位置就是原来的num），
 *       下次直接用倒数第二个位置元素（小于等于num区间的倒数第二个元素）作为下一次的num。
 */
int partition(vector<int> arr, int l, int r )
{
    int num = arr[r]; // 把最后一个数设为num进行比较
    int less = l - 1; // less为小于等于的区域，设为区域之前一个位置
    int cur = l; // cur是当前遍历的指针
    while (cur < r  + 1) { // 遍历所有位置
        if (arr[cur] <= num) {
            swap(arr[cur++], arr[++less]);
        } else {
            cur++;
        }
        return less;
    }
}
// 迭代部分
void QuickSort(vector<int> arr, int l, int r)
{
    if (l < r) { // 迭代的条件是在[l,r]范围内，如果越界表示不可继续分
        int pivot = partition(arr, l, r);
        QuickSort(arr, l, pivot - 1);
        QuickSort(arr, pivot + 1, r);
    }
}

/**
 * brief: 荷兰国旗改进的经典快排
 *       经典快排的缺点：每次只找出一个num进行排序，如果存在多个相同值的num还需要继续划分，多做了无用功。
 *                   考虑如果使用荷兰国旗的排序方法，将相同的num一次找出来，那么时间复杂度的常数时间就可以缩短。
 *                   荷兰国旗问题需要有两个指针记录小于num的范围和大于num的范围，考虑定义一个长度为2的数组记录下来，返回数组的指针用作下一步。
 * @param[in] arr 输入数组
 * @param[in] l  需要处理区间的最小值
 * @param[in] r 需要处理区间的最大值
 * @return 存放等于num值的索引最小值最大值的数组
 */

// 返回arr[r]在排序后的索引区间值
vector<int> partition(vector<int> arr, int l, int r)
{
    int num = arr[r]; // 首先在数组[l,r]中把最后一个元素作为num进行比较
    int less = l - 1; // less为小于等于num区间的之前的一个位置
    int more = r + 1;
    int cur = l;
    while (cur < more) {
        if (arr[cur] < num) {
            swap(arr[++less], arr[cur++]);
        } else if (arr[cur] > num) {
            swap(arr[cur], arr[--more]); // 此时cur并没有+1，因为交换后arr[cur]与num的大小关系未知
        } else {
            cur++;
        }
        return vector<int> {less + 1, more - 1};
    }
}

// 分治法迭代
void QuickSort(vector<int> arr, int l, int r)
{
    if (l < r) {
        vector<int> index = partition(arr, l, r); // index存储划分点
        QuickSort(arr, l, index[0] - 1); // [l, res[0] - 1]左子区间
        QuickSort(arr, index[1] + 1, r); // [res[1] + 1, r]右子区间
    }
}


/**
 * brief: 随机快排。
 *        荷兰国旗改进的经典快排缺点在于使用最后一个数作为num，
 *        例如[1,2，3,4,5,6]中复杂度就很高，因为此时复杂度就与数据状况有关了。
 *        考虑：在数组中随机选一个数作为num，这样就可以绕开原始数据状况，复杂度变成长期的期望值。
 */
// 分治法迭代
void QuickSort(vector<int> arr, int l, int r)
{
    if (l < r) {
        swap(arr[l+rand()%(r-l+1)], arr[r]); // 随机快排
        vector<int> index = partition(arr, l, r); // index存储划分点
        QuickSort(arr, l, index[0] - 1); // [l, res[0] - 1]左子区间
        QuickSort(arr, index[1] + 1, r); // [res[1] + 1, r]右子区间
    }
}


/**
    复杂度分析：
        时间复杂度为度O(NlogN)，额外空间复杂度O(logN)
        1.对于长期选择来说，随机成中间的值可能性最大，分治思想T(n) = 2T(N/2) + O(n)，时间复杂度为度O(NlogN)。
        2.随机查找时，二分多少次多少个断点，最好情况O(logN)，最差为O(N），概率上长期为O(logN)。
 */


/**
 * brief 经典快速排序(二)，基准数据找其正确索引位置的过程
 *       partition 函数找到分区后的第一个元素正确索引的位置
 * @param[in] arr 输入数组
 * @param[in] low 需要排序区间的下限值
 * @param[in] high 需要排序区间的上限值
 */

// 找到arr[low]的正确索引
int partition2(vector<int> arr, int low, int high)
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

void QuikSort(vector<int> arr, int low, int high)
{
    if (low < high) {
        int pivot = partition2(arr, low, high); // 找arr[low]正确索引的位置
        QuikSort(arr, low, pivot); // 分治法递归左半部分
        QuikSort(arr, pivot + 1, high); // 分治法递归右半部分
    }
}

/******************************************************************************
 * 堆排序 树中所有非终端结点的值均不大千（或不小千） 其左、右孩子结点的值
 ******************************************************************************/
 /**
  * 方法一：初始堆、调整堆
  */
  void AdjustHeap(vector<int> arr, int k)
 {
      int arr[0]
 }

 void BuildMaxHeap(vector<int> arr)
 {
     int len = arr.size();
     for (int i = len / 2; i > 0; ++i) { // 建初始堆
         AdjustHeap(arr, i);
     }
     for (int i = len; i > 1; --i) { // 沿着key较大的孩子节点向下调整
        AdjustHeap(arr, i);
     }
 }