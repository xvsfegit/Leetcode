/*************************************************************************
	> File Name: ContainerWithMostWater.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2015年01月27日 星期二 21时47分43秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution{
public:
    int maxArea_1(vector<int>& height)
    {
        int len = height.size();
        if(len <= 1){
            return 0;
        }
        int maxValue = 0;
        for(int i = 0;i < len - 1; ++i){
            for(int j = i + 1;j < len; ++j){
                int h = min(height[i],height[j]);
                int bottom = j - i;
                if(maxValue < (bottom * h)){
                    maxValue = bottom * h;
                }
            }
        }
        return maxValue;
    }
};

int main(int argc,char* argv[])
{
    return 0;
}
