/*************************************************************************
	> File Name: 3sum.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 二  3/ 3 22:14:50 2015
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int> > threeSum(vector<int>& num)
    {
        vector<vector<int> > result;
        sort(num.begin(),num.end());
        int numLen = num.size();
        for(int i = 0; i < numLen - 2; ++i){
            if(i > 0 && num[i] == num[i - 1]){
                continue;
            }
            twoSum(num,i + 1,0 - num[i],result);
        }
        return result;
    }
    void twoSum(vector<int>& sortNum,int start,int target,vector<vector<int> >& res)
    {
        int head = start;
        int tail = sortNum.size() - 1;
        while(head < tail){
            int tmpSum = sortNum[head] + sortNum[tail];
            if(tmpSum < target){
                ++head;
            }
            else if(tmpSum > target){
                --tail;
            }
            else{
                int tmpArray[3] = {sortNum[start - 1],sortNum[head],sortNum[tail]};
                res.push_back(vector<int>(tmpArray,tmpArray + 3));
                int k = head + 1;
                while(k < tail && sortNum[k] == sortNum[head]) ++k;
                head = k;
                k = tail - 1;
                while(k > head && sortNum[k] == sortNum[tail]) --k;
                tail = k;
            }
        }
    }
};

int main(int argc,char* argv[])
{
    int a[3] = {-1,0,1};
    vector<int> tmp(a,a + 3);
    return 0;
}
