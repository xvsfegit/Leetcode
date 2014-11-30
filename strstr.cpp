/*************************************************************************
	> File Name: strstr.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2014年11月30日 星期日 10时22分07秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
using namespace std;
int violent_match(const char*,const char*);


int main(int argc,char* argv[])
{
    string pattern;
    string text;
    std::cout << "Please input the Text: ";
    std::cin >> text;
    std::cout << "Please input the Pattern: ";
    std::cin >> pattern;
    if(text.empty() || pattern.empty()){
        std::cout << "Your input is wrong! Please try again!" << std::endl;
        exit(1);
    }
    int result = violent_match(text.c_str(),pattern.c_str());
    if(result == -1){
        std::cout << "The pattern is not in text!" << std::endl;
    }
    else{
        std::cout << "The pattern pos is:" << result << std::endl;
    }
    return 0;
}
int violent_match(const char* t,const char* p)
{
    int tlen = strlen(t);
    int plen = strlen(p);
    int i = 0,j = 0;
    while(i < tlen && j < plen){
        if(t[i] == p[j]){
            ++i;
            ++j;
        }
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == plen){
        return i - j;
    }
    return -1;
}
