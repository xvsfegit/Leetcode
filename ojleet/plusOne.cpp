/*************************************************************************
	> File Name: plusOne.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2014年12月23日 星期二 22时25分53秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    int tmp = 0;
    for(int i = digits.size() - 1;i >= 0; --i){
        tmp = ++digits[i] - 10;
        if(tmp  < 0){
            tmp = 0;
            break;
        }
        digits[i] = tmp;
        tmp = 1;
    }
    if(tmp == 1)
        digits.insert(digits.begin(),1);
    return digits;
}

int main(int argc,char* argv[])
{
    return 0;
}
