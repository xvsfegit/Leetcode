/*************************************************************************
	> File Name: CompareVersionNumbers.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2015年01月18日 星期日 23时57分06秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int strToInt(const char* beginPos,int len)
{
    string tmpStr(beginPos,len);
    return atoi(tmpStr.c_str());
}

int compareInt(int a,int b){
    if(a == b){
        return 0;
    }
    else if(a > b){
        return 1; 
    }
    else{
        return -1;
    }
}


int compareVersion(string version1,string version2)
{
    int i = 0;
    int j = 0;
    while(i < version1.size() && j < version2.size()){
        if(version1[i] != '.'){
            ++i;
        }
        
    }
    return -1;
}

int main(int argc,char* argv[])
{
    return 0;
}
