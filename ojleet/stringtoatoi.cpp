/*************************************************************************
	> File Name: stringtoatoi.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2014年12月15日 星期一 20时33分23秒
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

int test_atoi(const char* str)
{
    const int MAX_INT = 2147483647;
    const int MIN_INT = -2147483648;
    bool flag = false;
    while(*str == 0x20){
        ++str;
    }
    if(*str == '-'){
        flag = true;
        ++str;
    }
    else if(*str == '+'){
        ++str;
    }
    const int slen = strlen(str); 
    if(slen == 0){
        return 0;
    }
    long long res = 0;
    int count = 0;
    while('0' <= *str && *str <= '9'){
        res = res * 10 + (*str - '0');
        if(res >= MAX_INT)
            return MAX_INT;
        if(res <= MIN_INT)
            return MIN_INT;
        ++str;
    }
    if(flag){
        res = -res;
    }
    return res;
    
}

int main(int argc,char* argv[])
{
    cout << "Please input the string:";
    string tmp;
    cin >> tmp;
    cout << test_atoi(tmp.c_str()) << endl; 
    return 0;
}
