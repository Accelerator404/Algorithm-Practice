#include <iostream>
#include <map>
using namespace std;
/**
 * 03-树1 树的同构
 * 给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。
 * 例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。
 * 现给定两棵树，请你判断它们是否是同构的。
 * 输入格式:
 * 输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；
 * 随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。
 * 如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。
 *
 * 输出格式:
 * 如果两棵树是同构的，输出“Yes”，否则输出“No”。
 * 
 */

typedef struct node *ptrToNode;
struct node{
    char Data;
    int No;
    ptrToNode LSon;
    ptrToNode RSon;
    int LSonNo,RSonNo;
};


ptrToNode createTree(char K,int No){
    ptrToNode inode;
    inode = (ptrToNode)malloc(sizeof(struct node));
    inode->Data = K;
    inode->LSon = nullptr;
    inode->RSon = nullptr;
    inode->No = No;
    inode->LSonNo = -1;
    inode->RSonNo = -1;
    return inode;
}
//卡了我1小时的问题就在此处，仅遍历一遍不足以找到根节点——那就遍历2遍吧。等待一个更好的找根节点算法。
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

bool compareForce(ptrToNode & Tree1,ptrToNode & Tree2){
    //空树相等
    if((Tree1 == nullptr) && (Tree2 == nullptr))
        return true;
    //空树与非空树不等
    else if((Tree1 == nullptr) || (Tree2 == nullptr))
        return false;
    //树内数据不等则不等
    else if(Tree1->Data!=Tree2->Data)
        return false;
    //左侧均空检查右侧子树
    if((Tree1->LSon== nullptr)&&(Tree2->LSon== nullptr))
        return compareForce(Tree1->RSon,Tree2->RSon);
    //左侧子树数据相等则递归检查左侧右侧子树
    if((Tree1->LSon!= nullptr&&Tree2->LSon!= nullptr)&&(Tree1->LSon->Data==Tree2->LSon->Data))
        return (compareForce(Tree1->LSon,Tree2->LSon)&&compareForce(Tree1->RSon,Tree2->RSon));
        //否则交换左右子树再检查
    else
        return (compareForce(Tree1->LSon,Tree2->RSon)&&compareForce(Tree1->RSon,Tree2->LSon));
}


int main(){
    int N1,N2;
    //map暂存节点指针数据（链表——二叉树）
    map<int,ptrToNode> list1,list2;
    cin >> N1;
    ptrToNode Tree1,Tree2;
    list1[-1] = nullptr;
    list2[-1] = nullptr;
    for (int i = 0; i < N1; ++i) {
        char da,Ls,Rs;
        int Lsi,Rsi;
        cin >> da >> Ls >> Rs;
        if(Ls == '-')
            Lsi = -1;
        else
            Lsi = Ls - '0';
        if(Rs == '-')
            Rsi = -1;
        else
            Rsi = Rs - '0';
        list1[i] = createTree(da,i);
        list1[i]->LSonNo = Lsi;
        list1[i]->RSonNo = Rsi;
    }
    cin >> N2;
    for (int i = 0; i < N2; ++i) {
        char da,Ls,Rs;
        int Lsi,Rsi;
        cin >> da >> Ls >> Rs;
        if(Ls == '-')
            Lsi = -1;
        else
            Lsi = Ls - '0';
        if(Rs == '-')
            Rsi = -1;
        else
            Rsi = Rs - '0';
        list2[i] = createTree(da,i);
        list2[i]->LSonNo = Lsi;
        list2[i]->RSonNo = Rsi;
    }
    //将节点组装成链表树
    for (int i = 0; i < N1; ++i) {
        list1[i]->LSon = list1[list1[i]->LSonNo];
        list1[i]->RSon = list1[list1[i]->RSonNo];
    }
    for (int i = 0; i < N2; ++i) {
        list2[i]->LSon = list2[list2[i]->LSonNo];
        list2[i]->RSon = list2[list2[i]->RSonNo];
    }
    //找出根节点
    Tree1 = list1[findRoot(list1,N1)];
    Tree2 = list2[findRoot(list2,N2)];
    //以上构建完成两棵树

    if(compareForce(Tree1,Tree2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
