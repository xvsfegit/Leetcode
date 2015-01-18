/*************************************************************************
	> File Name: MinStack.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2015年01月12日 星期一 09时32分26秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
class MinStack{
public:
    stack<int> intStack;
    stack<int> minStack;
    void push(int x)
    {
        intStack.push(x);
        if(minStack.empty()){
            minStack.push(x);
        }
        else{
            if(x <= minStack.top()){
                minStack.push(x);
            }
        }
    }
    void pop()
    {
        if(!intStack.empty()){
            int popValue = intStack.top();
            if(popValue == minStack.top()){
                minStack.pop();
            }
            intStack.pop();
        }
    }
    int top()
    {
        if(intStack.empty()){
            return 0;
        }
        return intStack.top();  
    }
    int getMin()
    {
        if(minStack.empty()){
            return 0;
        }
        else{
            return minStack.top();
        }
    }
};
int main(int argc,char* argv[])
{
    MinStack testCase;
    testCase.push(2147483646);
    testCase.push(2147483646);
    testCase.push(2147483647);
    testCase.top();
    testCase.pop();
    cout << testCase.getMin() << endl;
    testCase.pop();
    cout << testCase.getMin() << endl;
    testCase.pop();
    testCase.push(2147483647);
    testCase.top();
    cout << testCase.getMin() << endl;
    testCase.push(-2147483648);
    testCase.top();
    cout << testCase.getMin() << endl;
    testCase.pop();
    cout << testCase.getMin() << endl;

    return 0;
}
