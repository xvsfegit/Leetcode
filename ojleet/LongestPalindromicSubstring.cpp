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
            //枚举子串所有可能的长度
            for(int i = 0;i <= slen - k; ++i){
                //枚举所有该长度的字串，看是否为回文
                if(s[i] == s[i + k - 1] && dp[i + 1][i + k - 2]){
                    dp[i][i + k - 1] = true;
                    if(resRight - resLeft + 1 < k){
                        resLeft = i;
                        resRight = i + k - 1;
                    }
                }        
            }
        }
        return s.substr(resLeft,resRight - resLeft + 1);
    }


};
int main(int argc,char* argv[])
{
    cout << "Please input the string:";
    string s;
    cin >> s;
    Solution testClass;
    cout << testClass.longestPalindrome(s) << endl;
    return 0;
}
