/*************************************************************************
	> File Name: ac_search.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 二 12/ 2 21:26:41 2014
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<vector>
const int PATTERN_NUM = 5;
const int MAX_STATE = 100;
const int ALP = 26; 
int _GOTO_TABLE[MAX_STATE][ALP];
int _FAIL_TABLE[MAX_STATE];
using namespace std;

void read_pattern(vector<string>& pattern_vec)
{
    cout << "Please input the pattern:" << endl;
    string tmp;
    for(int i=0;i < PATTERN_NUM; ++i){
        cin >> tmp;
        pattern_vec.push_back(tmp);
    }   
}

int build_goto_table(const vector<string>& pattern_vec)
{
    const char a = 'a';
    int used_state = 0;
    int t = 0;

    for(vector<string>::const_iterator piter = pattern_vec.begin();piter != pattern_vec.end(); ++piter){
        for(int i = 0;i != (*piter).size(); ++i){
            if(_GOTO_TABLE[t][piter[i] - a] == 0){
                _GOTO_TABLE[t][piter[i] - a] == ++used_state;
                t = used_state;
            }   
            else{
                t = _GOTO_TABLE[t][piter[i] - a];    
            }
        }
    }
    
}

int main(int argc,char* argv[])
{
    vector<string> pattern_vec;
    read_pattern(pattern_vec);
    cout << pattern_vec.size() << endl;
    return 0;
}

