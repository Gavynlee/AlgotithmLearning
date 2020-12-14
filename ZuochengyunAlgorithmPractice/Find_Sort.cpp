//
// Created by Jiwen-LI on 2020/8/22.
//
#include <bits/stdc++.h>
using namespace std;

/***************************************************************************
   查找算法
***************************************************************************/
//二分法查找
int BinarySearch(int a[],int val,int n)
{
    int low = 0,high = n -1,mid;
    while (low<= high) {
        mid = low + (low +high)/2; //取区间中点
        if (a[mid] == val)       //查找成功
            return mid;
        else if (a[mid] > val)   //在左区间中查找
            high = mid - 1;
        else                    //在右区间中查找
            low = mid + 1;
    }
    return -1; //查找失败
}

/***************************************************************************
   排序算法
***************************************************************************/

/**********************************************
   A. 插入排序算法
************************************************/
/*
 * (1) 直接插入排序
 * 插入排序是一种最简单的排序方法，
 * 它的基本思想是将一个记录插入到已经排好序的有序表中，
 * 从而一个新的、记录数增1的有序表。
 * 在其实现过程使用双层循环，外层循环对除了第一个元素之外的所有元素，
 * 内层循环对当前元素前面有序表进行待插入位置查找，并进行移动。
 * 类似于将新增的一张扑克牌插入到手中已经排好序的牌中的过程。
 */
void DirectInsertSort(vector<int> arr)
{
    if (arr.empty() || arr.size() < 2) {
        return;
    }
    for (int i = 1; i < arr.size() - 1; ++i) { //外层循环从第二个元素开始
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; --j) {
            swap(arr[j], arr[j + 1]); //如果新增的元素大于有序中的最后一个，则交换位置，更深层次的……
        }
    }
}

void DirectInsertSort(int A[],int n)
{
    int i,j;
    for (int i = 2; i <= n; ++i) {
        //如果待插入元素比有序序列的最后一个还大，则不用插入，直接放在原位置
        if (A[i] < A[i - 1]) {
            A[0] = A[i]; //设置监哨岗
            for (j = i - 1; A[0] < A[j]; --j) //边寻找（从后往前寻找）插入位置边移动元素
                A[j + 1] = A[j];     //退出循环时j+1为待插入元素的位置
            A[j + 1] = A[0]; //复制到插入位置
        }
    }
}
/*
    void DirectInsertSort(int A[],int n)
    {
        int i,j,k;
        for (int i = 2; i <= n; ++i) {
            A[0] = A[i]; //设置监哨岗
            for (j = i - 1; A[0] < A[j]; --j) //寻找A[i]插入位置（从后往前寻找）,退出循环时j+1为待插入元素的位置
            for (k = i - 1; k > j; --k)
                A[k + 1] = A[k]; //元素后移
            A[j + 1] = A[0];
        }
    }
*/


/*
 * （2）二分/折半插入排序
 */
void BinaryInsertSort(int A[],int n)
{
    int i,j,low,high,mid;
    //记录的是待插入的元素的下标，也就是说i-1之前的元素都是有序的
    for (i = 2; i <=n; ++i) {
       A[0] = A[i]; //保存待插入的值，监哨岗
       low = 1;high = i -1;
       while (low <= high) { //折半查找
           mid = low + (high - low)/2;
           if(A[mid] > A[0])
               high = mid - 1;
           else
               low = mid + 1;
       }  //循环结束，low为插入位置,low = high + 1
       //找到了待插入的位置，接下来从后往前依次后移元素腾出位置
       for (j = i - 1; j >= low; --j) //  for (j = i - 1; j >= high + 1; --j)
           A[j + 1] = A[j];
       A[low] = A[0]; // A[high + 1] = A[0]
    }
}


/*
 * （3）希尔排序
 */

//步长为d的一趟希尔排序,对比可知，直接插入排序是d = 1时的一趟希尔排序
void ShellInsert(int A[], int n, int d)
{
    int i,j;
    for (i = d + 1; i <= n; ++i) {
        if (A[i] < A[i - d]) {
            A[0] = A[i]; //设置监哨岗
            for (j = i - d; A[0] < A[j] && j > 0; j = j - d) //边寻找插入位置边移动元素
                A[j + d] = A[j];     //退出循环时j+d为待插入元素的位置
            A[j + d] = A[0];  //复制到插入位置
        }
    }
}

