/*************************************************************************
	> File Name: kmp.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2014年11月30日 星期日 13时42分50秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<string>
#include<stdlib.h>
using namespace std;

int kmp_search(const char*,const char*,const int*);
void build_next(const char* p,int* next)
{
    int plen = strlen(p);
    int k = -1;
    int j = k + 1;
    next[j] = k;
    while(j < plen){
        if(k == -1 || p[k] == p[j]){
            next[j + 1] = k + 1;
            ++k;
            ++j;
        }
        else{
            k = next[k];
        }
    }
}

int main(int argc,char* argv[])
{
    std::string text;
    std::string pattern;
    std::cout << "Please input the Text:";
    std::cin >> text;
    std::cout << "Please input the Pattern:";
    std::cin >> pattern;
    int* next = new int[pattern.size()];
    build_next(pattern.c_str(),next);
    for(int i = 0;i < pattern.size(); ++i){
        cout << next[i] << " ";
    }
    std::cout << endl;
    int pos = kmp_search(text.c_str(),pattern.c_str(),next);
    if(pos == -1){
        std::cout << "Sorry can't found!" << std::endl;
    }
    else{
        std::cout << "The pattern pos is:" << pos << std::endl; 
    }
    delete [] next;
    return 0;
}

int kmp_search(const char* t,const char* p,const int* next)
{
    int tlen = strlen(t);
    int plen = strlen(p);
    int i = 0,j = 0;
    while(i < tlen && j < plen){
        if(j == -1 || t[i] == p[j]){
            ++i;
            ++j;
        }
        else{
            j = next[j];
        }
    }
    if(j == plen){
        return i - j;
    }
    return -1;
}
