#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//PAT Advanced Level 1030 Travel Plan

int n, m, s, d;
//e、cost是邻接矩阵，分别记录城市间距离和路费，dis存储Dijkstra算法中的v点到起点最短路径距离
int e[510][510], dis[510], cost[510][510];
//pre数组指每一点v到出发点的所有有“最短距离dis”的路径中，到v点的前一点
vector<int> pre[510];
bool visit[510];
const int inf = 99999999;
vector<int> path, temppath;
int mincost = inf;

void dfs(int v) {
    //将当前点压入DFS的临时路径
    temppath.push_back(v);
    //到达起点便开始判断路费（Dijkstra算法已确定所有路径都是最短路径）
    if(v == s) {
        int tempcost = 0;
        //计算路费
        for(int i = temppath.size() - 1; i > 0; i--) {
            int id = temppath[i], nextid = temppath[i-1];
            tempcost += cost[id][nextid];
        }
        if(tempcost < mincost) {
            mincost = tempcost;
            //将当前路径暂时作为最佳路径
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    //否则压入所有pre数组中的“前一点”
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    //弹出临时路径中当前点，便于上一节点搜索其他的“前一点”
    temppath.pop_back();
}

int main() {
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &n, &m, &s, &d);
    //写邻接矩阵
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
        scanf("%d", &cost[a][b]);
        cost[b][a] = cost[a][b];
    }
    //初始化起点的
    pre[s].push_back(s);
    dis[s] = 0;
    
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        //寻找未访问节点中最小距离的点作为u点（不通点会被排除）
        for(int j = 0; j < n; j++) {
            if(!visit[j] && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        //存在这样一个u点，用它更新未访问点的距离表
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            //若v点未访问且uv相通
            if(!visit[v] && e[u][v] != inf) {
                //若通过u点，距离更小，则更新距离，删除所有前节点，压入当前节点
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                //若两条路径等长，压入当前节点
                else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    //从终点开始DFS
    dfs(d);
    for(int i = path.size() - 1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("%d %d", dis[d], mincost);
    return 0;
}
