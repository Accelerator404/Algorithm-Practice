/* ZJU Data Structure Mooc 19 Fall
 * 01-复杂度3 二分查找
 * 本题要求实现二分查找算法。
 * 函数接口定义：
 * Position BinarySearch( List L, ElementType X );
 * 其中List结构定义如下：
 * typedef int Position;
 * typedef struct LNode *List;
 * struct LNode {
 *     ElementType Data[MAXSIZE];
 *     Position Last; /* 保存线性表中最后一个元素的位置 */
 * };
 * L是用户传入的一个线性表，其中ElementType元素可以通过>、==、<进行比较，
 * 并且题目保证传入的数据是递增有序的。函数BinarySearch要查找X在Data中的位置，
 * 即数组下标（注意：元素从下标1开始存储）。
 * 找到则返回下标，否则返回一个特殊的失败标记NotFound。
 */

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
