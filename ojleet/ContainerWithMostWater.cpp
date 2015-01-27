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
    /*complete with the o(n2)
     */
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
    /*will use o(n) complete it
     *当从两边开始移动时，因为底边的长度是最大的，所以无论移动i,j底边都在减小
     *而面积的大小取决于两个height的最小值，所以需要移动小的height去寻找下一个
     *比当前大的面积。该算法虽然不会得到全部面积，但可以求的最大面积。
     */
    int maxArea_2(vector<int>& height)
    {
        int len = height.size();
        int left = 0;
        int right = len - 1;
        int maxValue = 0;
        while(left < right){
            int h = min(height[left],height[right]);
            maxValue = max(maxValue,(right - left) * h);
            height[left] < height[right] ? ++left : --right;
        }
        return maxValue;
    }
};

int main(int argc,char* argv[])
{
    int a[10] = {15,24,55,66,14,45,78,56,43,22};
    vector<int> height(a,a + 10);
    Solution testClass;
    cout << testClass.maxArea_1(height) << endl;
    cout << testClass.maxArea_2(height) << endl;
    return 0;
}
