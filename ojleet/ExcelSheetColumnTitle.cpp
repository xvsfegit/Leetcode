/*************************************************************************
	> File Name: ExcelSheetColumnTitle.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 一  2/ 2 21:39:00 2015
 ************************************************************************/

#include<iostream>
using namespace std;

const char A = 'A';
string convertToTitle(int n)
{
    string result;
    while(n > 0){
        --n;
        result =static_cast<char>(n % 26 + A) + result;
        n = n / 26;
    }
    return result;
}

int main(int argc,char* argv[])
{
    return 0;
}
