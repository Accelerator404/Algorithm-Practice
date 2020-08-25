#include <cstdio>
#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <vector>
using namespace std;

//PAT Advanced Level 1034 Head of a Gang

/* 直接用两个map进行姓名与int ID的转换
 * DFS遍历连通分量，某连通分量满足条件，即为结果之一，此处存入以帮主名称为key的map中
 */

map<int,string> hashToName;
map<string,int> nameToHash;
map<string,int> gangs;
int personID = 1,K;
int hashID(string s){
    if(nameToHash.find(s) == nameToHash.end()){
        nameToHash[s] = personID;
        hashToName[personID] = s;
        personID++;
        return personID - 1;
    }
    else{
        return nameToHash[s];
    }
}
int G[2005][2005],weight[2005];
bool visited[2005];

void dfs(int u,int & head,int & numMember,int & totalWeight){
    visited[u] = true;
    numMember++;
    if(weight[u] > weight[head])
        head = u;
    for(int v = 1;v < personID;v++){
        //如果uv联通，将权重计入该连通分量后封死uv通路
        if(G[u][v] > 0){
            totalWeight += G[u][v];
            G[u][v] = G[v][u] = 0;
            if(!visited[v])
                dfs(v,head,numMember,totalWeight);
        }
    }
}

int main() {
    int N;
    cin >> N >> K;
    for(int i = 0;i < N;i++){
        string str1,str2;
        int w;
        cin >> str1 >> str2 >> w;
        int ID1 = hashID(str1),ID2 = hashID(str2);
        weight[ID1] += w;
        weight[ID2] += w;
        G[ID1][ID2] += w;
        G[ID2][ID1] += w;
    }
    for(int i = 1; i < personID;i++){
        if(!visited[i]){
            int head = i,numMember = 0,totalWeight = 0;
            dfs(i,head,numMember,totalWeight);
            if(numMember > 2 && totalWeight > K){
                //map内部自带对key排序
                gangs[hashToName[head]] = numMember;
            }
        }
    }
    cout << gangs.size() << endl;
    for(auto it = gangs.begin();it != gangs.end();it++){
        cout << it->first << ' ' << it->second << endl;

    }
    return 0;
}
