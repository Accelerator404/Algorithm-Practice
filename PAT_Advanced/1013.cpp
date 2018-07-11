#include <iostream>
#include <algorithm>
using namespace std;

//PAT Advanced 1013 Battle Over Cities

/*
 * 题意说明，对N个城市现有M条开放的公路使所有城市互联，
 * 我们需要考虑其中一个城市被占领后其余城市需要修复多少条公路才能使其他城市再次处于互联。
 * 比如关闭城市1后剩余城市组成两个被分隔的内部互联子网，那么修复一条高速公路即可使其恢复互联。
 * 简而言之，关闭城市K后，剩余城市组成P个内部互联子网，则修复P-1条高速公路。
 * 可以考虑给所有的城市连接到一个DFS搜索的虚入口，从虚入口对每个城市进行一次DFS，由此判断子网个数。
 */
int map[1001][1001] = {0};
bool visited[1001] = {false};
int N;

void DFS(int node){
    if(visited[node])
        return;
    visited[node] = true;
    for (int i = 1; i <= N; ++i) {
        if(map[node][i] == 1 && !visited[i]){
            DFS(i);
        }
    }
}

int main() {
    int M,K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        int cityA,cityB;
        scanf("%d %d",&cityA,&cityB);
        map[cityA][cityB] = map[cityB][cityA] = 1;
    }
    for (int j = 0; j < K; ++j) {
        int occupiedCity,zone = 0;
        scanf("%d",&occupiedCity);
        fill(visited,visited+1001,false);
        visited[occupiedCity] = true;
        for (int i = 1; i <= N; ++i) {
            if(!visited[i]){
                DFS(i);
                zone++;
            }
        }
        printf("%d\n",zone-1);
    }
    return 0;
}
