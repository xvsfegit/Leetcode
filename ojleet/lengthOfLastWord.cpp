/*************************************************************************
	> File Name: lengthOfLastWord.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 四 12/25 21:59:49 2014
 ************************************************************************/

#include<iostream>
using namespace std;

int lengthOfLastWord(const char* s)
{
    int length = 0;
    bool flag = false;
    if(s == NULL){
        return 0;
    }
    while(*s != '\0'){
        if(*s == 0x20){
            flag = true;
        }
        else{
            if(flag){
                length = 0;
                flag = false;
            }
            ++length;
        }
        ++s;
    }
    return length;
}

int main(int argc,char* argv[])
{
    string tmp;
    cin >> tmp;
    cout << lengthOfLastWord(tmp.c_str()) << endl;
    return 0;
}
