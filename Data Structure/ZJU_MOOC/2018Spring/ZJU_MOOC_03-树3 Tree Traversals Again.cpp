#include <iostream>
#include <stack>
#include <string>
using namespace std;
/**
 * 03-树3 Tree Traversals Again
 *
 */

typedef struct node *Tree;
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

bool first = true;

void PostOrderTraversal(Tree BT){
    if(BT){
        PostOrderTraversal(BT->LSon);
        PostOrderTraversal(BT->RSon);
        if(first){
            cout << BT->data;
            first = false;
        }
        else
            cout << ' ' << BT->data;
    }
}

int main(){
    int N,count=0;
    cin >> N;
    Tree ptr = nullptr,root=nullptr;
    stack<Tree > S;
    while(count++ < 2*N){
        string comm;
        cin >> comm;
        if(comm == "Push"){
            int tmp;
            cin >> tmp;
            //压入根节点
            if(!root){
                root = createTree(tmp);
                S.push(root);
            }
                //创建压入右儿子节点,弹出后的下一次压入必插在弹出点的右侧（中序遍历）
            else if(ptr){
                ptr->RSon = createTree(tmp);
                S.push(ptr->RSon);
                //置空指针，下一次压入会压在栈顶（即本节点）的左侧
                ptr = nullptr;
            }
                //创建压入左节点
            else{
                S.top()->LSon = createTree(tmp);
                S.push(S.top()->LSon);
            }

        }
        else if(comm == "Pop"){
                ptr = S.top();
                S.pop();
        }
    }
    while(!S.empty()){
        S.pop();
    }
    PostOrderTraversal(root);
    cout << endl;
    return 0;
}
