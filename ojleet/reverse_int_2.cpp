/*************************************************************************
	> File Name: reverse_int.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 四 12/18 21:24:53 2014
 ************************************************************************/

#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int reverse(int x){
    const int MAX_INT = 2147483647;
    const int MIN_INT = -2147483648;
    int n = 0;
    long long y = 0;
    while(x != 0){
        n = x % 10;
        y = y * 10 + n;
        x = x / 10;
    }
    if(y > MAX_INT || y < MIN_INT){
        return 0;
    }
    return y;
}
int main(int argc,char* argv[])
{
    cout << "Please input the int:";
    int x = 0;
    cin >> x;
    cout << reverse(x) << endl;
    return 0;
}
