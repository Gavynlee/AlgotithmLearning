//
// Created by Gavyn on 2020/9/2.
//
/*
 * 走方格，礼物的最大价值
 */
#if 0
#include <bits/stdc++.h>
using namespace std;
int getMaxValue(vector<vector<int> > &grid)
{
    if(grid.empty() || grid[0].empty())
        return 0;
    int m = grid.size(), n = grid[0].size();

    vector<vector<int> > dp(m,vector<int>(n,0));

    dp[0][0] = grid[0][0];
    for(int j = 1;j < n; ++j)
        dp[0][j] = dp[0][j -1] + grid[0][j];
    for(int i = 1;i < m; ++i)
        dp[i][0] = dp[i -1][0] + grid[i][0];

    for (int i = 1; i < m;++i)
        for (int j = 1; j<n ; ++j)
            dp[i][j]= grid[i][j]+max(dp[i][j-1],dp[i-1][j]);

    return dp[m-1][n-1];
}


int main()
{
    int val,m,n;
    cin >> m >> n;
    vector<vector<int> > input(m,vector<int>(n));

    for(int i = 0; i< m; ++i)
        for(int j = 0; j < n;++j) {
            cin >> val;
            input[i][j] = val;
        }

    int res = getMaxValue(input);
    cout << res << endl;
    return 0;
}
#endif


/*
 * 走方格，最小成本和最大效益
 */
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
void helper(vector<vector<pair<int, int>>>& grids, int& max_profit, int& min_cost) {
    int rows = grids.size();
    if(rows == 0)
        return;
    int cols = grids[0].size();
    if(cols == 0)
        return;

    vector<vector<pair<int, int>>> dp(rows, vector<pair<int, int>>(cols, make_pair(0, 0)));
    dp[0][0] = make_pair(grids[0][0].first, grids[0][0].second);
    for(int i = 1; i < rows; ++i) {
        dp[i][0].first += dp[i - 1][0].first + grids[i][0].first;
        dp[i][0].second += dp[i - 1][0].second + grids[i][0].second;
    }
    for(int i = 1; i < cols; ++i) {
        dp[0][i].first += dp[0][i - 1].first + grids[0][i].first;
        dp[0][i].second += dp[0][i - 1].second + grids[0][i].second;
    }

    for(int i = 1; i < rows; ++i) {
        for(int j = 1; j < cols; ++j) {
            if(dp[i - 1][j].first < dp[i][j - 1].first) {
                dp[i][j].first = dp[i - 1][j].first + grids[i][j].first;
                dp[i][j].second = dp[i - 1][j].second + grids[i][j].second;
            }  else if(dp[i - 1][j].first > dp[i][j - 1].first) {
                dp[i][j].first = dp[i][j - 1].first + grids[i][j].first;
                dp[i][j].second = dp[i][j - 1].second + grids[i][j].second;
            } else {
                dp[i][j].first = dp[i - 1][j].first + grids[i][j].first;
                dp[i][j].second = max(dp[i - 1][j].second, dp[i][j - 1].second) + grids[i][j].second;
            }
        }
    }
    min_cost = dp[rows - 1][cols - 1].first;
    max_profit = dp[rows - 1][cols - 1].second;
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> grids(n, vector<pair<int, int>>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grids[i][j].first;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grids[i][j].second;
        }
    }

    int max_profit = 0, min_cost = 0;
    helper(grids, max_profit, min_cost);
    cout << min_cost << " " <<  max_profit << endl;
}
#endif


/*
 * 串流的使用
 */
#if 0
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string res;
    cin >> n;
    int i;
    for(i = 2; i <n; ) {
        if (n % i == 0) {
            stringstream result;
            result << i;
            res = res + result.str();
            res = res + "*";
            n = n / i;
            i = 2;
        } else
            ++i;
    }
    cout << res <<  n << endl;
}
#elif 0
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    vector<int> input;
    string str;
    getline(cin, str);
    int val;
    stringstream ss(str);
    while (ss >> val)
    {
        input.push_back(val);
    }
    for (auto m : input)
        cout << m << " ";
    cout << endl;
    return 0;
}
#endif



