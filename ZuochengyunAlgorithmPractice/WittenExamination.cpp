
/*************************************************************
 * 英伟达笔试2020/9/7
 *************************************************************/
#if 0
#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
bool visited[N];
int prime[N];
int total;
int mp[N];

void PrimeTable()
{
    for (int i = 3; i < 320; ++i) {
        if(!visited[i])
            for (int j = i*i; j < N; j += 2*i)
                visited[j] = true;
    }
    prime[total++] = 2;
    for (int i = 3; i < N; ++i)
        if ((i & 1) == 1 && !visited[i])
            prime[total++] = i;

}


int main()
{
    int n;
    PrimeTable();
    for(int i = 0; i < total; ++i)
        for (int j = i + 1;prime[i] + prime[j] <= 100000 && j < total; ++j) {
            mp[prime[i] + prime[j]]++;
        }
    while (scanf("%d",&n) != EOF)
        printf("%d\n",mp[n]);
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
string in[4];
int data[5];
char oper[4] = {'+','-','*','/'};
bool flag = false;

bool isOK()
{
    for (int i = 0; i < 4; ++i)
        if (in[i] == "Joker" || in[i] == "JOKER")
            return false;
    return true;
}

int weight(string s)
{
    int n;
    char ch = s[0];
    if (ch != 'J' && ch != 'Q' && ch != 'K' && ch != 'A')
        n = ch - '0';
    else if (ch == 'J')
        n = 11;
    else if (ch == 'Q')
        n = 12;
    else if (ch == 'K')
        n = 13;
    else
        n = 1;
    return n;
}

int caculateTwoVals(int &val1, int &val2, int index)
{
    switch (oper[index]) {
        case '+':
            return val1 + val2;
            break;
        case '-':
            return val1 - val2;
            break;
        case '*':
            return val1*val2;
            break;
        case '/':
        {
            if (val2 != 0  val2 % 2 == 0)
                return val1/val2;
            else
                return -100;
            break;
        }
        default :
            return -200;

    }
}

void caculateRes(int a1, int a2, int a3, int a4)
{
    for (int i = 0; i < 4; i ++0 ) {
        int sum = 0;
        if (flag = true)
           break;
        else {
            sum = caculateTwoVals(data[a1],data[a2], i);
            int temp = sum;
            for (int j= 0; j < 4; j ++) {
               if (flag = true)
                   break;
               else {
                   sum = caculateTwoVals(sum,data[a3], j);
                   int tmp = sum;
                   for (int k = 0; k < 4; k++) {
                       sum = caculateTwoVals(tmp,data[a4], k);
                       if (sum == 24 && flag == 0) {
                           cout << in[a1 -1] << oper[i] << in[a2-1]
                                << oper[j]<< in[a3-1] << oper[k]<< in[a4-1] << endl;
                           flag = true;
                           break;
                       }
                       sum = tmp;
                   }
               }
               sum = temp;
            }
            sum = temp;
        }
        sum = 0;
    }
}

int main (){
    while(cin >> in[0] >> in[1]>> in[2]>> in[3]) {
        if (isOK()) {
            data[0] = 0;
            for (int i = 0; i < 4; i++)
                data[i+1] = weight(in[i]);
            flag = 0;
            caculateRes(1,2,3,4);

        }
    }
}
#endif

/*************************************************************
 * 升序序列
 *************************************************************/
/*
 * 最长上升子序列(leetcode300)：给定一个无序的整数数组，找到其中
 * 最长上升子序列的长度。给定一个无序的整数数组，找到其中最长上升子序列的长度。
 */
#if 0
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> dp;
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) //不满足条件的
                    dp[i] = max(dp[j] + 1,dp[i]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
#endif
/*
 * 给定一个未排序的整数数组，找出最长连续序列的长度。leetcode128(最热题)
 */
#if 0
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> nums_set; //查找O(1)
        for (auto val:nums)
            nums_set.insert(val); //去重

        int maxLength = 1;
        for (auto val:nums) {
            //①如果没有val-1,则判断以val为起点的连续序列的元素个数，
            //②如果有a - 1，则忽略，遍历下一个,重复①
            if (!nums_set.count(val - 1)) {
                int currentNum = val;
                int baseCurrentLength = 1;

                while (nums_set.count(currentNum + 1)) { //找出以val为开头的连续数字序列的长度
                    currentNum += 1;
                    baseCurrentLength += 1;
                }
            maxLength = max(maxLength,baseCurrentLength); //每次循环更新最大长度
            }
        }
        return maxLength;
    }
};
#endif


/*
 * 美团
 */
