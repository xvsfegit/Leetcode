/*************************************************************************
	> File Name: trie.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 六 12/ 6 22:51:50 2014
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>

using namespace std;
const int MAX = 26;
const char a = 'a';
struct trie_node{
    bool is_str;
    string current_string;
    trie_node* next[MAX];
};

int read_pattern(vector<string>& pattern_vec)
{
    cout << "Please input the pattern end with eof!" << endl;
    while(1){
        string tmp;
        cin >> tmp;
        if(tmp == "eof"){
            break;
        } mZ        pattern_vec.push_back(tmp);
    }
    return pattern_vec.size();
}
trie_node* create_trie(const vector<string>& pattern_vec)
{
    trie_node* root = new trie_node;
    for(vector<string>::const_iterator piter = pattern_vec.begin();\
        piter != pattern_vec.end(); ++piter){
        trie_node* current_node = root;
        for(string::const_iterator siter = piter->begin() \
            ;siter != piter->end(); ++siter){
            unsigned int pos = *siter - a;
            if(current_node->next[pos] == NULL){
                current_node->next[pos] = new trie_node;     
            }
            current_node = current_node->next[pos];
        }     
        current_node->is_str = true;
        current_node->current_string = *piter;
    }
#ifdef DEBUG


#endif
    return root;
}


int main(int argc,char* argv[])
{
    vector<string> pattern_vec;
    read_pattern(pattern_vec);
    trie_node* root = create_trie(pattern_vec);
    return 0;
}
