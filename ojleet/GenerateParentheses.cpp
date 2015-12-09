/*************************************************************************
	> File Name: GenerateParentheses.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 日 11/29 09:59:18 2015
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        if(n == 0){
            return result;
        }
        string tempString;
        generateDeep(n,n,tempString,result);
        for(int i;i < result.size(); ++i){
            std::cout << result[i] << std::endl;
        }
        return result;
    }
    void generateDeep(int leftNum,int rightNum,string& s,vector<string>& result)
    {
        if(leftNum == 0 && rightNum == 0){
            result.push_back(s);
        }        
        if(leftNum > 0){
            generateDeep(leftNum - 1,rightNum,s.append("("),result);
        }
        if(rightNum > 0 && leftNum < rightNum){
            generateDeep(leftNum,rightNum - 1,s.append(")"),result);
        }
    }
};

int main(int argc,char* argv[])
{
    Solution testClass;
    testClass.generateParenthesis(2);
    return 0;
}
