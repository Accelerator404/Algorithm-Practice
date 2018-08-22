#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//PAT Advanced 1102 Invert a Binary Tree

/*
 * 根结点是所有左右结点中没有出现的那个结点;
 * 对中序遍历算法略作修改。
 */
typedef struct node *nodePtr;
struct node{
    int val;
    nodePtr L,R;
};
vector<int> in;

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

void inOrderT(nodePtr root){
    if(root == nullptr)
        return;
    inOrderT(root->L);
    in.push_back(root->val);
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
    vector<int> book(N);
    for (int i = 0; i < N; ++i) {
        char lb,rb;
        cin >> lb >> rb;
        if(lb != '-'){
            seq[i]->L = seq[lb - '0'];
            book[lb -'0'] = 1;
        }
        else
            seq[i]->L = nullptr;
        if(rb != '-') {
            seq[i]->R = seq[rb - '0'];
            book[rb - '0'] = 1;
        }
        else
            seq[i]->R = nullptr;
    }
    for(int i = 0; i < N; i++) {
        if(book[i] == 0) {
            root = seq[i];
            break;
        }
    }
    invertBT(root);
    levelT(root);
    cout << endl;
    inOrderT(root);
    cout << in[0];
    for (int i = 1; i < N; ++i) {
        cout << ' ' << in[i];
    }
    return 0;
}
