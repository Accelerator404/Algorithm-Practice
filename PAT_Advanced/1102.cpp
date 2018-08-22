#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//PAT Advanced 1102 Invert a Binary Tree

typedef struct node *nodePtr;
struct node{
    int val,h = 0;
    nodePtr L,R;
};

int height(nodePtr root){
    if(root->L == nullptr && root->R == nullptr)
        return 0;
    else if(root->L != nullptr && root->R == nullptr)
        return height(root->L) + 1;
    else if(root->L == nullptr && root->R != nullptr)
        return height(root->R) + 1;
    else
        return max(height(root->L),height(root->R))+1;
}

void levelT(nodePtr root){
    queue<nodePtr> q;
    q.push(root);
    bool first = false;
    while(!q.empty()){
        nodePtr front = q.front();
        q.pop();
        if(!first){
            cout << front->val;
            first = true;
        }
        else
            cout << ' ' << front->val;
        if(front->L != nullptr)
            q.push(front->L);
        if(front->R != nullptr)
            q.push(front->R);
    }
}

void invertBT(nodePtr root){
    if(root == nullptr)
        return;
    nodePtr tmp;
    tmp = root->L;
    root->L = root->R;
    root->R = tmp;
    invertBT(root->L);
    invertBT(root->R);
}

bool firstI = false;

void inOrderT(nodePtr root){
    if(root == nullptr)
        return;
    inOrderT(root->L);
    if(!firstI){
        cout << root->val;
        firstI = true;
    } else
        cout << ' ' << root->val;
    inOrderT(root->R);
}

int main(){
    int N;
    nodePtr root;
    vector<nodePtr> seq;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        nodePtr tmp = new node;
        tmp->val = i;
        seq.push_back(tmp);
    }
    for (int i = 0; i < N; ++i) {
        char lb,rb;
        cin >> lb >> rb;
        if(lb >= '0' && lb <= '9')
            seq[i]->L = seq[lb - '0'];
        else
            seq[i]->L = nullptr;
        if(rb >= '0' && rb <= '9')
            seq[i]->R = seq[rb - '0'];
        else
            seq[i]->R = nullptr;
    }
    int maxH = 0;
    for (int i = 0; i < N; ++i) {
        seq[i]->h = height(seq[i]);
        if(seq[i]->h >= maxH){
            root = seq[i];
            maxH = seq[i]->h;
        }
    }
    invertBT(root);
    levelT(root);
    cout << endl;
    inOrderT(root);
    cout << endl;
    return 0;
}
