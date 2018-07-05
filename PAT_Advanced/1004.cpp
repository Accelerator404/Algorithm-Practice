#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//PAT Advanced 1004 Counting Leaves

struct people{
    int childNum = 0;
    int ID;//方便起见以整数保存
    vector<int> childID;
};

int MaxDepth=-1;
vector<people> nameList;
vector<int> levelLeaves(99,0);



void dfs(int index, int depth) {
    if(nameList[index].childID.size() == 0) {
        levelLeaves[depth]++;
        MaxDepth = max(MaxDepth, depth);
        return ;
    }
    for(int i = 0; i < nameList[index].childID.size(); i++)
        dfs(nameList[index].childID[i], depth + 1);
}

int main(){
    int N,M;
    cin >> N >> M;
    nameList.resize(N+1);
    for (int i = 1; i <= N; ++i) {
        nameList[i].ID = i;
    }
    for (int i = 0; i < M; ++i) {
        int currID,K;
        cin >> currID >> K;
        nameList[currID].childNum = K;
        nameList[currID].childID.resize(K);
        for (int j = 0; j < K; ++j) {
            cin >> nameList[currID].childID[j];
        }
    }
    dfs(1,0);
    bool first = true;
    for (int k = 0; k <= MaxDepth; ++k) {
        if(first){
            cout << levelLeaves[k];
            first = false;
        }
        else
            cout<< ' ' << levelLeaves[k];
    }
    return 0;
}
