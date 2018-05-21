#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/**
 * 04-树4 是否同一棵二叉搜索树
 *
 */

/*
说明：这个程序因为包含了实现二分搜索树的尝试，所以代码很脏。checkSameTree函数因为没有分拆为子函数所以很乱，
  实质就是对两棵树各生成中序遍历与先序遍历结果，两种分别相同则树是同一棵树。
要点：insert函数会返回插入节点地址。

*/
//个人的二分搜索树实现（链表，限正整数）
typedef struct node *Tree;
typedef struct node *ptrToNode;
struct node{
    int data;
    Tree LSon;
    Tree RSon;
};

Tree createTree(int No){
    Tree iTree = (Tree)malloc(sizeof(struct node));
    iTree->LSon = nullptr;
    iTree->RSon = nullptr;
    iTree->data = No;
    return iTree;
}
/*
void PreOrderTraversal(Tree BT){
    if(BT){
        cout << BT->data << endl;
        PreOrderTraversal(BT->LSon);
        PreOrderTraversal(BT->RSon);
    }
}

void InOrderTraversal(Tree BT){
    if(BT){
        InOrderTraversal(BT->LSon);
        cout << BT->data << endl;
        InOrderTraversal(BT->RSon);
    }
}

void PostOrderTraversal(Tree BT){
    if(BT){
        PostOrderTraversal(BT->LSon);
        PostOrderTraversal(BT->RSon);
        cout << BT->data << endl;
    }
}


void LevelOrderTraversal(Tree iTree){
    queue<ptrToNode> Q;
    ptrToNode T;
    if(!iTree)
        return;
    //每层节点入队
    Q.push(iTree);
    while (!Q.empty()){
        T=Q.front();
        cout << T->data << endl;
        Q.pop();
        if(T->LSon)
            Q.push(T->LSon);
        if(T->RSon)
            Q.push(T->RSon);
    }
}

Tree findRootNode(vector<int> InOrderList,vector<int> AnotherList,bool AnotherListIsPreOrder){
    if(AnotherListIsPreOrder){
        //todo
    }
    else{
        //todo
    }
}
ptrToNode find(Tree & iTree,int & X){
    ptrToNode ptr = iTree;
    while(ptr){
        if(X > ptr->data)
            ptr = ptr->RSon;
        else if(X < ptr->data)
            ptr = ptr->LSon;
        else
            return ptr;
    }
    return nullptr;
}
 */
Tree insert(Tree ptr,int X){
    if(!ptr){
        ptr = (Tree)malloc(sizeof(struct node));
        ptr->data = X;
        ptr->LSon = ptr->RSon =nullptr;
    } else{
        if(X < ptr->data)
            ptr->LSon = insert(ptr->LSon,X);
        else if(X > ptr->data)
            ptr->RSon = insert(ptr->RSon,X);
    }
    return ptr;
}

Tree deleteNode(int X,Tree iTree){
    //todo
}

bool checkSameTree(Tree TreeA,Tree TreeB){
    Tree IT = TreeA;
    stack<Tree> S;
    vector<int> InOTQueueA,InOTQueueB,PreOTQueueA,PreOTQueueB;
    while(IT || !S.empty()){
        while (IT){
            S.push(IT);
            IT = IT->LSon;
        }
        if(!S.empty()){
            IT = S.top();
            S.pop();
            InOTQueueA.push_back(IT->data);
            IT = IT->RSon;
        }
    }
    IT = TreeB;
    while(!S.empty()){
        S.pop();
    }
    while(IT || !S.empty()){
        while (IT){
            S.push(IT);
            IT = IT->LSon;
        }
        if(!S.empty()){
            IT = S.top();
            S.pop();
            InOTQueueB.push_back(IT->data);
            IT = IT->RSon;
        }
    }
    while(!S.empty()){
        S.pop();
    }
    IT = TreeA;
    while(IT || !S.empty()){
        if (IT){
            PreOTQueueA.push_back(IT->data);
            S.push(IT);
            IT = IT->LSon;
        }
        else{
            IT = S.top();
            S.pop();
            IT = IT->RSon;
        }
    }
    while(!S.empty()){
        S.pop();
    }
    IT = TreeB;
    while(IT || !S.empty()){
        if (IT){
            PreOTQueueB.push_back(IT->data);
            S.push(IT);
            IT = IT->LSon;
        }
        else{
            IT = S.top();
            S.pop();
            IT = IT->RSon;
        }
    }
    while(!S.empty()){
        S.pop();
    }
    for (int i = 0; i < InOTQueueA.size(); ++i) {
        if(InOTQueueA[i]!=InOTQueueB[i] || PreOTQueueA[i]!=PreOTQueueB[i])
            return false;
    }
    return true;
}

int main(){
    while(true){
        int N,L;
        cin >> N;
        if(N == 0)
            break;
        cin >> L;
        Tree OrigT = nullptr;
        for (int i = 0; i < N; ++i) {
            int tmp;
            cin >> tmp;
            OrigT = insert(OrigT,tmp);
        }
        while(L--){
            Tree CompT = nullptr;
            for (int i = 0; i < N; ++i) {
                int tmp;
                cin >> tmp;
                CompT = insert(CompT,tmp);
            }
            if(checkSameTree(OrigT,CompT))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
