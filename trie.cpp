/*************************************************************************
	> File Name: trie.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2014年12月05日 星期五 16时29分03秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>

using namespace std;
const int MAX = 26;
const char a = 'a';
struct trie_node{
    bool is_str;
    unsigned int count;
    string current_string;
    trie_node* next[MAX];
    trie_node():count(0)
    {
    }
};

int read_pattern(vector<string>& pattern_vec)
{
    cout << "Please input the pattern end with eof!" << endl;
    while(1){
        string tmp;
        cin >> tmp;
        if(tmp == "eof"){
            break;
        }         
        pattern_vec.push_back(tmp);
    }
    return pattern_vec.size();
}
trie_node* create_trie(const vector<string>& pattern_vec)
{
    trie_node* root = new trie_node;
    trie_node* current_node = NULL;
    for(vector<string>::const_iterator piter = pattern_vec.begin();\
        piter != pattern_vec.end(); ++piter){
        current_node = root;
        for(string::const_iterator siter = piter->begin() \
            ;siter != piter->end(); ++siter){
            unsigned int pos = *siter - a;
            if(current_node->next[pos] == NULL){
                current_node->next[pos] = new trie_node;     
            }
            current_node = current_node->next[pos];
            ++(current_node->count);
        }     
        current_node->is_str = true;
        current_node->current_string = *piter;
    }
    return root;
}
void find_exstring(const trie_node* root,const string& text)
{
    for(string::const_iterator siter = text.begin(); \
        siter != text.end(); ++siter){
        while(root->next[*siter - a]){
            root = root->next[*siter - a];
            if(root->is_str){
                cout << root->current_string << endl;
            }
        }
    } 
}


int main(int argc,char* argv[])
{
    vector<string> pattern_vec;
    read_pattern(pattern_vec);
    trie_node* root = create_trie(pattern_vec);
    cout << "Please input the text:" << endl;
    string text;
    cin >> text;
    find_exstring(root,text);
    return 0;
}
