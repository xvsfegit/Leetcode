/*************************************************************************
	> File Name: MergeSortedArray.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2014年12月26日 星期五 04时44分58秒
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

int* merge(int A[],int m,int B[],int n)
{
    if(m == 0){
        memcpy(A,B,n * 4);
        return NULL;
    }
    if(n == 0){
        return NULL;
    }
    int* result = new int[m + n];
    int i = 0;
    int j = 0;
    int count = 0;
    while(1){
        if(i < m && A[i] <= B[j]){
            result[count] = A[i];
            ++i;
        }
        else if(j < n){
            result[count] = B[j];
            ++j;
        }
        else{
            result[count] = A[i];
            ++i;
        }
        ++count;
        if(count >= m + n){
            break;
        }
    }
    return result;
}

int main(int argc,char* argv[])
{
    int A[1] = {2};
    int B[1] = {1};
    int* a = merge(A,1,B,1);
    for(int i = 0;i < 2; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
