/*************************************************************************
	> File Name: zigzag.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 四 12/18 20:17:08 2014
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;
string convert(const string& s,int nRows)
{
    if(nRows <= 1 || s.size() == 0){
        return s;
    }
    int slen = s.size();
    string result;
    for(int i = 0;i < nRows; ++i){
        int j = i;
        bool flag = true;
        while(j < slen){
            result.push_back(s[j]);
            if(i == 0 || i == nRows - 1){
                j += 2 * (nRows - 1);
            }
            else{
                if(flag){
                    j += 2 * (nRows - i - 1);
                    flag = false;
                }
                else{
                    j += 2 * i;
                    flag = true;
                }
            }
        }
    }
    return result;
}
int main(int argc,char* argv[])
{
    cout << convert("PAYPALISHIRING",4) << endl;
    return 0;
}
