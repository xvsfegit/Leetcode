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
#include<cmath>
using namespace std;

class Solution{
public:
    int threeSumCloset(vector<int>& num,int target)
    {
        int numLen = num.size();
        int result = num[0] + num[1] + num[2];
        sort(num.begin(),num.end());
        for(int i = 0; i < numLen - 2; ++i){
            int start = i + 1;
            int tail = numLen - 1;
            while(start < tail){
                int sum = num[i] + num[start] + num[tail];
                if(abs(result - target) > abs(sum - target)){
                    result = sum;
                }
                if(sum > target){
                    --tail;
                }
                else if(sum < target){
                    ++start;
                }
                else{
                    ++start;
                    --tail;
                }
            }
        }
        return result;
    }
};



int main(int argc,char* argv[])
{
    int a[135] = {87,6,-100,-19,10,-8,-58,56,14,-1,-42,-45,-17,10,20,-4,13,-17,0,11,-44,65,74,-48,30,-91,13,-53,76,-69,-19,-69,16,78,-56,27,41,67,-79,-2,30,-13,-60,39,95,64,-12,45,-52,45,-44,73,97,100,-19,-16,-26,58,-61,53,70,1,-83,11,-35,-7,61,30,17,98,29,52,75,-73,-73,-23,-75,91,3,-57,91,50,42,74,-7,62,17,-91,55,94,-21,-36,73,19,-61,-82,73,1,-10,-40,11,54,-81,20,40,-29,96,89,57,10,-16,-34,-56,69,76,49,76,82,80,58,-47,12,17,77,-75,-24,11,-45,60,65,55,-89,49,-19,4};
    vector<int> tmp(a,a + 135);
    Solution testClass;
    cout << testClass.threeSumCloset(tmp,-275) << endl;
    return 0;
}
