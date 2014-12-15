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

    if(x == 0){
        return x;
    }
    int n = 0;
    int y = 0;
    while(x != 0){
        n = x % 10;
        if(y > MAX_INT/10 || y < MIN_INT/10){
            return 0;
        }
        y = y * 10 + n;
        x = x / 10;
    }
    return y;
}
int main(int argc,char* argv[])
{
    cout << "Please input the int:";
    int x = 0;
    cin >> x;
    cout << x << endl;
    cout << reverse(x) << endl;
    return 0;
}
