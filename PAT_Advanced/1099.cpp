#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//PAT Advanced 1099 Build A Binary Search Tree


/*
 * BST可以在进行中序遍历时，将升序的数值序列按顺序填充进该BST。
 * 层序遍历使用队列。
 */

struct node{
    int data,lb,rb;
};

int token = 0;

void inOrderT(int root,vector<int> & seq,vector<node> & BST){
    if(root == -1)
        return;
    inOrderT(BST[root].lb,seq,BST);
    BST[root].data = seq[token];
    token++;
    inOrderT(BST[root].rb,seq,BST);
}

int main(){
    vector<node> BST;
    vector<int> seq;
    int N;
    cin >> N;
    BST.resize(N);
    seq.resize(N);
    for (int i = 0; i < N; ++i) 
        cin >> BST[i].lb >> BST[i].rb;
    for (int i = 0; i < N; ++i) 
        cin >> seq[i];
    sort(seq.begin(),seq.end(),less<int>());
    inOrderT(0,seq,BST);
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int ptr = q.front();
        q.pop();
        if(ptr != 0)
            cout << ' ';
        cout << BST[ptr].data;
        if(BST[ptr].lb != -1)
            q.push(BST[ptr].lb);
        if(BST[ptr].rb != -1)
            q.push(BST[ptr].rb);
    }
    return 0;
}
