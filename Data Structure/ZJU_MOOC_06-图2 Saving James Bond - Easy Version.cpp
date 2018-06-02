#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


/*
 * 06-图2 Saving James Bond - Easy Version
 */
/*
 * 注意，这个岛的半径是7.5，第一跳要单独考虑。
 */

class graph{
private:
    unsigned int nodeCount;
    int D;
    vector<bool> visited;
    vector<int> edge;
    vector<bool> border;
    vector<pair<float,float> > plotList;
public:
    graph(int N,int jump):nodeCount(N+1),D(jump){
        visited.resize(N+1);
        edge.resize((N+1)*(N+1));
        edge.assign(edge.size(),0);
        visited.assign(nodeCount,false);
        border.resize(N+1);
        border.assign(nodeCount,false);
        plotList.resize(nodeCount);
        plotList[0].first=0;
        plotList[0].second=0;
    }
    void createMap(){
        if(D>=35)
            border[0] = true;
        if(nodeCount>1)
            for (int i = 1; i < nodeCount; ++i) {
            float x,y;
            cin>>x>>y;
            plotList[i].first=x;
            plotList[i].second=y;
            if(x+D>=50 || x-D<=-50)
                border[i] = true;
            if(y+D>=50 || y-D<=-50)
                border[i] = true;
        }
        //创建第一跳
        for (int i = 1; i < nodeCount; ++i) {
            double dis = sqrt(pow(plotList[i].first,2)+pow(plotList[i].second,2));
            if(dis <= 7.5+D)
                createEdge(0,i);
        }
        //创建鳄鱼链接
        for (int i = 1; i < nodeCount; ++i) {
            for (int j = i+1; j < nodeCount; ++j) {
                float jump = D*D;
                float dis;
                float & x1 = plotList[i].first;float & x2 = plotList[j].first;
                float & y1 = plotList[i].second;float & y2 = plotList[j].second;
                dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                if(dis <= jump){
                    createEdge(i,j);
                }
            }
        }
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
    bool DFS(int start){
        visited[start] = true;
        bool reach = false;
        if(border[start])
            reach = true;
        else{
            while(true){
                int next = searchNeighbour(start);
                if(next == -1)
                    break;
                reach = DFS(next);
                if(reach)
                    break;
            }
        }
        return reach;
    }
};

int main(){
    int N,D;
    cin >> N >> D;
    graph data(N,D);
    data.createMap();
    if(data.DFS(0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
