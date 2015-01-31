/*************************************************************************
	> File Name: CompareVersionNumbers.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2015年01月18日 星期日 23时57分06秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;


int compareVersion(string version1,string version2)
{
    int flag = 0;
    for(int i = 0,j = 0;i < version1.size() && j < version2.size();){
        if(version1[i] != '.'){
            ++i;
        }
        else{
            flag = 1;
        }
        if(version2[j] != '.'){
            ++j;
        }
        else{
            flag += 1;
        }
        if(flag == 2){
            if(i == j){

            }
            else if (i < j){
                return -1;
            }
            else{
                return 0;
            }
        }
    }
    return -1;
}

int main(int argc,char* argv[])
{
    return 0;
}
