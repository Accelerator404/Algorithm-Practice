#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * 06-图1 列出连通集
 */
/*
 * 实现了图（边界是完全邻接矩阵储存，占用过多空间），BFS、DFS
 */

class graph{
private:
    int nodeCount;
    int edgeCount;
    vector<bool> visited;
    vector<int> edge;
public:
    graph(int N,int E):nodeCount(N),edgeCount(E){
        visited.resize(N);
        edge.resize(N*N);
        edge.assign(edge.size(),0);
        visited.assign(nodeCount,false);
    }
    void createEdge(int node1,int node2){
        int edgePlot1,edgePlot2;
        if(node1 == node2){
            return;
        }
        edgePlot1 = nodeCount * node1 + node2;
        edgePlot2 = nodeCount * node2 + node1;
        edge[edgePlot1] = 1;
        edge[edgePlot2] = 1;

    }
    bool connected(int nodeT,int node){
        int edgePlot;
        if(nodeT == node){
            return true;
        }
        edgePlot = nodeCount * nodeT + node;
        return (bool)edge[edgePlot];
    }
    int searchNeighbour(int target){
        for (int i = 0; i < nodeCount; ++i) {
            if (target == i)
                continue;
            if(connected(target,i) && !visited[i])
                return i;
        }
        return -1;
    }
    void resetVisited(){
        visited.assign((unsigned int)nodeCount,false);
    }
    void DFS(int start){
        visited[start] = true;
        cout << start << ' ';
        while(true){
            int next = searchNeighbour(start);
            if(next == -1)
                break;
            DFS(next);
        }
    }
    void ListSetDFS(){
        resetVisited();
        for (int i = 0; i < nodeCount; ++i) {
            if(!visited[i]){
                cout << "{ ";
                DFS(i);
                cout << '}' << endl;
            };
        }
        resetVisited();
    }
    void BFS(int start){
        visited[start] = true;
        queue<int> q;
        q.push(start);
        int handle;
        while(!q.empty()){
            handle = q.front();
            q.pop();
            cout << handle << ' ';
            while (true){
                int next = searchNeighbour(handle);
                if(next == -1)
                    break;
                else{
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
    void ListSetBFS(){
        resetVisited();
        for (int i = 0; i < nodeCount; ++i) {
            if(!visited[i]){
                cout << "{ ";
                BFS(i);
                cout << '}' << endl;
            };
        }
        resetVisited();
    }
};

int main(){
    int N,E;
    cin >> N >> E;
    graph data(N,E);
    for (int i = 0; i < E; ++i) {
        int n1,n2;
        cin>>n1>>n2;
        data.createEdge(n1,n2);
    }
    data.ListSetDFS();
    data.ListSetBFS();
    return 0;
}
