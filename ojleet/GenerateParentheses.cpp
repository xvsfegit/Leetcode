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
        generateDeep(n,n,"",result);
        return result;
    }
    void generateDeep(int leftNum,int rightNum,string s,vector<string>& result)
    {
        if(leftNum == 0 && rightNum == 0){
            result.push_back(s);
        }        
        else{
            if(leftNum > 0){
                generateDeep(leftNum - 1,rightNum,s + '(' ,result);
            }
            if(rightNum > 0 && leftNum < rightNum){
                generateDeep(leftNum,rightNum - 1,s + ')',result);
            }       
        }
    }
};

int main(int argc,char* argv[])
{
    int n = 0;
    cout << "The number you want input:";
    cin >> n;
    vector<string> result;
    Solution testClass;
    result = testClass.generateParenthesis(n);
    for(int i = 0;i < result.size(); ++i){
        std::cout << result[i] << std::endl;
    }
    return 0;
}
