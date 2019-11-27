#include <iostream>
#include <vector>
using namespace std;

/*
 * PAT (Advanced Level) 1098 Insertion or Heap Sort
 *
 * According to Wikipedia:
 * Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
 * Each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.
 * Heap sort divides its input into a sorted and an unsorted region,
 * and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region.
 * it involves the use of a heap data structure rather than a linear-time search to find the maximum.
 * Now given the initial sequence of integers,
 * together with a sequence which is a result of several iterations of some sorting method,
 * can you tell which sorting method we are using?
 *
 * 输入格式:
 * Each input file contains one test case.
 * For each case, the first line gives a positive integer N (≤100).
 * Then in the next line, N integers are given as the initial sequence.
 * The last line contains the partially sorted sequence of the N numbers.
 * It is assumed that the target sequence is always ascending.
 * All the numbers in a line are separated by a space.
 *
 * 输出格式:
 * For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial result.
 * Then run this method for one more iteration and output in the second line the resulting sequence.
 * It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space,
 * and there must be no extra space at the end of the line.
 */
// 未解决，测试点5无法通过(最大N，Hp，后面x位没变化)

bool seqDetector(const vector<int> & originSeq,const vector<int> & midSeq,int & divide){
    // while the method is heap sort return true
    // 堆排序的数组结构是一个最大堆+一个排好的序列，且这个序列所有数均大于等于堆顶
    // 插入排序的未排序序列在队尾，与原队列相同
    // 但也要考虑原序列部分排好序，这时堆排序中间过程的后半序列是和原序列一样的
    int pivot = 0;
    while (pivot < midSeq.size()-1 && midSeq[pivot] <= midSeq[pivot+1])
        pivot++;
    divide = pivot;
    pivot++;
    // 现在pivot指向第一位从前开始未排好序的位置，如果pivot=size，则全序列已排好
    // 如果未排序位置的数与原序列相等，就是插入排序
    while (pivot < midSeq.size() && originSeq[pivot] == midSeq[pivot])
        pivot++;
    return pivot != midSeq.size();
}

void makeHeap(vector<int> & array,int low,int high){
    if(low > high)
        return;
    int i = low, j = low + 1;
    // 从堆顶开始向下调整
    while(j <= high) {
        if(j + 1 <= high && array[j] < array[j + 1])
            j = j + 1;  // 选择两个子节点中较大者以与根节点比较/交换
        if (array[i] >= array[j])
            break;
        swap(array[i], array[j]);
        // 将原为堆顶的这个数继续向下移
        i = j;
        j = i * 2;
    }
}

void nextStep_HeapSort(vector<int> & midSeq){
    int divide = midSeq.size()-1;
    while (divide > 0 && midSeq[0] <= midSeq[divide]){
        divide--;
    }
    if(divide <= 0)
        return; // 堆排序完毕
    swap(midSeq[0],midSeq[divide]);
    makeHeap(midSeq,0,divide-1);    // 重建堆
}

void nextStep_InsertionSort(vector<int> & midSeq,int divide){
    if(divide+1 < midSeq.size()){
        int tmp = midSeq[divide+1];
        while (tmp < midSeq[divide]){
            swap(midSeq[divide],midSeq[divide+1]);
            divide--;
        }
    }
}

int main(){
    int N,divide;
    cin >> N;
    vector<int> originSeq(N),midSeq(N);
    for (int i = 0; i < N; ++i) {
        cin >> originSeq[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> midSeq[i];
    }
    if(seqDetector(originSeq,midSeq,divide)){
        cout << "Heap Sort" << endl;
        nextStep_HeapSort(midSeq);
    }
    else{
        cout << "Insertion Sort" << endl;
        nextStep_InsertionSort(midSeq,divide);
    }
    for (int i = 0; i < midSeq.size(); ++i) {
        if(i == 0)
            printf("%d",midSeq[i]);
        else{
            printf(" %d",midSeq[i]);
        }
    }
    cout << endl;
    return 0;
}