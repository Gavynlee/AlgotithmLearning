//
// Created by Gavyn on 2020/12/13.
//

/***************************************************************
   A. 插入排序算法
*****************************************************************/
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

/***************************************************************
   B. 交换排序算法
*****************************************************************/
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


/*****************************************************************
   C. 选择排序算法
*******************************************************************/
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

#elif 0
/*
 * 归并排序应用-小和问题
 */
int MergeSort(vector<int> arr, int l, int r);
int SmallSum(vector<int> arr)
{
    if (arr.empty() || arr.size() < 2) {
        return 0;
    }
    MergeSort(arr, 0, arr.size() - 1);
}

int merge(vector<int> arr, int l, int mid, int r);
int MergeSort(vector<int> arr, int l, int r)
{
    if (l == r) { //递归终止条件
        return 0;
    }
    int mid = l + ((r-l)>>1);
    return MergeSort(arr, l, mid) + MergeSort(arr,mid + 1, r) + merge(arr, l, mid, r);
    // T(N) = 2T(n/2) + O(N) --》时间复杂度：O(nlogn)
}

int merge(vector<int> arr, int l, int mid, int r)
{
    int* helper  = new int[r - l + 1]; //辅助数组，在辅助数组上排好序后拷贝到原数组,vector<int> helper(r - l + 1);
    int p1 = l;
    int p2 = r;
    int i = 0; //helper数组索引
    int res = 0; //和上面归并排序中merge函数唯一的区别即是增加了返回res功能
    while (p1 <= mid && p2 <=r) {
        res += arr[p1] < arr[p2] ? (r - p2 + 1) * arr[p1] : 0;
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
    return res;
}

#elif 1
class Small_Sum {
public:
    int SmallSum(vector<int> arr)
    {
        if (arr.empty() || arr.size() < 2) {
            return 0;
        }
        MergeSort(arr, 0, arr.size() - 1);
    }

    int MergeSort(vector<int> arr, int l, int r)
    {
        if (l == r) { //递归终止条件
            return 0;
        }
        int mid = l + ((r-l)>>1);
        return MergeSort(arr, l, mid) + MergeSort(arr,mid + 1, r) + merge(arr, l, mid, r);
        // T(N) = 2T(n/2) + O(N) --》时间复杂度：O(nlogn)
    }

    int merge(vector<int> arr, int l, int mid, int r)
    {
        int* helper  = new int[r - l + 1]; //辅助数组，在辅助数组上排好序后拷贝到原数组,vector<int> helper(r - l + 1);
        int p1 = l;
        int p2 = r;
        int i = 0; //helper数组索引
        int res = 0; //和上面归并排序中merge函数唯一的区别即是增加了返回res功能
        while (p1 <= mid && p2 <=r) {
            res += arr[p1] < arr[p2] ? (r - p2 + 1) * arr[p1] : 0;
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
        return res;
    }
};

#endif