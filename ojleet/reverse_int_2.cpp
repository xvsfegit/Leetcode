/*************************************************************************
	> File Name: reverse_int.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 四 12/18 21:24:53 2014
 ************************************************************************/

#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int reverse(int x){
    const int MAX = 9;
    const int MAX_INT = 2147483647;
    const int MIN_INT = -2147483648;

    if(x == 0){
        return x;
    }
     
    return x;
}
int main(int argc,char* argv[])
{
    cout << "Please input the int:";
    int x = 0;
    cin >> x;
    cout << x << endl;
    cout << reverse(x) << endl;
    return 0;
}
