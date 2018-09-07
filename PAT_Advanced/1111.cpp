#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced Level 1111 Online Map

const int INF = INT32_MAX;
vector<int> tempPath,shortPath,fastPath;
int minTime = INF;

void dfs(int v,int S,vector<vector<int>> & pre,vector<vector<int>> & time){
    tempPath.push_back(v);
    if(v == S){
        int tempTime = 0;
        for(int i = tempPath.size() - 1;i > 0;i--){
            int thisCity = tempPath[i],nextCity = tempPath[i-1];
            tempTime += time[thisCity][nextCity];
        }
        if(tempTime < minTime){
            minTime = tempTime;
            shortPath = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for(int i = 0; i < pre[v].size();i++)
        dfs(pre[v][i],S,pre,time);
    tempPath.pop_back();
}

void dfs2(int v,int S,vector<vector<int>> & pre){
    tempPath.push_back(v);
    if(v == S){
        fastPath = tempPath;
        tempPath.pop_back();
        return;
    }
    for(int i = 0; i < pre[v].size();i++)
        dfs2(pre[v][i],S,pre);
    tempPath.pop_back();
}


int main() {
    int N,M,S,D;
    cin >> N >> M;
    vector<vector<int>> length(N,vector<int>(N,0));
    vector<vector<int>> time(N,vector<int>(N,0));
    for (int i = 0; i < M; ++i) {
        int v1,v2,ow,len,t;
        scanf("%d%d%d%d%d",&v1,&v2,&ow,&len,&t);
        length[v1][v2] = len;
        time[v1][v2] = t;
        if(ow == 0){
            length[v2][v1] = len;
            time[v2][v1] = t;
        }
    }
    cin >> S >> D;
    //以下是最短路线计算
    vector<int> dist(N,INF);
    bool visited[510];
    vector<vector<int>> pre(510);
    dist[S] = 0;
    pre[S].push_back(S);
    for (int i = 0; i < N; ++i) {
        int minDist = INF,u = -1;
        for (int j = 0; j < N; ++j) {
            if(!visited[j] && dist[j] < minDist){
                u = j;
                minDist = dist[j];
            }
        }
        if(u == -1)
            break;
        visited[u] = true;
        for (int v = 0; v < N; ++v) {
            if(!visited[v] && length[u][v] < INF){
                if(dist[v] > dist[u] + length[u][v]){
                    dist[v] = dist[u] + length[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dist[v] == dist[u] + length[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(D,S,pre,time);
    tempPath.clear();

    //以下是最快路线计算
    vector<int> totalTime(N,INF);
    bool visited2[510];
    vector<vector<int>> pre2(510);
    totalTime[S] = 0;
    pre2[S].push_back(S);
    for (int i = 0; i < N; ++i) {
        int minTime = INF,u = -1;
        for (int j = 0; j < N; ++j) {
            if(!visited2[j] && totalTime[j] < minTime){
                u = j;
                minTime = dist[j];
            }
        }
        if(u == -1)
            break;
        visited2[u] = true;
        for (int v = 0; v < N; ++v) {
            if(!visited2[v] && length[u][v] < INF){
                if(totalTime[v] > totalTime[u] + time[u][v]){
                    totalTime[v] = totalTime[u] + time[u][v];
                    pre2[v].clear();
                    pre2[v].push_back(u);
                } else if(totalTime[v] == totalTime[u] + time[u][v]){
                    pre2[v].push_back(u);
                }
            }
        }
    }
    dfs2(D,S,pre2);
    reverse(shortPath.begin(),shortPath.end());
    reverse(fastPath.begin(),fastPath.end());
    vector<int> shortPath1 = shortPath,fastPath2 = fastPath;
    if(shortPath1 == fastPath2){
        cout << "Distance = " << dist[D] <<"; Time = " <<totalTime[D];
        cout << ": ";
        for (int i = 0; i < shortPath1.size(); ++i) {
            if(i>0)
                cout  << " -> ";
            cout << shortPath1[i];
        }
    }
    else{
        cout << "Distance = " << dist[D] <<": ";
        for (int i = 0; i < shortPath1.size(); ++i) {
            if(i>0)
                cout  << " -> ";
            cout << shortPath1[i];
        }
        cout << endl;
        cout << "Time = " << totalTime[D] <<": ";
        for (int i = 0; i < fastPath2.size(); ++i) {
            if(i>0)
                cout  << " -> ";
            cout << fastPath2[i];
        }
        cout << endl;

    }

    return 0;
}
