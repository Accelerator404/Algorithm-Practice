#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;
/*
 * 04-树5 Root of AVL Tree
 *
 */

//因为偷懒，所以基于二叉搜索树的操作函数，扩充平衡操作
//越写越复杂，只能注意每一次旋转都会改变子树或者主树根的位置，所以设定平衡函数总会返回平衡后的主树根，同时也是返回值所在节点

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
    ElementType AVLBalanceValue=0;
};


BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

BinTree Insert(BinTree BST,ElementType X){
    if(!BST){
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    } else{
        if(X < BST->Data)
            BST->Left = Insert(BST->Left,X);
        else if(X > BST->Data)
            BST->Right = Insert(BST->Right,X);
    }
    return BST;
}

BinTree Delete( BinTree BST, ElementType X ){
    Position Tmp;
    if(!BST) printf("Not Found\n");
    else if(X < BST->Data)
        BST->Left = Delete(BST->Left,X);
    else if(X > BST->Data)
        BST->Right = Delete(BST->Right,X);
    else{
        if(BST->Left && BST->Right){
            Tmp = FindMin(BST->Right);
            BST->Data = Tmp->Data;
            BST->Right = Delete(BST->Right,BST->Data);
        }
        else{
            Tmp = BST;
            if(!BST->Left)
                BST = BST->Right;
            else if(!BST->Right)
                BST = BST->Left;
            free(Tmp);
        }
    }
    return BST;
}

Position Find( BinTree BST, ElementType X ){
    while(BST){
        if(X > BST->Data)
            BST = BST->Right;
        else if(X < BST->Data)
            BST = BST->Left;
        else
            return BST;
    }
    return NULL;
};

Position FindMin( BinTree BST ){
    if(!BST)
        return NULL;
    else if(!BST->Left)
        return BST;
    else
        return FindMin(BST->Left);
};

Position FindMax( BinTree BST ){
    if(BST)
        while(BST->Right)
            BST = BST->Right;
    return BST;
};

int getNodeHeight(BinTree BST){
    if(BST == NULL)
        return 0;
    if(BST->Left == NULL && BST->Right == NULL)
        return 1;
    else{
        int LB = getNodeHeight(BST->Left);
        int RB = getNodeHeight(BST->Right);
        if(LB > RB)
            return LB+1;
        else
            return RB+1;
    }
}

int calNodeBalanceVal(Position BST){
    if(!BST)
        return 0;
    return getNodeHeight(BST->Left)-getNodeHeight(BST->Right);
}

bool isBalance(Position node){
    if(!node || node->Left == NULL && node->Right == NULL)
        return true;
    if(node->AVLBalanceValue >= 2 || node->AVLBalanceValue <=-2)
        return false;
    else
        return true;
}

BinTree rebalanceLabor(BinTree BST){
    Position A,B,C;
    BinTree BL,BR,CL,CR;
    //LL与LR
    if(BST->AVLBalanceValue > 0){
        if(BST->Left->AVLBalanceValue > 0){     //LL
            A = BST;
            B = A->Left;BR = B->Right;
            B->Right = A;
            A->Left =BR;
            return B;
        }
        else if(BST->Left->AVLBalanceValue < 0){    //LR
            A = BST;
            B = A->Left;
            C = B->Right;
            CL = C->Left;
            CR = C->Right;
            C->Left = B;
            C->Right =A;
            B->Right = CL;
            A->Left = CR;
            return C;
        }
    }
        //RR与RL
    else if(BST->AVLBalanceValue < 0){
        if(BST->Right->AVLBalanceValue <0){   //RR
            A = BST;
            B = A->Right;
            BL = B->Left;
            BR = B->Right;
            B->Left =A;
            A->Right = BL;
            return B;
        }
        else if(BST->Right->AVLBalanceValue>0){    //RL
            A = BST;
            B = A->Right;
            C = B->Left;
            CL = C->Left;
            CR = C->Right;
            A->Right = CL;
            C->Left = A;
            C->Right = B;
            B->Left = CR;
            return C;
        }
    }
}

BinTree reBalanceWorker(BinTree BST){
    BinTree Entry = BST,tgt = BST;
    bool left = true;
    if(isBalance(Entry))
        return Entry;
    while (!isBalance(BST->Left) || !isBalance(BST->Right)){
        tgt = BST;
        if(!isBalance(BST->Left)){
            BST = BST->Left;
            left = true;
        }
        else if(!isBalance(BST->Right)){
            BST = BST->Right;
            left = false;
        }
    }
    if(Entry == BST)
        return rebalanceLabor(BST);
    else{
        if(left)
            tgt->Left = rebalanceLabor(BST);
        else
            tgt->Right = rebalanceLabor(BST);
        return Entry;
    }
}


BinTree reBalance(BinTree BST){
    BinTree Entry = BST;
    if(!isBalance(Entry)){
        Entry = reBalanceWorker(Entry);
    }
    else {
        stack<BinTree> S;
        while (BST || !S.empty()) {
            while (BST) {
                S.push(BST);
                BST = BST->Left;
            }
            if (!S.empty()) {
                BST = S.top();
                S.pop();
                if (!isBalance(BST->Left)) {
                    BST->Left = reBalanceWorker(BST->Left);
                    break;
                }
                else if(!isBalance(BST->Right)){
                    BST->Right = reBalanceWorker(BST->Right);
                    break;
                }
                BST = BST->Right;
            }
        }
    }
    return Entry;
}


bool calculateBalanceValue(BinTree BST){
    stack<BinTree> S;
    BST->AVLBalanceValue = calNodeBalanceVal(BST);
    bool Balance = true;
    while(BST || !S.empty()){
        while (BST){
            S.push(BST);
            BST = BST->Left;
        }
        if(!S.empty()){
            BST = S.top();
            S.pop();
            BST->AVLBalanceValue = calNodeBalanceVal(BST);
            if(!isBalance(BST)){
                Balance = false;
            }
            BST = BST->Right;
        }
    }
    return Balance;
}



int main()
{
    BinTree BST = NULL;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        BST = Insert(BST,tmp);
        if(!calculateBalanceValue(BST))
            BST = reBalance(BST);
    }
    calculateBalanceValue(BST);
    while (!calculateBalanceValue(BST)){
        BST = reBalance(BST);
    }
    cout << BST->Data;
    return 0;
}

