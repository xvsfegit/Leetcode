/*************************************************************************
	> File Name: addBinary.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2014年12月23日 星期二 23时26分17秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string addBinary(string a,string b)
{
    const char zero = '0';
    int tmp = 0;
    int i = 0;
    int j = 0;
    string result;
    for (i = a.size() - 1,j = b.size() - 1;i >= 0 && j >= 0; --i,--j){
        int a_value = a[i] - zero;
        int b_value = b[j] - zero;
        tmp = a_value + b_value + tmp;
        result.push_back(zero + (tmp % 2));
        if(tmp >= 2){
            tmp = 1;
        }
        else{
            tmp = 0;
        }
    }
    string& remainString = a;
    int remainLen = 0;
    i > 0 ? remainLen = i:(remainString = b,remainLen = j);
    for(int i = remainLen;i >= 0; --i){
        tmp = tmp + remainString[i] - zero;
        if(tmp > 1){
            tmp = 1;
        }
        else{
            tmp = 0;
        }
        result.push_back(zero + (tmp % 2));
    }
    if(tmp){
        result.push_back(tmp);
    }
    //return result.assign(result.rbegin(),result.rend());
    return result;
}

int main(int argc,char* argv[])
{
    string a;
    string b;
    cin >> a >> b;
    cout << addBinary(a,b) << endl;
    return 0;
}
