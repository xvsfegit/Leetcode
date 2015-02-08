/*************************************************************************
	> File Name: LongestSubstringWithOutRepeatCharacters.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 五  2/ 6 22:56:23 2015
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution{
public:
    int lengthOfLongestSubstring(string& s)
    {
        int slen = s.size();
        if(slen == 0){
            return 0;
        }
        int subMaxLen = 0;
        int currentLen = 0;
        map<char,int> repeatMap; 
        for(int i = 0;i < slen; ++i){
            int tmpLen = i + 1 - repeatMap[s[i]];
            repeatMap[s[i]] = i + 1;
            if(tmpLen > currentLen){
                ++currentLen;
            }
            else{
                if(currentLen > subMaxLen){
                    subMaxLen = currentLen;
                }
                currentLen = tmpLen;
            }
        }
        if(currentLen > subMaxLen){
            subMaxLen = currentLen;
        }
        return subMaxLen;
    }
};

int main(int argc,char* argv[])
{
    cout << "Please input the string:";
    string s;
    cin >> s;
    Solution testClass;
    cout << testClass.lengthOfLongestSubstring(s) << endl;
}
