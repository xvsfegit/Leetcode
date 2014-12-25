/*************************************************************************
	> File Name: climbingStairs.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 日  1/ 4 22:07:05 2015
 ************************************************************************/

#include<iostream>
using namespace std;

int climbStairs(int n)
{
    if(n == 0){
        return 0;
    }
    int d[n + 1];
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    for(int i = 3;i < n + 1;++i){
        d[i] = d[i - 2] + d[i - 1];
    }
    return d[n];
}


int main(int argc,char* argv[])
{
    cout << "Please input the stairs:";
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}
