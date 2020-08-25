#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//PAT Advanced 1018 Public Bike Management

const int INFI = 99999999;
int Cmax,N,Sp,M;
int Matrix[505][505],dist[505],weight[505];//weight指节点自行车数量与节点半容量Cmax/2的差
bool visited[505];
int minNeed = INFI,minBack = INFI;
vector<int> preNode[505];
vector<int> path,tempPath;

//DFS从报警告的停车点Sp开始搜索，到PBMC即0节点时开始计算该临时路径的自行车存取数量
//preNode，也就是各节点通向Sp的最短路线，是Dijkstra算法得出的

void dfs(int v){
    tempPath.push_back(v);
    if(v == 0){
        int need = 0,back = 0;
        for (int i = tempPath.size() - 1; i >= 0 ; i--) {
            int id = tempPath[i];//从Sp点开始计算tempPath沿途各点存取自行车数量
            if(weight[id] > 0){
                back += weight[id]; //取车
            }
            else{
                if(back > (0 - weight[id])){//携带车数足够
                    back += weight[id];
                }//存车
                else{   //车数不足，需要出发时带自行车
                    need += ((0-weight[id]) - back);
                    back = 0;
                }
            }
        }
        if(need < minNeed){
            minNeed = need;
            minBack = back;
            path = tempPath;//得出需要携带或能带回的自行车数目，及最短路径
        }
        else if(need == minNeed && back < minBack){
            minBack = back;
            path = tempPath;
        }
        tempPath.pop_back(); // 从0节点开始弹出tempPath节点
        return; // 退出迭代
    }
    for (int i = 0; i < preNode[v].size(); ++i)
        dfs(preNode[v][i]);
    tempPath.pop_back();
}

int main(){
    fill(Matrix[0],Matrix[0]+505*505,INFI);
    fill(dist,dist+505,INFI);
    scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d",&weight[i]);
        weight[i] = weight[i] - Cmax/2;
    }
    for (int i = 0; i < M; ++i) {
        int nodeA,nodeB;
        scanf("%d%d",&nodeA,&nodeB);
        scanf("%d",&Matrix[nodeA][nodeB]);
        Matrix[nodeB][nodeA] = Matrix[nodeA][nodeB];
    }
    dist[0] = 0;
    //Dijkstra
    for (int i = 0; i <= N; ++i) {
        int u = -1,minN = INFI;
        //找到未到访顶点中dist最小
        for (int j = 0; j <= N; ++j) {
            if(!visited[j] && dist[j] < minN){
                u = j;
                minN = dist[j];
            }
        }
        if(u == -1) break;
        visited[u] = true;
        for (int v = 0; v <= N; ++v) {
            if(!visited[v] && Matrix[u][v] != INFI){
                if(dist[v] > dist[u] + Matrix[u][v]){
                    dist[v] = dist[u] + Matrix[u][v];
                    preNode[v].clear();
                    preNode[v].push_back(u);
                }
                else if(dist[v] == dist[u] + Matrix[u][v]){
                    preNode[v].push_back(u);
                }
            }
        }
    }
    dfs(Sp);
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
}
