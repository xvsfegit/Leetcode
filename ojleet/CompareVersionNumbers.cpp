/*************************************************************************
	> File Name: CompareVersionNumbers.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2015年01月18日 星期日 23时57分06秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<sstream>
using namespace std;

    vector<int> &split(const string &s, char delim, vector<int> &elems)
    {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(atoi(item.c_str()));
        }
        return elems;
    }


    vector<int> split(const string &s, char delim)
    {
        vector<int> elems;
        split(s, delim, elems);
        return elems;
    }

    void rightTrimZero(vector<int> &v)
    {
        while (v.back() == 0){
            v.pop_back();
        }
    }

    int compareVersion(string version1, string version2)
    {
        //split the version by delimer '.'
        vector<int> ver1 = split(version1, '.');
        vector<int> ver2 = split(version2, '.');
        //remove the right Zeros
        rightTrimZero(ver1);
        rightTrimZero(ver2);
        //compare two versions 
        for (int i=0; i<ver1.size() && i < ver2.size(); i++) {
            if (ver1[i] < ver2[i]){
                return -1;
            }
            else if(ver1[i] > ver2[i]){
                return 1;
            }
        }
            //if the above for-loop is not returned, which means they are equal so far
            //then check the length.
        if (ver1.size() > ver2.size()) {
            return 1;
        }
        else if (ver1.size() < ver2.size()) {
            return -1;
        }
        return 0;
    }

int main(int argc,char* argv[])
{
    cout << "Please input the version that you want compare:";
    string version1,version2;
    cin >> version1 >> version2;
    cout << compareVersion(version1,version2) << endl;
    return 0;
}
