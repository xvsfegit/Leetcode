/*************************************************************************
	> File Name: ValidPalndrome.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 一  1/26 22:58:00 2015
 ************************************************************************/

#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;


bool isPalindrome(const string& s)
{
    int slen = s.size();
    if(slen == 0){
        return true;
    }
    for(int i = 0,j = slen - 1;i < j; ++i,--j){
        while(i < j && (s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < '0' || s[i] > '9')){
            ++i;
        }
        while(i < j && (s[j] < 'a' || s[j] > 'z') && (s[j] < 'A' || s[j] > 'Z') && (s[j] < '0' || s[j] > '9')){
            --j;
        }
        if(tolower(s[i]) - tolower(s[j])){
            return false; 
        }
    }
    return true;
}

int main(int argc,char* argv[])
{
    cout << "Please input the string:";
    string inputString;
    getline(cin,inputString);
    cout << isPalindrome(inputString) << endl;
    return 0;
}
