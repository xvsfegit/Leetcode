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
    bool flag = false;
    for(int i = 0;i < s.size(); ++i){
        switch(s[i]){
            case '(':
            case '[':
            case '{':
                c_stack.push(s[i]);
                continue;
            default:
            {
                if(c_stack.size() == 0){
                    return false;
                }            
                flag = true;
                char tmp = c_stack.top();
                if(s[i] == '}' && tmp == '{'){
                    c_stack.pop();
                }
                else if(s[i] == ']' && tmp == '['){
                    c_stack.pop();            
                }
                else if(s[i] == ')' && tmp == '('){
                    c_stack.pop();             
                }
                else{
                    return false;
                }
            }
                           
        }
    }
    if(c_stack.empty())
        return true && flag;
    return false;
}
int main(int argc,char* argv[])
{
    cout << "Please input the s:";
    string tmp;
    cin >> tmp;
    cout << isValid(tmp) << endl; 
    return 0;
}