#if 0
#include <bits/stdc++.h>
using namespace std;
int totalSolution (vector<int> input,int m,int k)
{
    int cnt = 0;
    if (input.empty() || m > input.size())
        return cnt;

    for (int i = 0, j = m ; i < input.size() && j < input.size() + 1; ++i, ++j) {
        vector<int> window;
        window.assign(input.begin()+i, input.begin()+j);
        sort(window.begin(),window.end());
        if (window[0] >= k){
            cnt++;
        }

    }
    return cnt;
}

int main()
{
    int n,m,k,val;
    cin >> n >> m >> k;
    vector<int> input;
    for(int i = 0; i < n;++i) {
        cin >> val;
        input.push_back(val);
    }
    int res = totalSolution(input,m,k);
    cout << res << endl;
}

#elif 0

#include <bits/stdc++.h>
using namespace std;

int totalSolution (vector<int> input, int n)
{
    int sum = 0;
    if (input.empty())
        return 0;

    sort(input.begin(),input.end());

    sum = input[0];
    int i = 0;
    while (sum <= n) {
        ++i;
        sum = sum + input[i];
    }
    return i;
}

int main()
{
    int n,m,val;
    cin >> n >> m;
    vector<int> input;
    for(int i = 0; i < m;++i) {
        cin >> val;
        input.push_back(val);
    }
    int res = totalSolution(input,n);
    cout << res << endl;
}
#elif 0

#include <bits/stdc++.h>
using namespace std;

void totalSolution (vector<vector<int> > &grids, int n)
{
    if (grids.empty())
        return;

    if (grids[n - 1][0] == 0 && grids[n - 2][0] == 1 && grids[n - 1][1] == 1 )
        grids[n - 1][0] = 1;
    if (grids[n - 1][n - 1] == 0 && grids[n - 2][n - 1] == 1 && grids[n - 1][n - 2] == 1 )
        grids[n - 1][n - 1] = 1;


    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if (i < n - 1 && grids[i][0] == 0 && grids[i][1] == 1 && grids[i + 1][1] == 1)
                grids[i][0] = 1;

            if (j < n - 1 && grids[0][j] == 0 && grids[1][j] == 1 && grids[1][j + 1] == 1)
                grids[i][0] = 1;

            if ( grids[i][j] == 0 && grids[i - 1][j] == 1 && grids[i + 1][j] == 1 &&
                    grids[i ][j-1] == 1 && grids[i ][j+ 1] == 1)
                grids[i][j] = 1;

            if (i < n - 1 && grids[i][n -1] == 0 && grids[i][j-1] == 1 && grids[i + 1][j] == 1)
                grids[i][n -1] = 1;

            if ( 0< j && j < n -1 && grids[n - 1][j] == 0 && grids[n - 1][j-1] == 1 && grids[n-1][j + 1] == 1 && grids[n - 2][j] == 1)
                grids[n - 1][j] = 1;
        }
    }
}

int main()
{
    int n,val;
    cin >> n ;
    vector<vector<int> > grids(n, vector<int> (n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> grids[i][j];

    totalSolution(grids,n);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            cout << grids[i][j];
        cout << endl;
    }

}

#endif

/*************************************************************
 * 回溯法，全排列leetcode46,leetcode47
 *************************************************************/


#if 0
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    for (vector<int>::size_type i = input.size(); i >=0 ; --i) {
        cout<< input[i] << endl;
    }

}

#elif 0
/**************************************************
 * leetcode46:给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 *************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
 * 路径：记录在 track 中
 * 选择列表：nums 中不存在于 track 的那些元素
 * 结束条件：nums 中的元素全都在 track 中出现
 */
void dfs(vector<int>& nums,vector<int>& path, vector<vector<int>>& res)
{
    //触发结束条件
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }

    //做选择
    for (int i = 0; i < nums.size(); ++i) {
        //if (path.contains(nums[i]))//排除不合法的选择，剪枝条件
        vector<int>::iterator iter = find(path.begin(),path.end(),nums[i]);
        if (iter != path.end())
            continue;
        path.push_back(nums[i]);
        //进入下一层决策树
        dfs(nums,path,res);
        //撤销选择
        path.pop_back();
    }
}

/*
 * 主函数，输⼊⼀组不重复的数字，返回它们的全排列
 */
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > res; //全局变量，保存所有的路径
    vector<int> path; //保存一次遍历的结果
    dfs(nums,path,res);
    return res;
}

