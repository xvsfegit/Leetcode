/*************************************************************************
	> File Name: removeDupFromSortedArray.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 一 12/22 19:25:34 2014
 ************************************************************************/

#include<iostream>
using namespace std;
int removeElement(int A[],int n,int elem)
{
    if(n == 0)
        return 0;
    int i = 0;
    int j = n - 1;
    while(i < j){
        if(A[i] == elem){
            if(A[j] == elem){
                --j;
            }
            else{
                A[i++] = A[j--];     
            }
        }
        else{
            ++i;
        }
    }
    return i;
}

int main(int argc,char* argv[])
{
    cout << "Please the element number:";
    int n = 0;
    cin >> n;
    cout << "Please input array element:";
    int A[n];
    for(int i = 0;i < n; ++i){
        int tmp = 0;
        cin >> tmp;
        A[i] = tmp;
    }
    cout << endl;
    return 0;
}
