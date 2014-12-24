/*************************************************************************
	> File Name: validSoduku.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 二 12/23 20:49:24 2014
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define SODU 9

const char zero = '0';

bool isValidSudoku(vector< vector<char> >& board)
{
    int h_flag[SODU][SODU];
    int w_flag[SODU];
    int flag_1[SODU];
    int flag_2[SODU];
    int flag_3[SODU];
    memset(h_flag,0,SODU * SODU * 4);
    for(int i = 0;i < SODU; ++i){
        memset(w_flag,0,SODU * 4);
        if(i % 3 == 0){
            memset(flag_1,0,SODU * 4);
            memset(flag_2,0,SODU * 4);
            memset(flag_3,0,SODU * 4);
        }
        for(int j = 0;j < SODU; ++j){
            if(board[i][j] == '.')
                continue;
            int w = board[i][j] - zero - 1;
            if(w_flag[w] == 1 || h_flag[j][w] == 1){
                return false;
            }
            else{
                h_flag[j][w] = 1;
                w_flag[w] = 1;
            }
            if(j > 5){
                if(flag_3[w] == 1){
                    return false;
                }
                flag_3[w] = 1;
            }
            if(2 < j && j < 6){
                if(flag_2[w] == 1){
                    return false;
                }
                flag_2[w] = 1;
            }
            if(j < 3){
                if(flag_1[w] == 1){
                    return false;
                }
                flag_1[w] = 1;
            }
        }
    }
    return true;
}

int main(int argc,char* argv[])
{
    string tmp;
    vector< vector<char> > board;
    cout << "Please input the case:";
    for(int i = 0;i < SODU; ++i){
        cin >> tmp;
        vector<char> vec_char;
        for(int j = 0;j < SODU; ++j){
            vec_char.push_back(tmp[j]);
        }
        board.push_back(vec_char);
    }
    cout << isValidSudoku(board) << endl;
    return 0;
}
