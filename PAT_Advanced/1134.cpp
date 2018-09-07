#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

//PAT Advanced Level 1134 Vertex Cover

int main() {
    int N,M;
    set<int> vertices[10001],edge;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        vertices[v1].insert(i);
        vertices[v2].insert(i);
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < M; ++j) {
            edge.insert(j);
        }
        int Nv;
        cin >> Nv;
        for (int j = 0; j < Nv; ++j) {
            int v;
            scanf("%d",&v);
            for (auto it = vertices[v].begin(); it != vertices[v].end(); ++it) {
                edge.erase(*it);
            }
            if(edge.empty())
                break;
        }
        if(edge.empty()){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }

    return 0;
}
