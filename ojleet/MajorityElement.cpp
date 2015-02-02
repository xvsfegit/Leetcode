/*************************************************************************
	> File Name: MajorityElement.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 一  2/ 2 23:07:06 2015
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


int MajorityElement(vector<int>& num)
{
    int count = 1;
    int value = num[0];
    for(int i = 1;i < num.size(); ++i){
        if(value == num[i]){
            ++count;
        }
        else{
            --count;
            if(count < 0){
                value = num[i];
                count = 1;
            }
        }
    }
    return value;
}


int main(int argc,char* argv[])
{
    int a[10] = {1,5,3,5,3,5,5,3,5,6};
    int b[5] = {10,9,9,9,10};
    vector<int> testVec(b,b + 5);
    cout << MajorityElement(testVec) << endl;
    return 0;
}