//确定步长序列dt[],循环调用ShellInsert
void ShellSort(int A[],int n, int dt[],int t)
{   //dt[]为步长序列，t为步长序列的长度
    for (int k = 0; k < t - 1; k ++)
        ShellInsert(A,n,dt[k]);
}

/**********************************************
   B. 交换排序算法
************************************************/
/*
 * (1) 冒泡排序
 */

//从最右端往左边两两比较，每一趟将最小的数移到左边
void BubbleSort(vector<int> arr)
{
    if (arr.empty() || arr.size() < 2) {    //如果数组为空或者个数为1，则无需排序
        return;
    }
    //最多进行arr.size() - 1趟排序
    for (int b = 0; b < arr.size() - 1; ++b) { //右端区间[b,arr.size()-1)为无序（区间宽度逐渐减小），左端区间有序
        int flag = 0;   //是否发生交换的标志
        for (int j = arr.size() - 1; j > b + 1; --j) { //第b趟左边b个已经有序,从最右边开始两两比较
            if (arr[j] < arr[j - 1]) { //如果前面元素比后面元素大则交换,将小值左移
                swap (arr[j], arr[j - 1]);
                flag = 1;   //发生了交换
            }
        }
        if (!flag) //如果某一趟排序没有交换，则说明已经有序
            break; //return;
    }
}

//从最左端往右边两两比较，每一趟将最大的数移到右边
void BubbleSort(vector<int> arr )                 //n为数组长度
{
    if (arr.empty() || arr.size() < 2) {         //如果数组为空或者个数为1，则无需排序
        return;
    }
    for (int e = arr.size() - 1; e > 0; --e) {  //左端区间[0,e]为无序（区间宽度逐渐减小），右端区间有序
        int flag = 0;                           //是否发生交换的标志
        for (int i = 0; i < e; ++i) {           //第e趟右边e个已经有序,从最左边开始两两比较
            if (arr[i] > arr[i + 1]) {          // 如果前面的值比后面值大，则进行交换顺序，将大值右移
                swap(arr[i],arr[i + 1]);
                flag = 1;                       //发生了交换
            }
        }
        if (!flag) {                            //如果某一趟排序没有交换，则说明已经有序
            break;
        }
    }
}


/*
 * (2) 快速排序
 */
int Partition(int A[], int low, int high)
{
    int pivot = A[low]; //第一个元素作为枢纽
    while (low < high) {
        while (low < high && A[high] >= pivot) --high; //从末尾找到第一个比枢轴小的元素
        A[low] = A[high]; //用high的元素替换low的元素
        while (low < high && A[low] <= pivot)  ++low; //再从开头找到第一个比枢轴小大的元素
        A[high] = A[low]; //用low的元素替换high的元素
    }
    A[low] = pivot; //枢纽元素存放到最终位置
    return low; //返回存放枢纽的最终位置
}

void QuickSort(int A[], int low, int high)
{
    if (low < high) { //if (low >= high) return;
        int pivotPos = Partition(A,low,high);
        QuickSort(A, low, pivotPos - 1); //分治递归左半部分
        QuickSort(A, pivotPos + 1, high); //分治递归右半部分
    }
}

/**********************************************
   C. 选择排序算法
************************************************/
/*
 * (1)//简单选择排序;
 * 第一次从待排序的数据元素中选出最小（或最大）的一个元素，
 * 存放在序列的起始位置，然后再从剩余的未排序元素中寻找到最小（大）元素，
 * 然后放到已排序的序列的末尾。以此类推，直到全部待排序的数据元素的个数为零。
 * 选择排序是不稳定的排序方法。
 */

