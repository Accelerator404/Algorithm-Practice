#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced Level 1111 Online Map

/* 两次Dijkstra
 */

const int inf = 999999999;
int dis[510], Time[510], e[510][510], w[510][510], dispre[510],Timepre[510], weight[510],NodeNum[510];
bool visit[510];
vector<int> dispath, Timepath, temppath;
int S, D, minnode = inf;
void dfsdispath(int v) {
    dispath.push_back(v);
    if(v == S) return ;
    dfsdispath(dispre[v]);
}
void dfsTimepath(int v) {
    Timepath.push_back(v);
    if(v == S) return ;
    dfsTimepath(Timepre[v]);
}
int main() {
    fill(dis, dis + 510, inf);
    fill(Time, Time + 510, inf);
    fill(weight, weight + 510, inf);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(w[0], w[0] + 510 * 510, inf);
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, flag, len, t;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
        e[a][b] = len;
        w[a][b] = t;
        if(flag != 1) {
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    scanf("%d %d", &S, &D);
    dis[S] = 0;
    for(int i = 0; i < n; i++)
        dispre[i] = i;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
                    dispre[v] = u;
                    weight[v] = weight[u] + w[u][v];
                } else if(e[u][v] + dis[u] == dis[v] && weight[v] > weight[u] + w[u][v]) {
                    weight[v] = weight[u] + w[u][v];
                    dispre[v] = u;
                }
            }
        }
    }
    dfsdispath(D);
    Time[S] = 0;
    fill(visit, visit + 510, false);
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && minn > Time[j]) {
                u = j;
                minn = Time[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && w[u][v] != inf) {
                if(w[u][v] + Time[u] < Time[v]) {
                    Time[v] = w[u][v] + Time[u];
                    Timepre[v]=(u);
                    NodeNum[v]=NodeNum[u]+1;
                } else if(w[u][v] + Time[u] == Time[v]&&NodeNum[u]+1<NodeNum[v]) {
                    Timepre[v]=(u);
                    NodeNum[v]=NodeNum[u]+1;
                }
            }
        }
    }
    dfsTimepath(D);
    reverse(dispath.begin(),dispath.end());
    reverse(Timepath.begin(),Timepath.end());
    if(dispath == Timepath){
        cout << "Distance = " << dis[D] <<"; Time = " <<Time[D];
        cout << ": ";
        for (int i = 0; i < dispath.size(); ++i) {
            if(i>0)
                cout  << " -> ";
            cout << dispath[i];
        }
    }
    else{
        cout << "Distance = " << dis[D] <<": ";
        for (int i = 0; i < dispath.size(); ++i) {
            if(i>0)
                cout  << " -> ";
            cout << dispath[i];
        }
        cout << endl;
        cout << "Time = " << Time[D] <<": ";
        for (int i = 0; i < Timepath.size(); ++i) {
            if(i>0)
                cout  << " -> ";
            cout << Timepath[i];
        }
        cout << endl;
    }

    return 0;
}