#if 0
#include <bits/stdc++.h>
using namespace std;

char* DeleteLine(char * str){
    char *begin = str;
    char *next = str;
    while (*next) {
        if (*next != '_') {
            *begin = *next;
            begin++;
        }

        if (*next == '_' && *(next-1) != '_') {
            *begin = *next;
            begin++;
        }
        next++;
    }
    *begin = '\0';
    return  str;
}

int main ()
{
    string s;
    getline(cin,s);
    int len = s.size();
    char str[len];
    for(int i = 0; i<len; ++i)
        str[i] = s[i];
    char * res = DeleteLine(str);
    cout<<res<<endl;
    return 0;
}
#endif

/*
 * 起点为a,b…z,步长为k,step
 */
#if 0
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int , char> mp;
    for(int i = 97; i <= 122; ++i){
        mp[i - 96] = i;
    }
    int n,k,step;
    char ch;
    cin >> n ;
    string s;
    for(int i = 0; i < n;++i) {
        cin>>ch>>k>> step;
        long long  total = ch - 'a' + 1 + k*step;
        int key = total % 26;
        s+= mp[key];
    }

    for(int i = 0; i < s.size();++i)
        cout << s[i] << endl;
}
#endif

/*
 * 滑动窗口,时间复杂度O（n）~ O（2n）
 */
#if 0
#include<bits/stdc++.h>
using namespace std;

//方法一：滑动窗口,时间复杂度O（n）~ O（2n）
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        unordered_map<char,int> mp;
        int left = 0, right = 0; //left，right控制窗口大小
        int windowSize = 0;

        for (int i = 0; i < s.size(); ++i) {
            while (mp.find(s[i]) != mp.end())  //找到相同的时候，删除左边的直到与s[i]相等的下一个位置
                mp.erase(s[left++]);

            mp[s[i]] = i; //mp找不到与当前相同的元素，则加入到mp中并扩大窗口
            right++;
            windowSize = max(right - left,windowSize);
        }
        return windowSize;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution S;
    int res = S.lengthOfLongestSubstring(s);
    cout << res << endl;
    return 0;
}
#endif

/************************************************************************
 * 动态规划
 * *********************************************************************/

/*
 * 动态规划走方格
 */
#if 0
class Solution {
public:
    // 使用动态规划解题,能够到达每个格子，只能是从他的上方或者左侧到达
    int uniquePaths(int m, int n) {
        // 建立dp
        // vector<vector<int>>dp(m, vector<int>(n, 0));
        int[][] dp = new int[m][n];	//只用到0、1、2……m-1,故数组开m,不是m+1

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j) {
                if (i == 0 || j == 0)	//初始化
                    dp[i][j] = 1;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
        delete[][] dp;
    }
};

//单独初始化
// dp[0][0] = 1;
// for(int j=0; j<n; ++j)	// 填充第一行(边界)
//    dp[0][j] = 1;
// for(int i=0; i<m; ++i)	// 填充第一列(边界)
//     dp[i][0] = 1;

#endif

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (arr.empty() || k <=0 || k > arr.size())
            return res;
        int low = 0,high = arr.size() - 1;
        int index = partition(arr,low,high);
        while (index != k - 1) {
            if (index < k - 1)
                low = index + 1;
            else
                high = index - 1;
            index = partition(arr,low,high);
        }
        res.assign(arr.begin(),arr.begin() + k);
        return res;
    }

    int partition(vector<int> A, int low, int high)
    {
        int pivot = A[low];
        while (low < high) {
            while (low < high && A[high] >= pivot) high--;
            A[low] = A[high];
            while (low < high && A[low] <= pivot) low++;
            A[high] = A[low];
        }
        A[low] = pivot;
        return low;
    }
};