/*************************************************************************
	> File Name: romantoint.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2014年12月16日 星期二 02时28分00秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;
int charToInt(char a)
{
    switch(a){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
}
int romanToInt(const string s){
    int result = charToInt(s[0]); 
    for(int i = 1;i < s.size(); ++i){
        int cur = charToInt(s[i]);
        int pre = charToInt(s[i - 1]);
        if(cur <= pre){
            result += cur; 
        }
        else{
            result = result - pre * 2 + cur;
        }
    }
    return result;
}
int main(int argc,char* argv[])
{
    cout << "Please input the Roman Int:";
    string tmp;
    cin >> tmp;
    cout << romanToInt(tmp) << endl;
    return 0;
}

