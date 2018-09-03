#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced Level 1052 Linked List Sorting

struct node{
    int myAddr,nextAddr,data;
};

bool compare(node A,node B){
    return A.data < B.data;
}

int main() {
    int N,enterAddr;
    vector<node> memory(100001),sortCache;
    cin >> N >> enterAddr;
    for (int i = 0; i < N; ++i) {
        node input;
        scanf("%d%d%d",&input.myAddr,&input.data,&input.nextAddr);
        memory[input.myAddr] = input;
    }
    for (int i = enterAddr; i != -1 ; i = memory[i].nextAddr) {
        sortCache.push_back(memory[i]);
    }
    if(sortCache.size() == 0)
        printf("0 -1\n");
    else {
        sort(sortCache.begin(), sortCache.end(), compare);
        for (auto i = sortCache.begin(); i != sortCache.end(); ++i) {
            if (i + 1 != sortCache.end())
                i->nextAddr = (i + 1)->myAddr;
            else
                i->nextAddr = -1;
        }
        enterAddr = sortCache[0].myAddr;
        printf("%lu %05d\n", sortCache.size(), enterAddr);
        for (auto it = sortCache.begin(); it != sortCache.end(); it++) {
            printf("%05d %d ", it->myAddr, it->data);
            if(it != sortCache.end()-1)
                printf("%05d\n",(it+1)->myAddr);
            else
                printf("-1\n");
        }
    }
    return 0;
}
