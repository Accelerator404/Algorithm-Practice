#include <iostream>
#include <vector>
using namespace std;

//PAT Advanced Level 1110 Complete Binary Tree

struct node{
    int left,right;
};

int maxn = -1,lastNode;

void dfs(int root,int index,vector<node> & BT){
    //maxn记录访问到的二叉树叶子节点最大序号，显然若maxn > N则不是完全二叉树
    //lastNode记录最后访问到的节点号
    if(index > maxn){
        maxn = index;
        lastNode = root;
    }
    if(BT[root].left != -1)
        dfs(BT[root].left,index*2,BT);
    if(BT[root].right != -1)
        dfs(BT[root].right,index*2+1,BT);
}

int main() {
    int N;
    cin >> N;
    vector<int> findRoot(100,0);
    vector<node> BT(100);
    for (int i = 0; i < N; ++i) {
        string a,b;
        cin >> a >> b;
        if(a != "-") {
            BT[i].left = strtol(a.c_str(),nullptr,10);
            findRoot[strtol(a.c_str(),nullptr,10)] = 1;
        }
        else
            BT[i].left = -1;
        if(b != "-"){
            BT[i].right = strtol(b.c_str(),nullptr,10);
            findRoot[strtol(b.c_str(),nullptr,10)] = 1;
        }
        else
            BT[i].right = -1;
    }
    int root = 0;
    while (findRoot[root])
        root++;
    dfs(root,1,BT);
    if(maxn == N){
        cout << "YES " << lastNode;
    }
    else{
        cout << "NO " << root;
    }
    return 0;
}