int main()
{
    int n,val;
    while(cin >> n) {
       vector<int> nums;
       vector<vector<int> > output;
        for(int i = 0; i < n; ++i) {
            cin >> val;
            nums.push_back(val);
        }
        output = permute(nums);
        for (int i = 0; i < output.size(); ++i) {
            for (int j = 0; j < output[0].size(); ++j)
                cout << output[i][j] << " ";
            cout << endl;
        }
    }
}


#elif 0
/**************************************************
 * leetcode47:给定一个 有重复数字的序列，返回其所有可能的全排列。
 *************************************************/
#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& ans,
               int index, vector<int>& perm,vector<int> vis) //index,perm,vis均为状态变量
{
    if (index == nums.size()) {  //递归到的层数等于输入数组的个数时，触发结束条件
        ans.emplace_back(perm);
        return;
    }

    for (int i = 0; i < (int)nums.size(); ++i) { //剪枝条件
        if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]))
            continue;
        perm.emplace_back(nums[i]);
        vis[i] = 1;
        backtrack(nums, ans, index + 1, perm,vis);
        vis[i] = 0;
        perm.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<int> vis(nums.size(),0); //状态变量，标记访问节点与否
    vector<vector<int>> ans;
    vector<int> perm;
    sort(nums.begin(), nums.end());
    backtrack(nums, ans, 0, perm,vis); //index为记录已经访问过数字的个数，即递归到第index层
    return ans;
}

int main()
{
    int n,val;
    while(cin >> n) {
        vector<int> nums;
        vector<vector<int> > output;
        for(int i = 0; i < n; ++i) {
            cin >> val;
            nums.push_back(val);
        }
        output = permuteUnique(nums);
        for (int i = 0; i < output.size(); ++i) {
            for (int j = 0; j < output[0].size(); ++j)
                cout << output[i][j] << " ";
            cout << endl;
        }
    }
}
#elif 0

/**************************************************
 * leetcode
 *************************************************/

#include<iostream>

namespace A{
    void A1(){ std::cout << "我是A1" << std::endl; };
    class B{
    public:
        static void B1()
        {
            std::cout << "我是B1"<<std::endl;
        }
        void B2()
        {
            std::cout << "我是B2" << std::endl;
        }
    };
    namespace C{
        void C1()
        {
            std::cout << "我是C1" << std::endl;
        }
    }
}

int main(){
    using namespace A; //可访问命名空间A下的所有属性
    //访问A1
    A1();
    //访问B1，B2
    B::B1();
    //B::B2();  //error,不可访问，B2不是B类的静态函数，需先创建B类对象，再调用B2；
    //访问C1
    C::C1();
    //C1();   //error
    using namespace A::C; //可访问命名空间C下的所有属性
    C1();
    std::cin.get();
}
#elif 1

#include<iostream>
#include<vector>
#include<random>
#include<cassert>
#include<algorithm>
#include<ctime>

using namespace std;

default_random_engine e;

// 自己实现插入排序
void InsertSort(vector<int> &arr) {
    if (arr.size() < 2) {
        return;
    }
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i - 1; j >= 0 && arr[j + 1] < arr[j]; j--) {
            swap(arr[j], arr[j + 1]);
        }
    }
}

// for test
vector<int> generateRandomArray(int maxSize, int& size, int minValue, int maxValue) {
    assert(minValue < maxValue);
    size = e() % maxSize + 1;
    vector<int> arr(size);
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = e() % (maxValue - minValue) + minValue;
    }
    return arr;
}

// for test
vector<int> copyArray(vector<int> arr, const int n) {
    vector<int> arr2(n);
    arr2.assign(arr.begin(), arr.end());
    return arr2;
}

// for test
void rightMethod(vector<int>& arr, const int size) {
    sort(arr.begin(), arr.end());
}

// for test
bool isEqual(vector<int>& arr1, vector<int>& arr2, const int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

// for test
void printArray(vector<int>& arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void testAlgorithm() {
    int testTime = 500000;
    int maxSize = 10;
    int minValue = -100;
    int maxValue = 100;
    bool succeed = true;
    clock_t startTime, endTime;
    int size = 0;
    startTime = clock();
    for (int i = 0; i < testTime; i++) {
        vector<int> arr = generateRandomArray(maxSize, size, minValue, maxValue);
        vector<int> arr1 = copyArray(arr, size);
        vector<int> arr2 = copyArray(arr, size);
        InsertSort(arr1);
        rightMethod(arr2, size);
        if (!isEqual(arr1, arr2, size)) {
            succeed = false;
            printArray(arr2, size);
            break;
        }
    }
    cout << (succeed ? "NICE" : "FUCKED") << endl;
    endTime = clock();
    cout << "time cost:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

int main()
{
    testAlgorithm();

    system("PAUSE");
    return 0;
}

#endif
