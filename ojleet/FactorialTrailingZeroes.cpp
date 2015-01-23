/*************************************************************************
	> File Name: FactorialTrailingZeroes.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2015年01月23日 星期五 21时23分47秒
 ************************************************************************/

#include<iostream>
using namespace std;

int trailingZeroes(int n)
{
    int count = 0;
    for(int i = 5;(n / i) >= 1;){
        count += n / i;
        n /= 5;
    }
    return count;
}
int main(int argc,char* argv[])
{
    cout << "Please input the in value:";
    int value;
    cin >> value;
    cout << trailingZeroes(value) << endl;
    return 0;
}
