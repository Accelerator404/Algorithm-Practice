#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

//PAT Advanced Level 1110 Complete Binary Tree

/*
 * 层序遍历
 */

struct node{
    int left,right,data;
};

int main() {
    int N;
    cin >> N;
    set<int> findRoot;
    vector<node> BT(N);
    for (int i = 0; i < N; ++i) {
        //之前犯错用char接收，这就无法处理十位数了
        string a,b;
        cin >> a >> b;
        if(a != "-")
            BT[i].left = strtol(a.c_str(),nullptr,10);
        else
            BT[i].left = -1;
        if(b != "-")
            BT[i].right = strtol(b.c_str(),nullptr,10);
        else
            BT[i].right = -1;
        BT[i].data = i;
    }
    for (int i = 0; i < N; ++i) {
        findRoot.insert(i);
    }
    for (int i = 0; i < N; ++i) {
        findRoot.erase(BT[i].left);
        findRoot.erase(BT[i].right);
    }
    int root = *findRoot.begin();
    vector<int> popSeq;
    node nullNode = node{-1,-1,-1};
    queue<node> q;
    q.push(BT[root]);
    while (!q.empty()){
        if(q.front().left != -1)
            q.push(BT[q.front().left]);
        else if(q.front().data != -1)
            q.push(nullNode);
        if(q.front().right != -1)
            q.push(BT[q.front().right]);
        else if(q.front().data != -1)
            q.push(nullNode);
        popSeq.push_back(q.front().data);
        q.pop();
        if(popSeq.size() > 30)
            break;
    }
    bool isComplete = true;
    for (int i = 0; i < N; ++i) {
        if(popSeq[i] == -1)
            isComplete = false;
    }
    if(isComplete){
        cout << "YES " << popSeq[N-1];
    }
    else{
        cout << "NO " << root;
    }
    return 0;
}
