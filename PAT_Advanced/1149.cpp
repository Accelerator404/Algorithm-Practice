#include <iostream>
#include <vector>
#include <set>
using namespace std;

// PAT Advanced Level 201809 7-2 &
// PAT Advanced Level 1149 Dangerous Goods Packaging

int main()
{
    int N,M;
    cin >> N >> M;
    set<int> lists[100010];
    for(int i = 0;i < N;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        lists[a].insert(b);
        lists[b].insert(a);
    }
    for(int i = 0;i < M;i++){
        int K;
        vector<int> G;
        cin >> K;
        for(int j = 0;j < K;j++){
            int p;
            scanf("%d",&p);
            G.push_back(p);
        }
        bool isIncompatible = false;
        for(int j = 0;j < K - 1;j++){
            int target = G[j];
            for(int k = j + 1;k < K;k++){
                if(lists[target].count(G[k])!= 0){
                    isIncompatible = true;
                    break;
                }
            }
            if(isIncompatible)
                break;
        }
        if(isIncompatible)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
