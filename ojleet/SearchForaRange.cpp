/*************************************************************************
	> File Name: SearchForaRange.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 一  3/21 00:07:14 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> tmpResult;
        for(int i = 0;i < nums.size(); ++i){
            if(nums[i] == target){
                tmpResult.push_back(i);
            }
        }
        vector<int> result;
        if(tmpResult.empty()){
            result.push_back(-1);
            result.push_back(-1);
        }
        else{
            result.push_back(tmpResult[0]);
            result.push_back(tmpResult[tmpResult.size() - 1]);
        }
        return result;
    }
};

int main(int argc,char* argv[]){
    return 0;
}