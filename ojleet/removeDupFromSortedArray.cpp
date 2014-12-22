/*************************************************************************
	> File Name: removeDupFromSortedArray.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 一 12/22 19:25:34 2014
 ************************************************************************/

#include<iostream>
using namespace std;
int removeDuplicates(int A[],int n)
{
    if(n == 0)
        return 0;
    int i = 0;
    int j = i + 1;
    while(j < n){
        if(A[i] != A[j]){
            if(i + 1 != j){
                A[i + 1] = A[j];
            }
            ++i;
            ++j;
        }
        else{
            ++j;   
        }
    }
    return i + 1;
}

int main(int argc,char* argv[])
{
    cout << "Please input array element:";
    int A[5];
    for(int i = 0;i < 5; ++i){
        int tmp = 0;
        cin >> tmp;
        A[i] = tmp;
    }
    int result = removeDuplicates(A,5);
    cout << result << endl;
    for(int i = 0;i < result; ++i){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
