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
        for(int j = 0;j < tmp.size() && j < strs[i].size();){
            if(tmp[j] == strs[i][j]){
                ++count; 
            }
            else if(count < max_pre || i == 1){
                max_pre = count;
                break;
            }
            ++j;
        }        
        if(count == strs[i].size() || count == strs[0].size()){
            if(i == 1){
                max_pre = count;
            }
            else if(max_pre > count){
                max_pre = count;
            }
        }
    }
    string result(&tmp[0],max_pre);
    return result;
}


int main(int argc,char* argv[])
{
    string tmp;
    vector<string> strs;
    while(1){
        cin >> tmp;
        if(tmp == "eof")
            break;
        strs.push_back(tmp);
    } 
    cout << longestCommonPre(strs) << endl;
    return 0;
}
