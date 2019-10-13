#include <iostream>
using namespace std;
/*
 * 05-树7 堆中的路径
 * 将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。
 *
 * 输入格式:
 * 每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。
 * 下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。
 *
 * 输出格式:
 * 对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。
 */

#define MINLIMIT -10086    /* “哨兵”数，小于插入数的界限-10000 */

typedef int ElementType;
typedef class Heap *MinHeap; /* 堆的类型定义 */
class Heap {
private:
    ElementType *Data; /* 存储元素的数组 */
    int Size;          /* 堆中当前元素个数 */
    int Capacity;      /* 堆的最大容量 */
public:
    Heap(){Size = 0;}
    MinHeap defineHeap(int MaxSize){
        Data = new ElementType[MaxSize+1];
        Size = 0;
        Capacity = MaxSize;
        Data[0] = MINLIMIT;
        return this;
    }
    bool IsFull(){
        return (Size == Capacity);
    }
    bool insert(ElementType X){
        int i ;
        if(IsFull()){
            return false;
        }
        i = ++Size;
        for (; Data[i/2] > X; i/=2) {
            Data[i] = Data[i/2];
        }
        Data[i] = X;
        return true;
    }
    bool isEmpty(){
        return (Size == 0);
    }
    void track(int p){
        if(p<=Size){
            cout << Data[p];
            p/=2;
            for(;p>0;p/=2){
                cout << ' ' << Data[p];
            }
            cout << endl;
        }
    }
    ~Heap(){
        delete []Data;
    }
};

int main()
{
    int N,M;
    cin >> N >> M;
    MinHeap H  = new Heap();
    H->defineHeap(N);
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        H->insert(temp);
    }
    for (int j = 0; j < M; ++j) {
        int temp;
        cin >> temp;
        H->track(temp);
    }
    return 0;
}

