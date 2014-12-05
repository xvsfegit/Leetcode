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
#include<map>

using namespace std;
const int PATTERN_NUM = 100;
const int MAX_STATE = 100;
const int ALP = 26; 
const char a = 'a';
unsigned int _GOTO_TABLE[MAX_STATE][ALP];
unsigned int _FAIL_TABLE[MAX_STATE];
std::map<int,set<string> > _out;
//std::set<string> _out[MAX_STATE];


void read_pattern(vector<string>& pattern_vec)
{
    set<string> test;
    cout << "Please input the pattern eof is end :" << endl;
    string tmp;
    for(int i=0;i < PATTERN_NUM; ++i){
        cin >> tmp;
        if(tmp == "eof"){
            break;
        }
        pattern_vec.push_back(tmp);
    }   
#ifdef DEBUG
    cout << "****************PATTERN INFO***************" << endl;
    for(int i = 0;i != pattern_vec.size(); ++i){
        cout << i << ":" << pattern_vec[i] << endl;
    }
    cout << "****************PATTERN INFO***************" << endl;
#endif
}

void build_fail_table(const vector<string>& pattern_vec)
{
    unsigned int t = 0;
    unsigned int m = 0;
    unsigned int last_state = 0;
    unsigned int state[100];
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
            state[m++] = t; 
        }
        for(sit1 = piter->begin() + 1;sit1 != piter->end(); ++sit1){
            for(sit2 = piter->begin() + 1; sit2 != sit1 + 1; ++sit2){
                t = 0;
                sit3 = sit2;
                while(sit3 != sit1 + 1 && _GOTO_TABLE[t][*sit3 -a] != 0){
                    t = _GOTO_TABLE[t][*sit3 - a];
                    ++sit3;
                }
                if(sit3 == sit1 + 1){
                    last_state = state[sit3 - (piter->begin()) - 1];
                    if(_FAIL_TABLE[last_state] == 0){
                        _FAIL_TABLE[last_state] = t;
                    }
                    if(!_out[last_state].empty() && !_out[t].empty()){
                        for(set<string>::const_iterator siter = _out[t].begin() \
                            ;siter != _out[t].end(); ++siter){
                            _out[last_state].insert(*siter);
                        }    
                    }
                }
            }
        }
    }       
#ifdef DEBUG
    cout << "****************FAIL TABLE INFO***************" << endl;
    for(int i = 0;i < MAX_STATE; ++i){
        if(_FAIL_TABLE[i] != 0){
            cout <<"state_"<< i << ":" << _FAIL_TABLE[i] << endl;
        }
    }
    cout << "****************FAIL TABLE INFO***************" << endl;
#endif
}

void build_goto_table(const vector<string>& pattern_vec)
{
    int used_state = 0;
    set<string> tmp;
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
    cout << "****************GOTO TABLE INFO***************" << endl;
    for(int i = 0;i < MAX_STATE; ++i){
        for(int j = 0;j < ALP; ++j){
            cout << _GOTO_TABLE[i][j] << " ";
        }
        cout << endl;
    }
    cout << "****************GOTO TABLE INFO***************" << endl;
    cout << "****************OUT TABLE INFO***************" << endl;
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
    cout << "****************OUT TABLE INFO***************" << endl;
#endif
}
void ac_search(const string& text)
{
    int t = 0;
    set<string> match_res;
    string::const_iterator siter = text.begin();  
    while(siter != text.end()){
        if(t == 0){
            if(_GOTO_TABLE[t][*siter -a] == 0){
                ++siter;
                continue;
            }
        }
        if(_GOTO_TABLE[t][*siter - a] == 0){
            t = _FAIL_TABLE[t];
            while(t != 0 && _GOTO_TABLE[t][*siter - a] == 0){
                t = _FAIL_TABLE[t];    
            }
        }
        t = _GOTO_TABLE[t][*siter - a];
        ++siter;
        if(_out[t].size()){
            for(set<string>::const_iterator iter = _out[t].begin(); \
                iter != _out[t].end(); ++iter){
                match_res.insert(*iter);
            }
        }
    }
    cout << "The match pattern:";
    for(set<string>::const_iterator iter = match_res.begin();\
        iter != match_res.end(); ++iter){
        cout << *iter << ",";
    }
    cout << endl;
}

int main(int argc,char* argv[])
{
    memset(_GOTO_TABLE,0,MAX_STATE * ALP * 4);
    vector<string> pattern_vec;
    read_pattern(pattern_vec);
    build_goto_table(pattern_vec);
    build_fail_table(pattern_vec);
    string text;
    cout << "Please input the text:" << endl;
    cin >> text;
    ac_search(text);
    return 0;
}

