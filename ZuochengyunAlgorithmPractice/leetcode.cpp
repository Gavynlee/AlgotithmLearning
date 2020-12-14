//
// Created by Gavyn on 2020/10/8.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    * 主函数
    */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; //全局变量，保存所有的路径
        vector<int> track; //保存一次遍历的结果
        backtrack(nums,track,res);
        return res;
    }
    /*
    * 深度优先遍历
    */
    void backtrack(vector<int>& nums,vector<int>& track, vector<vector<int>>& res)
    {
        //结束条件
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }

        //做选择
        for (int i = 0; i < nums.size(); ++i) {
            //排除不合法的选择
            vector<int>::iterator iter=find(track.begin(),track.end(),nums[i]);
            if (iter != track.end())
                continue;
            track.push_back(nums[i]);
            //进入下一层决策树
            backtrack(nums,track,res);
            //撤销选择
            track.pop_back();
        }
    }
};

class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; //全局变量存储答案
        // 记录「路径」
        vector<int> track; //全局变量存储路径
        backtrack(nums, track, res);
        return res;
    }


    void backtrack(vector<int>& nums, vector<int>& track, vector<vector<int>>& res) {
        //触发结束条件
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            //if (track.contains(nums[i]))//排除不合法的选择
            vector<int>::iterator iter = find(track.begin(), track.end(), nums[i]);
            if(iter != track.end()) //nums[i]在track中时，此时为不合法的选择
                continue;
            //做选择
            track.push_back(nums[i]);
            //进入下一层决策树
            backtrack(nums, track, res);
            //取消选择
            track.pop_back();
        }
    }
};