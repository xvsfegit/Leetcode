/*************************************************************************
	> File Name: palindromeNumber.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2014年12月16日 星期二 00时51分09秒
 ************************************************************************/

#include<iostream>
using namespace std;
bool isPalindrome(int x)
{
    const int MAX_INT = 2147483647;
    if(x > MAX_INT || x < 0){
        return false;
    }
    long long y = 0;
    int z = x;
    while(x != 0){
        y = y * 10 + x % 10;
        x = x / 10;
    }
    if(y == z){
        return true;
    }
    return false;    
}
int main(int argc,char* argv[])
{
    cout << "Please input the number:";
    int x;
    cin >> x;
    cout << x << endl;
    cout << isPalindrome(x)<< endl;
    return 0;
}
