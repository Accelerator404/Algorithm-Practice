#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
/**
 * 03-树2 List Leaves
 * Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.
 *
 * Input Specification:
 * Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the
 * total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow,
 * each corresponds to a node, and gives the indices of the left and right children of the node.
 * If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.
 *
 * Output Specification:
 * For each test case, print in one line all the leaves' indices in the order of top down, and left to right.
 * There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.
 *
 */

typedef struct node *ptrToNode;
struct node{
    int No;
    ptrToNode LSon;
    ptrToNode RSon;
    int LSonNo,RSonNo;
};


ptrToNode createTree(int No){
    ptrToNode inode;
    inode = (ptrToNode)malloc(sizeof(struct node));
    inode->LSon = nullptr;
    inode->RSon = nullptr;
    inode->No = No;
    inode->LSonNo = -1;
    inode->RSonNo = -1;
    return inode;
}
//等待一个更好的找根节点算法。
int findRoot(map<int,ptrToNode> list,int N){
    int no = 0;
    for (int i = 0; i < N; ++i) {
        if(list[i]->LSonNo == no || list[i]->RSonNo == no){
            no = i;
        }
    }
    for (int i = 0; i < N; ++i) {
        if(list[i]->LSonNo == no || list[i]->RSonNo == no){
            no = i;
        }
    }
    return no;
}

vector<int> outList;

//需要使用层序遍历实现按从上到下输出,使用STL的队列

void listLeaves(ptrToNode Tree){
    queue<ptrToNode> Q;
    ptrToNode T;
    if(!Tree)
        return;
    //每层节点入队
    Q.push(Tree);
    while (!Q.empty()){
        T=Q.front();
        Q.pop();
        if(!T->LSon&&!T->RSon)
            outList.push_back(T->No);
        if(T->LSon)
            Q.push(T->LSon);
        if(T->RSon)
            Q.push(T->RSon);
    }
}

int main(){
    int N;
    //map暂存节点指针数据（链表——二叉树）
    map<int,ptrToNode> list;
    cin >> N;
    ptrToNode Tree;
    list[-1] = nullptr;
    for (int i = 0; i < N; ++i) {
        char Ls,Rs;
        int Lsi,Rsi;
        cin >> Ls >> Rs;
        if(Ls == '-')
            Lsi = -1;
        else
            Lsi = Ls - '0';
        if(Rs == '-')
            Rsi = -1;
        else
            Rsi = Rs - '0';
        list[i] = createTree(i);
        list[i]->LSonNo = Lsi;
        list[i]->RSonNo = Rsi;
    }

    //将节点组装成链表树
    for (int i = 0; i < N; ++i) {
        list[i]->LSon = list[list[i]->LSonNo];
        list[i]->RSon = list[list[i]->RSonNo];
    }
    //找出根节点
    Tree = list[findRoot(list,N)];
    //以上构建完成

    listLeaves(Tree);
    for (auto i = outList.begin(); i != outList.end() ; ++i) {
        if(i == outList.begin())
            cout<<*i;
        else
        cout <<' ' << *i;
    }
    return 0;
}
