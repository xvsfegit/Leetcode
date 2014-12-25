/*************************************************************************
	> File Name: LIS.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2014年12月25日 星期四 00时24分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
int lis(int A[],int n)
{
    if(n == 0){
        return 0;
    }
    int len = 1;
    int d[n];
    for(int i = 0;i < n; ++i){
        d[i] = 1;
        for(int j = 0;j < i; ++j){
            if(A[i] >= A[j] && d[j] + 1 > d[i]){
                d[i] = d[j] + 1;
            }
        }
        if(len < d[i]){
            len = d[i];
        }
    }
    return len;
}
/*
 */
int main(int argc,char* argv[])
{
    int A[6] = {5,3,4,8,6,7};
    cout << lis(A,6) << endl;
    return 0;
}
