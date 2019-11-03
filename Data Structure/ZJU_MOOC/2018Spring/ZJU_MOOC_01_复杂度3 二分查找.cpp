#include <stdio.h>
#include <stdlib.h>
//注意，实现的函数在最后，中间框架部分代码是空的
#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X ){
    if(L->Last == 0){
        return NotFound;
    }
    int pivot,boundL,boundR;
    boundL = 1;
    boundR = L->Last;
    while (boundL < boundR){
        pivot = (boundL + boundR)/2;
        if(L->Data[pivot] == X)
            return pivot;
        else if(L->Data[pivot] > X && pivot < boundR)
            boundR = pivot;
        else if(L->Data[pivot] < X && pivot > boundL)
            boundL = pivot;
        else if(L->Data[pivot] > X && pivot == boundR)
            boundR = boundL;
        else
            boundL = boundR;
    }
    pivot = boundL;
    if(boundL == boundR && L->Data[pivot] == X)
        return pivot;
    else
        return NotFound;
}
