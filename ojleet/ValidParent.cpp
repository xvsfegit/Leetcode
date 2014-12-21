/*************************************************************************
	> File Name: ValidParent.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 日 12/21 22:19:50 2014
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string& s)
{
    stack<char> c_stack;
    for(int i = 0;i < s.size(); ++i){
        switch(s[i]){
            case '(':
            case '[':
            case '{':
                c_stack.push(s[i]);
                continue;
            default:
            {
                if(c_stack.top() == s[i])
                    c_stack.pop();
                else
                    return false;
                continue;
            }
        }
    }
    return true;
}
int main(int argc,char* argv[])
{
    cout << "Please input the s:";
    string tmp;
    cin >> tmp;
    cout << isValid(tmp) << endl; 
    return 0;
}
