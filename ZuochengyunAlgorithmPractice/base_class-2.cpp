//
// Created by Gavyn on 2020/12/14.
//
#include <bits/stdc++.h>
using namespace std;

/******************************************************************************
 * 问题一：荷兰国旗问题引入
 * 给定一个数组arr，和一个数num，请把小于等于num的数放在数组的左边，大于num的数放在数组的右边。
 * 要求额外空间复杂度O(1)，时间复杂度O(N)
 ******************************************************************************/
/*
  * @brief partition函数和快排中的partion一样
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

/******************************************************************************
 * 问题二（荷兰国旗问题）
 * 给定一个数组arr，和一个数num，请把小于num的数放在数组的左边，
 * 等于num的数放在数组的中间，大于num的数放在数组的右边。
 * 要求额外空间复杂度O(1)，时间复杂度O(N)
 ******************************************************************************/
 /*
  * @brief partition函数和快排中的partion一样
  * @param[in] arr 输入数组
  * @param[in] l  需要处理区间的最小值
  * @param[in] r 需要处理区间的最大值
  * @param[in] num 需要比较的值
  * @return 存放等于num值索引最小值最大值的数组
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
