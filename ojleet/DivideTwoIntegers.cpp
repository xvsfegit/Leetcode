/*************************************************************************
	> File Name: DivideTwoIntegers.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 五 12/18 23:51:35 2015
 ************************************************************************/

#include<iostream>
#include<limits>
using namespace std;

class Solution {
public:
    int sign(int x)
    {
        return x < 0 ? -1 : 1;
    }
    int divide(int dividend, int divisor) {
        /*
        auto sign = [=](int x) {
            return x < 0 ? -1 : 1;
        };
        */
        int d1 = sign(dividend);
        int d2 = sign(divisor);
        long long n1 = abs(static_cast<long long>(dividend));
        long long n2 = abs(static_cast<long long>(divisor));
        long long ans = 0;
        while(n1 >= n2) {
            long long base = n2;
            for(int i = 0 ; n1 >= base ; ++i) {
                n1 -= base;
                base <<= 1;
                ans +=  1LL << i;
            }
        }
        if(d1 != d2){
            ans = -ans;
        }
        
        if(ans <= INT_MAX && ans > INT_MIN){
            return static_cast<int>(ans);
        }
        else if(ans > INT_MAX){
            return INT_MAX;
        }
        else{
            return INT_MIN;
        }
    }
};

int main(int argc,char* argv[])
{
    int dividend = 0;
    int divisor = 0;
    cout << "Please input dividend:";
    cin >> dividend;
    cout << "Please input divisor:";
    cin >> divisor;
    Solution testClass;
    cout << testClass.divide(dividend,divisor) << endl;

    return 0;
}
