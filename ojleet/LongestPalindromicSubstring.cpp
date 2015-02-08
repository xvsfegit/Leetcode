/*************************************************************************
	> File Name: LongestPalindromicSubstring.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 日  2/ 8 13:46:14 2015
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class Solution{
public:
    string longestPalindrome(const string& s)
    {
        const int slen = s.size();
        if(slen <= 1){
            return s;
        }
        string result;
        bool dp[slen][slen];
        memset(dp,0,sizeof(dp));
        dp[0][0] = true;
        int resLeft = 0;
        int resRight = 0;
        for(int i = 1;i < slen; ++i){
            dp[i][i] = true;
            dp[i][i - 1] = true;
        }
        for(int k = 2;k <= slen; ++k){
            for(int i = 0;i < slen - k; ++i){

            }
        }
        return result;
    }


};
int main(int argc,char* argv[])
{

}
