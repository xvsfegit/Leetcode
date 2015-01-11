/*************************************************************************
	> File Name: PascalTriangle.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 四  1/22 23:55:19 2015
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


vector<int > generateTriangle(int numRows)
{
    ++numRows;
    vector<vector<int> > result;
    vector<int> beginVec(1,1);
    result.push_back(beginVec);
    if(numRows >= 2){
        vector<int> secVec(2,1);
        result.push_back(secVec);
    }
    for(int i = 2;i < numRows; ++i){
        vector<int> tmpVec;
        tmpVec.push_back(1);
        int j = 1;
        for(;j < (i / 2 + 1); ++j){
            int tmpValue = result[i - 1][j - 1] + result[i - 1][j]; 
            tmpVec.push_back(tmpValue);
        }
        int k = 0;
        if(i % 2){
            k = j - 1; 
        }
        else{
            k = j - 2;
        }
        for(;j < i + 1; ++j,--k){
            tmpVec.push_back(tmpVec[k]);
        }
        result.push_back(tmpVec);
    }
    return result[numRows - 1];
}


int main(int argc,char* argv[])
{
    int nRow = 0;
    cout << "Please input the row:";
    cin >> nRow;
    vector<vector<int> > result;
    result = generateTriangle(nRow);
    for(int i = 0;i < result.size(); ++i){
        for(int j = 0;j < result[i].size(); ++j){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
