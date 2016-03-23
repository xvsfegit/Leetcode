/*************************************************************************
	> File Name: CombinationSum.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 一  3/21 22:57:25 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
private:
    vector< vector<int> > results;
    const int index_count;
    int* index;
    int target;
public:
    Solution():index_count(10000)
    {
        index = new int[index_count];
    };
    ~Solution()
    {
        delete [] index;
    }

    void dfs(vector<int>& candidates,int sum,int n){
        if(sum > target){
            return;
        }
        else if(sum == target){
            vector<int> tmpVec;
            for(int i = 1;i <= n; ++i){
                tmpVec.push_back(candidates[index[i]]);
            }
            results.push_back(tmpVec);
        }
        for(int i = index[n];i < candidates.size(); ++i){
            index[n + 1] = i;
            dfs(candidates,sum + candidates[i],n + 1);
        }
    }

    vector< vector<int> > combinationSum(vector<int>& candidates,int target){
        sort(candidates.begin(),candidates.end());    
        this->target = target;
        results.clear();
        memset(index,0,sizeof(int) * index_count);
        dfs(candidates,0,0);
        return results;
    }

};

int main(int argc,char* argv[]){
    return 0;
}
