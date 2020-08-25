#include <iostream>
#include <vector>
using namespace std;

/*
 * PAT (Advanced Level) 1074 Reversing Linked List
 *
 * Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L.
 * For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.
 *
 * 输入格式:
 * Each input file contains one test case. For each case, the first line contains the address of the first node,
 * a positive N (≤10^5) which is the total number of nodes,
 * and a positive K (≤N) which is the length of the sublist to be reversed.
 * The address of a node is a 5-digit non-negative integer, and NULL is represented by -1.
 * Then N lines follow, each describes a node in the format:
 * Address Data Next
 * where Address is the position of the node, Data is an integer, and Next is the position of the next node.
 *
 * 输出格式:
 * For each case, output the resulting ordered linked list. Each node occupies a line,
 * and is printed in the same format as in the input.
 */

struct node{
    int addr;
    int data;
    int next;
};

int main(){
    vector<node> LinkedList;
    int beginAddr,N,K;
    cin >> beginAddr >> N >> K;
    LinkedList.resize(100000);
    for (int i = 0; i < N; ++i) {
        int addr,data,next;
        scanf("%d %d %d",&addr,&data,&next);
        LinkedList[addr].addr = addr;
        LinkedList[addr].data = data;
        LinkedList[addr].next = next;
    }
    vector<int> sub;
    int ptr = beginAddr;    // 指向下一个节点
    int prev = -25;
    while (ptr >= 0){
        if(sub.size() < K && ptr >= 0){
            sub.push_back(ptr);
            ptr = LinkedList[ptr].next;
        }
        if(sub.size() == K){
            // 反转子链表
            for (int i = sub.size()-1; i > 0; --i) {
                LinkedList[sub[i]].next = sub[i-1];
            }
            // 连接链表
            if(prev == -25)
                beginAddr = sub[sub.size()-1];
            else{
                LinkedList[prev].next = sub[sub.size()-1];
            }
            prev = sub[0];
            LinkedList[sub[0]].next = ptr;
            // 清空待反转子链表
            sub.clear();
        }
    }
    // 打印链表
    ptr = beginAddr;
    while (LinkedList[ptr].next != -1){
        printf("%05d %d %05d\n",LinkedList[ptr].addr,LinkedList[ptr].data,LinkedList[ptr].next);
        ptr = LinkedList[ptr].next;
    }
    if(LinkedList[ptr].next == -1)
        printf("%05d %d %d\n",LinkedList[ptr].addr,LinkedList[ptr].data,LinkedList[ptr].next);
    return 0;
}