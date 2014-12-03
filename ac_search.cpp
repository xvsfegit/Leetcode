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
#include<set>
#include<memory.h>

using namespace std;
const int PATTERN_NUM = 4;
const int MAX_STATE = 20;
const int ALP = 26; 
const char a = 'a';
int _GOTO_TABLE[MAX_STATE][ALP];
int _FAIL_TABLE[MAX_STATE];
std::set<string> _out[MAX_STATE];


void read_pattern(vector<string>& pattern_vec)
{
    cout << "Please input the pattern:" << endl;
    string tmp;
    for(int i=0;i < PATTERN_NUM; ++i){
        cin >> tmp;
        pattern_vec.push_back(tmp);
    }   
}

void build_fail_table(const vector<string>& pattern_vec)
{
    unsigned int t = 0;
    unsigned int m = 0;
    unsigned int last_state = 0;
    unsigned int s[20];
    string::const_iterator sit1;
    string::const_iterator sit2;
    string::const_iterator sit3;
    for(vector<string>::const_iterator piter = pattern_vec.begin() \
        ;piter != pattern_vec.end(); ++piter){
        t = 0;
        m = 0;
        sit1 = piter->begin();
        while(sit1 != piter->end() && _GOTO_TABLE[t][*sit1 - a] != 0){
            t = _GOTO_TABLE[t][*sit1 - a];                 
            ++sit1;
        }
    }       
}

void build_goto_table(const vector<string>& pattern_vec)
{
    int used_state = 0;
    for(vector<string>::const_iterator piter = pattern_vec.begin();piter != pattern_vec.end(); ++piter){
        string::const_iterator sit = piter->begin();
        int t = 0;
        for(;sit != piter->end(); ++sit){
            if(_GOTO_TABLE[t][(*sit) - a] == 0){
                _GOTO_TABLE[t][(*sit) - a] = ++used_state;
                t = used_state;
            }   
            else{
                t = _GOTO_TABLE[t][(*sit) - a];    
            }
        }
        _out[t].insert(*piter);
    }
#ifdef DEBUG
    for(int i = 0;i < MAX_STATE; ++i){
        for(int j = 0;j < ALP; ++j){
            cout << _GOTO_TABLE[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0;i != MAX_STATE; ++i){
        int len = _out[i].size();
        if(len != 0){
            set<string>::const_iterator iter = _out[i].begin();
            cout << i << ":";
            for(;iter != _out[i].end(); ++iter){
                cout << *iter << " ";
            }
            cout << endl;
        }
    }
#endif
    
}

int main(int argc,char* argv[])
{
    memset(_GOTO_TABLE,0,MAX_STATE * ALP * 4);
    vector<string> pattern_vec;
    read_pattern(pattern_vec);
    build_goto_table(pattern_vec);
    return 0;
}

