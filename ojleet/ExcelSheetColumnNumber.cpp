/*************************************************************************
	> File Name: ExcelSheetColumnNumber.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 二  2/ 3 09:48:44 2015
 ************************************************************************/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

const char A = 'A';

int titleToNumber(const string& s)
{
    if(s.empty()){
        return 0;
    }
    int result = 0;
    int facor = 1;
    for(int i = s.size() - 1;i >= 0; --i){
        result += (s[i] - A + 1) * facor;
        facor *= 26;
    }
    return result;
}

int main(int argc,char* argv[])
{
    cout << "Please input the string:";
    string svalue;
    cin >> svalue;
    cout << titleToNumber(svalue) << endl;
}
