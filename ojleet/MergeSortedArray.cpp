/*************************************************************************
	> File Name: MergeSortedArray.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2014年12月26日 星期五 04时44分58秒
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

void merge(int A[],int m,int B[],int n)
{
    if(m == 0){
        memcpy(A,B,n);
    }
    if(n == 0){
        return;
    }
    int i = 0;
    int j = 0;
    int tmp = 0;
    while(i < m && j < n){
        if(A[i] <= B[j]){
            ++i;
        }
        else{

        }
    }
}

int main(int argc,char* argv[])
{
    return 0;
}
