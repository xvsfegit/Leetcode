/*************************************************************************
	> File Name: MinStack.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2015年01月12日 星期一 09时32分26秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class MinStack{
public:
    int minElement;
    stack<int> intStack;
    stack<int> mininmStack;
    void push(int x)
    {
        intStack.push(x);
    }
    void pop()
    {
        intStack.pop();
    }
    int top()
    {
        return intStack.top();  
    }
    int getMin()
    {
        return 0;
    }
};
int main(int argc,char* argv[])
{
    MinStack testCase;
    return 0;
}