void SimpleSelectSort(vector<int> arr)
{
    if (arr.empty() || arr.size()) {
        return;
    }
    for (int i = 0; i < arr.size() - 1; ++i) {  //最多arr.size() - 1 趟排序,无序区间[i,arr.size()-1]
        int minIndex = i; //每一趟将下表为i的元素初始化为最小值，其下标记为minIndex
        for (int j = i + 1; j < arr.size(); ++j) { //每一趟从无序中选出最小的数,将其下标赋值给minIndex
            minIndex = arr[j] < arr[minIndex] ? j : minIndex;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void SimpleSelectSort(int A[], int n)
{   int min; //min存放的是当前无序序列中最小元素所在下标，初始设置为第i个
    for (int i = 1; i <= n - 1; ++i) { //经过n - 1趟完成排序
        for(int j = i + 1, min = i; j < n; ++j)
            if (A[j] < A[min]) //如果这个值更小，则更新min值标
                min = j;       // 记为新最小元素的下标j
        if (min != i)   //如果第i个元素不是当前无序序列最小的，
            swap(A[min],A[i]);  // 则和最小的进行交换
    }
}




/*
 * （2）堆排序
 */
//大顶堆，调整堆
//A为存储堆的数组，len为数组长度（堆中元素个数），k为待检查的节点下标
void AdjustHeap(int A[], int len, int k)
{
    A[0] = A[k];
    for (int i = 2 * k; i <= len; i *= 2) { //从当前节点的左孩子开始往下比较（包括只有左孩子、有左右两个孩子两种情况）
        if (i < len && A[i] < A[i + 1]) //如果当前节点有右孩子且比左孩子大
            ++i;     //则考虑将当前节点和右孩子比较
        if (A[0] < A[i]) { //当前节点k和最大的孩子节点i比较
            A[k] = A[i];
            k = i; //从i开始继续往下检查，直到所有节点检查完毕
        }
        else
            break;
    }
    A[k] = A[0]; //检查到最后的k 值就是最后一轮交换过的节点位置下标
}

//堆排序算法的实现
void BuildMaxHeap(int A[], int len)
{
    for (int i = len/2; i > 0; --i)  //建立初始堆
        AdjustHeap(A,len,i);
    for (int i = len; i >= 2; --i) { //n - 1次筛选
        swap(A[1],A[i]); //堆中最后一个元素替代堆顶位置,A[1] = A[i]
        AdjustHeap(A,i - 1, 1); //堆中元素个数逐减，为i - 1
    }
}

/*
 * (3)归并排序
 */

/****************************************************************
  D. 归并排序
******************************************************************/
/*
 * 将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，
 * 再使子序列段间有序。若将两个有序表合并成一个有序表，称为二路归并。
 */
#if 0
void MergeSort(vector<int> arr, int l, int r);
void MergeSort(vector<int> arr)
{
    if (arr.empty() || arr.size() < 2) {
        return;
    }
    MergeSort(arr, 0, arr.size() - 1);
}

void merge(vector<int> arr, int l, int mid, int r);
void MergeSort(vector<int> arr, int l, int r)
{
    if (l == r) { //递归终止条件
        return;
    }
    int mid = l + ((r-l)>>1);
    MergeSort(arr, l, mid);  //T(n/2)
    MergeSort(arr,mid + 1, r); //T(n/2)
    merge(arr, l, mid, r);  //O(N)
    // T(N) = 2T(n/2) + O(N) --》时间复杂度：O(nlogn)
}

void merge(vector<int> arr, int l, int mid, int r)
{
    int* helper  = new int[r - l + 1]; //辅助数组，在辅助数组上排好序后拷贝到原数组,vector<int> helper(r - l + 1);
    int p1 = l;
    int p2 = r;
    int i = 0; //helper数组索引
    while (p1 <= mid && p2 <=r) {
        helper[i++] = arr[p1] < arr[p2] ? arr[p1] : arr[p2];
    }
    //两个且必有一个越界
    while (p1 <= mid) {
        helper[i++] = arr[p1++];
    }
    while (p2 <= r) {
        helper[i++] = arr[p2++];
    }
    for (i = 0;i < helper.size(); i++) {
        arr[l+i] = helper[i];
    }
    delete[] helper;
}

#endif