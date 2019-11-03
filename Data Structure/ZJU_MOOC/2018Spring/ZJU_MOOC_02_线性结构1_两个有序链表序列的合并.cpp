#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge(List L1,List L2){
    //初始化一个新的空链表
    List L;
    L = (List)malloc(sizeof(struct Node));
    //定义一些指针
    PtrToNode P1,P2,Ptr;
    P1 = L1->Next;
    P2 = L2->Next;
    //处理空链表情形
    if(P1 == NULL && P2 == NULL){
        L->Next = NULL;
        return L;
    }
    else if(P1 == NULL && P2 != NULL){
        L->Next = P2;
        L2->Next = NULL;
        return L;
    }
    else if(P1 != NULL && P2 == NULL){
        L->Next = P1;
        L1->Next = NULL;
        return L;
    }
    //链接第一个节点
    if(P1->Data < P2->Data){
        L->Next = P1;
        L1->Next = P1->Next;
        P1 = L1->Next;
    }
    else
    {
        L->Next = P2;
        L2->Next = P2->Next;
        P2 = L2->Next;
    }
    Ptr = L->Next;
    Ptr->Next = NULL;
    //处理到至少一个链表变空
    while (P1 != NULL && P2 != NULL){
        if(P1->Data < P2->Data){
            Ptr->Next = P1;
            L1->Next = P1->Next;
            P1 = L1->Next;
        }
        else
        {
            Ptr->Next = P2;
            L2->Next = P2->Next;
            P2 = L2->Next;
        }
        Ptr = Ptr->Next;
    }
    //扫尾
    if(P1 == NULL && P2 != NULL){
        Ptr->Next = P2;
        L2->Next = NULL;
    }
    else if(P2 == NULL && P1 != NULL){
        Ptr->Next = P1;
        L1->Next = NULL;
    }
    else
        Ptr->Next = NULL;
    return L;
}
