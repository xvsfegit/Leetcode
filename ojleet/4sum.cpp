/*************************************************************************
	> File Name: 4sum.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 五 10/ 9 23:49:28 2015
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector< vector<int> > forsum(vector<int>& nums,int target)
    {
        vector< vector<int> > result;
        int numLen = nums.size();
        if(numLen < 4){
            return result;
        }
        sort(nums.begin(),nums.end());
        set < vector<int> > tmpres;
        for(int i = 0;i < numLen; ++i){
            for(int j = i + 1;j < numLen; ++j){
                int begin = j + 1;
                int end = numLen - 1;
                while(begin < end){
                    int sum = nums[i] + nums[j] + nums[begin] + nums[end];
                    if(sum == target){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[begin]);
                        tmp.push_back(nums[end]);
                        tmpres.insert(tmp);
                        ++begin;
                        --end;
                    }
                    else if(sum > target){
                        --end;
                    }
                    else{
                        ++begin;
                    }
                }
            }
        }
        set< vector<int> >::const_iterator iter = tmpres.begin();
        for(;iter != tmpres.end(); ++iter){
            result.push_back(*iter);
        }
        return result; 
    }
};


int main(int argc,char* argv[])
{
    return 0;
}



