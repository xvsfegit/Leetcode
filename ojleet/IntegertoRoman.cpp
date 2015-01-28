/*************************************************************************
	> File Name: IntegertoRoman.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2015年01月28日 星期三 00时09分20秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    string intToRoman(int num)
    {
        string result;
        string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for(int i = 0;num != 0;++i){
            while(num >= value[i]){
                num -= value[i];
                result += symbol[i];
            }
        }
        return result;
    }
};

int main(int argc,char* argv[])
{
    cout << "Please input the int:";
    int value;
    cin >> value;
    Solution testClass;
    cout << testClass.intToRoman(value) << endl;
    return 0;
}
