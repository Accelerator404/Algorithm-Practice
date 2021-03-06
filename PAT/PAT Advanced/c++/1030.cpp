#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//PAT Advanced Level 1030 Travel Plan

const int INF = 99999999;
//e、cost是邻接矩阵，分别记录城市间距离和路费，dis存储Dijkstra算法中的v点到起点最短路径距离
int route[505][505],dist[505],cost[505][505],costWeight[505];
int N,M,S,D;
//pre数组指每一点v到出发点的所有有“最短距离dis”的路径中，到v点的前一点
vector<int> previous(505);
vector<int> tempPath,FinalPath;
int minCost = INF;

void dfs(int v) {
    //将当前点压入DFS的临时路径
    FinalPath.push_back(v);
    //到达起点便开始判断路费（Dijkstra算法已确定所有路径都是最短路径）
    if(v == S){
        return;
    }
    //未到起点，则压入所有pre数组中的“前一点”
    dfs(previous[v]);
}

int main() {
    //初始化邻接矩阵，输入参数
    bool isVisited[505];
    fill(route[0],route[0]+505*505,INF);
    fill(dist,dist+505,INF);
    fill(costWeight,costWeight+505,0);
    fill(isVisited,isVisited+505,false);
    cin >> N >> M >> S >> D;
    //读入邻接矩阵
    for(int i = 0;i < M;i++){
        int a,b,c,d;
        scanf("%d%d",&a,&b);
        scanf("%d%d",&c,&d);
        route[b][a] = route[a][b] = c;
        cost[b][a] = cost[a][b] = d;
    }
    //初始化起点
    dist[S] = 0;
    previous[S] = S;
    //遍历所有节点
    for(int i = 0; i < N; i++) {
        int minD = INF,u = -1;
        //寻找未访问节点中最小距离的点作为u点（不通点会被排除），不存在则跳出
        for(int j = 0;j < N;j++){
            if(!isVisited[j] && dist[j] < minD){
                u = j;
                minD = dist[j];
            }
        }
        if(u == -1)
            break;
        isVisited[u] = true;
        //若存在这样一个u点，用它更新未访问点的距离表
        for(int v = 0; v < N; v++) {
            //若v点未访问且uv相通
            if(!isVisited[v] && route[u][v] < INF) {
                //若通过u点，距离更小，则更新距离，更新前节点为当前节点
                if(dist[v] > dist[u] + route[u][v]){
                    dist[v] = dist[u] + route[u][v];
                    previous[v] = u;
                    costWeight[v] = costWeight[u] + cost[u][v];
                }
                //若两条路径等长时走当前节点路费更省，更新前节点为当前节点
                else if(dist[v] == dist[u] + route[u][v] && costWeight[v] > costWeight[u] + cost[u][v]) {
                    previous[v] = u;
                    costWeight[v] = costWeight[u] + cost[u][v];
                }
            }
        }
    }
    //从终点开始DFS
    dfs(D);
    minCost = costWeight[D];
    for(int i = FinalPath.size()-1;i >= 0;i--){
        printf("%d ",FinalPath[i]);
    }
    printf("%d %d\n",dist[D],minCost);
    return 0;
}
