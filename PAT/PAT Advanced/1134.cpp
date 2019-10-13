#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

//PAT Advanced Level 1134 Vertex Cover

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> vertices[N+1];
    for (int i = 0; i < M; ++i) {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        vertices[v1].push_back(i);
        vertices[v2].push_back(i);
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        set<int> edge;
        int Nv;
        cin >> Nv;
        for (int j = 0; j < Nv; ++j) {
            int v;
            scanf("%d",&v);
            //往空集插入所有覆盖到的边
            for (auto it = vertices[v].begin(); it != vertices[v].end(); ++it) {
                edge.insert(*it);
            }
        }
        //边集合大小不等于边条数即为未完全覆盖
        if(edge.size() == M){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }
    return 0;
}
