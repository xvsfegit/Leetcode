/*************************************************************************
	> File Name: TwoSum.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2015年01月24日 星期六 01时20分34秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> twoSum_1(vector<int>& numbers,int target)
{
    vector<int> result;
    for(int j = 1;j < numbers.size(); ++j){
        int remainValue = target - numbers[j];
        for(int i = 0;i < j; ++i){
            if(numbers[i] == remainValue){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}


vector<int> twoSum_2(vector<int>& numbers,int target)
{
    vector<int> result;
    map<int,int> valueMap;
    int vecLen = numbers.size();
    for(int i = 0;i < vecLen; ++i){
        int remainValue = valueMap[target - numbers[i]];
        if(remainValue){
            result.push_back(remainValue);
            result.push_back(i + 1);
            break;
        }
        valueMap[numbers[i]] = i + 1;
    }
    return result;
}



int main(int argc,char* argv[])
{
    int a[13] = {2,3,5,6,7,8,9,10,100,22,565,99,56};
    vector<int> numbers(a,a + 13);
    cout <<"Please input the target:";
    int target = 0;
    cin >> target;
    vector<int> result = twoSum_2(numbers,target);
    for(int i = 0;i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
