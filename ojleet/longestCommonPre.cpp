/*************************************************************************
	> File Name: longestCommonPre.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 六 12/20 11:37:22 2014
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;

string longestCommonPre(const vector<string>& strs)
{
    int vec_len = strs.size();    
    if(vec_len == 0){
        return "";
    }
    if(vec_len == 1){
        return strs[0];
    }
    string tmp = strs[0];
    int count = 0;
    int max_pre = 0;
    for(int i = 1;i < vec_len; ++i){
        count = 0;
        if(tmp[0] != strs[i][0]){
            return "";
        }
        ++count;
        for(int j = 1;j < tmp.size()&& j < strs[i].size(); ++j){
            if(tmp[j] == strs[i][j]){
                ++count; 
            }
            else if(count > max_pre){
                max_pre = count;
            }
        }        
    }
    string result(&tmp[0],max_pre);
    return result;
}


int main()
{
    string tmp;
    vector<string> strs;
    while(tmp != "eof"){
        cin >> tmp;
        strs.push_back(tmp);
    } 
    cout << longestCommonPre(strs) << endl;
    return 0;
}
