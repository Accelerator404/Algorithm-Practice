#include <iostream>
using namespace std;

/**
 * 02-线性结构2 一元多项式的乘法与加法运算
 *
 * 设计函数分别求两个一元多项式的乘积与和。
 *
 * 输入格式:
 * 输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
 *
 * 输出格式:
 * 输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
 * 数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。
 *
 */

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType coE;
    ElementType index;
    PtrToNode   Next;
};
typedef PtrToNode List;

//删除节点
void deleteNode(List L,PtrToNode target){
    PtrToNode P1,P2;
    P1 = L;
    P2 = L->Next;
    while(P1->Next != target){
        P1 = P1->Next;
        if(P1->Next == nullptr)
            P2 = nullptr;
    }
    if(P2 != nullptr){
        P2 = P1->Next;
        P1->Next = P1->Next->Next;
        delete []P2;
    }
}

//插入节点函数，比较完善，适用于降序排列
void insertNode(List origin,PtrToNode target){
    if(target == nullptr){
        //
    }
    else if(origin->Next == nullptr){
        origin->Next = target;
        target->Next = nullptr;
    }
    else{
        PtrToNode Ptr = origin,Ptr2 = origin->Next;
        if(target->index > Ptr2->index){
            Ptr->Next = target;
            target->Next = Ptr2;
        } else if(target->index == Ptr2->index){
            Ptr2->coE += target->coE;
            if(Ptr2->coE == 0){
                deleteNode(origin,Ptr2);
            }
        }
        else{
            while (Ptr2->index > target->index){
                Ptr2 = Ptr2->Next;
                Ptr = Ptr->Next;
                if(Ptr2 == nullptr){
                    Ptr->Next = target;
                    target->Next = Ptr2;
                    break;
                }
            }
            if(Ptr->Next != target){
                if(target->index > Ptr2->index){
                target->Next = Ptr2;
                Ptr->Next = target;
                }
                else{
                    Ptr2->coE += target->coE;
                    if(Ptr2->coE == 0){
                        deleteNode(origin,Ptr2);
                    }
                }
            }
        }
    }
}

//求链表长度，0=空链表
int listLength(List & L){
    int count = 0;
    PtrToNode P = L->Next;
    while (P != nullptr){
        count++;
        P = P->Next;
    }
    return count;
}

//节点乘法，也就是单项式与单项式相乘
PtrToNode NodeMultiply(PtrToNode N1,PtrToNode N2){
    PtrToNode res = (PtrToNode)malloc(sizeof(struct Node));
    if(N1 == nullptr || N2 == nullptr){
        return nullptr;
    }
    res->Next = nullptr;
    res->coE = N1->coE * N2->coE;
    res->index = N1->index + N2->index;
    if(res->coE == 0){
        res->index = 0;
    }
    return res;
}

/*
 * 用来取链表特定位节点的函数，此处不使用
PtrToNode getExactNode(List & L,int num){
    if(num > listLength(L) || num < 1){
        return nullptr;
    }
    PtrToNode P = L;
    while(num-- && P->Next){
        P = P->Next;
    }
    return P;
}
*/

//多项式乘法
List linearListMultiply(List & List1,List & List2){
    List L = nullptr;
    L = (List)malloc(sizeof(struct Node));
    L->Next = nullptr;
    int l1 = listLength(List1),l2 = listLength(List2);
    if(l1 == 0 || l2 == 0){
        return L;
    }
    PtrToNode thisNode = List1->Next;
    while(thisNode != nullptr){
        PtrToNode thatNode = List2->Next;
        while(thatNode != nullptr){
            insertNode(L,NodeMultiply(thisNode,thatNode));
            thatNode = thatNode->Next;
        }
        thisNode = thisNode->Next;
    }
    return L;
}

//多项式加法
List linearListPlus(List & L1,List & L2){
    //初始化一个新的空链表
    List L;
    L = (List)malloc(sizeof(struct Node));
    //定义一些指针
    PtrToNode P1,P2;
    P1 = L1->Next;
    P2 = L2->Next;
    //处理空链表情形，提高速度
    if(P1 == nullptr && P2 == nullptr){
        L->Next = nullptr;
        return L;
    }
    else if(P1 == nullptr && P2 != nullptr){
        L->Next = P2;
        L2->Next = nullptr;
        return L;
    }
    else if(P1 != nullptr && P2 == nullptr){
        L->Next = P1;
        L1->Next = nullptr;
        return L;
    }
    //开始加法运算，采用直接把链表节点拷贝一份插入新链表的方法（我困了只能想到这个）
    while(P1 != nullptr){
        //拷贝的节点为便于传递，用指针初始化
        auto kit = (PtrToNode)malloc(sizeof(struct Node));
        kit->index = P1->index;
        kit->coE = P1->coE;
        kit->Next = nullptr;
        insertNode(L,kit);
        P1 = P1->Next;
    }
    while(P2 != nullptr){
        auto kit = (PtrToNode)malloc(sizeof(struct Node));
        kit->index = P2->index;
        kit->coE = P2->coE;
        kit->Next = nullptr;
        insertNode(L,kit);
        P2 = P2->Next;
    }
    return L;
}

void readList(List L){
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int coe,ind;
        auto kit = (PtrToNode)malloc(sizeof(struct Node));
        cin >> coe >> ind;
        kit->coE = coe;
        kit->index = ind;
        kit->Next = nullptr;
        insertNode(L,kit);
    }
}

void PrintList(List L){
    PtrToNode P = L->Next;
    if(P == nullptr){
        cout << 0 << ' ' << 0 << endl;
    }
    else{
        cout << P->coE << ' ' << P->index;
        P = P->Next;
        while(P != nullptr){
            cout << ' ' << P->coE << ' ' << P->index;
            P = P->Next;
        }
        cout << endl;
    }
}

int main()
{
    List List1 = nullptr,List2 = nullptr;
    List1 = (List)malloc(sizeof(struct Node));
    List2 = (List)malloc(sizeof(struct Node));
    List1->Next = nullptr;
    List2->Next = nullptr;
    readList(List1);
    readList(List2);
    List resultM = linearListMultiply(List1,List2);
    List resultP = linearListPlus(List1,List2);
    PrintList(resultM);
    PrintList(resultP);
    return 0;
}

