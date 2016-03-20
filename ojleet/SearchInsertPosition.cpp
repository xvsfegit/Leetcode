#include<vecotr>
#include<iostream>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        for(;i < nums.size(); ++i){
            if(nums[i] >= target){
                break;
            }
        }
        return i;
    }
};
int main(int argc,char* argv[]){
    return 0;
}