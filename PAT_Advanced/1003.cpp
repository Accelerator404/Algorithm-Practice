#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//PAT Advanced 1003 Emergency

#define INFI 6324666
int main(){
    int N,M,C1,C2;
    //存放路径长度权重无向图
    int rMap[503][503];
    bool visited[503] = {false};
    fill(rMap[0],rMap[0]+503*503,INFI);
    //四个数组分别存放节点救援队数（权重），节点最短距离，最短路径数，节点路径合计救援队权重（最短路径聚集的救援队员数）
    vector<int> memberNum,dist,path,firemanNum;
    cin >> N >> M >> C1 >> C2;
    memberNum.resize(N);
    dist.resize(N);
    path.resize(N);
    firemanNum.resize(N);
    dist.assign(N,INFI);
    for (int i = 0; i < N; ++i) {
        cin >> memberNum[i];
    }
    for (int j = 0; j < M; ++j) {
        int cityA,cityB,pathL;
        scanf("%d%d%d",&cityA,&cityB,&pathL);
        rMap[cityA][cityB]=rMap[cityB][cityA]=pathL;
    }
    dist[C1]=0,firemanNum[C1]=memberNum[C1],path[C1]=1;
    for(int i = 0; i < N; i++) {
        int u = -1, minN = INFI;
        for(int j = 0; j < N; j++) {
            if(visited[j] == false && dist[j] < minN) {
                u = j;
                minN = dist[j];
            }
        }
        if(u == -1) break;
        visited[u] = true;
        for(int v = 0; v < N; v++) {
            if(visited[v] == false && rMap[u][v] != INFI) {
                if(dist[u] + rMap[u][v] < dist[v]) {
                    dist[v] = dist[u] + rMap[u][v];
                    path[v] = path[u];
                    firemanNum[v] = firemanNum[u] + memberNum[v];
                } else if(dist[u] + rMap[u][v] == dist[v]) {
                    path[v] = path[v] + path[u];
                    if(firemanNum[u] + memberNum[v] > firemanNum[v])
                        firemanNum[v] = firemanNum[u] + memberNum[v];
                }
            }
        }
    }
    cout << path[C2] << ' ' << firemanNum[C2] << endl;
    return 0;
}
