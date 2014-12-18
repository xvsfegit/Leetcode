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
    const int MAX = 9;
    const int MAX_INT = 2147483647;
    const int MIN_INT = -2147483648;

    if(x == 0){
        return x;
    }
    
    int flag = 0;
    if(x < 0){
        x = abs(x);
        flag = 1; 
    }   
    int value[MAX];
    string result;
    value[0] = x % 10;
    for(int i = MAX - 1;i > 0; --i){
        int base = pow(10,i);
        value[i] = x / base;
        x = x % base;
    }
    for(int i = 0;i < MAX; ++i){
        result.push_back('0' + value[i]);      
    }
    x = atoi(result.c_str());
    while(x % 10 == 0){
        x = x / 10;
    }
    if(flag){
        x = -x;
    }
    return x;
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
