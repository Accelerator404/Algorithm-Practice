#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced 1021 Deepest Root

/* 原理就是DFS求联通块，之后DFS求高度
 * 注意测试点3有海量数据，需要采取相应措施
 */

int N;
vector<int> Matrix[10001];
vector<int> compNo(10001,-1),node(10001,-1);

//dfs1()用来求联通块，参考算法竞赛入门例题6-12(UVa572)
void dfs1(int enterNode,int compId){
    if(enterNode <= 0 || enterNode > N)
        return;
    if(compNo[enterNode] != -1)
        return;
    compNo[enterNode] = compId;
    node[enterNode] = 1;
    for (int i = 0; i < Matrix[enterNode].size(); ++i) {
        if(Matrix[enterNode][i] != enterNode)
            dfs1(Matrix[enterNode][i],compId);
    }
}

//该子树高度=该子树的所有子树的最高高度+1
int dfs2(int enterNode){
    if(enterNode <= 0 || enterNode > N)
        return 0;
    if(node[enterNode] != -1)
        return 0;
    int subTreeHeight = 0;
    node[enterNode] = 1;
    for (int i = 0; i < Matrix[enterNode].size(); ++i) {
        int tmp;
        if(Matrix[enterNode][i] != enterNode){
            tmp = dfs2(Matrix[enterNode][i]);
            if(tmp > subTreeHeight)
                subTreeHeight = tmp;
        }
    }
    return subTreeHeight + 1;
}

int main(){
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        Matrix[a].push_back(b);
        Matrix[b].push_back(a);
    }
    int comp = 0;
    while(true){
        bool flag = false;
        for (int i = 1; i <= N; ++i) {
            if(node[i] == -1 && compNo[i] == -1){
                comp++;
                dfs1(i,comp);
                flag = true;
                break;
            }
        }
        if(!flag) break;
    }
    if(comp > 1){
        printf("Error: %d components\n",comp);
        return 0;
    }
    node.resize(N+1);
    vector<int> height(N+1,0);
    int maxH = 0;
    for (int i = 1; i < N+1; ++i) {
        node.assign(N+1,-1);
        height[i] = dfs2(i);
        maxH = max(maxH,height[i]);
    }
    for (int i = 1; i < N+1; ++i) {
        if(height[i] == maxH)
            printf("%d\n",i);
    }
    return 0;
}
