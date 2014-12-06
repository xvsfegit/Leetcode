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
struct trie_node{
    bool is_str;
    trie_node* next[MAX];
};
struct trie{
    trie_node* root;
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


int main(int argc,char* argv[])
{
    return 0;
}
