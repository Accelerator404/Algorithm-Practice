#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced Level 1085 Perfect Sequence

int Search(int leftB,int N,int limit,vector<int> & mainSeq){
    if(limit >= mainSeq[N-1])
        return N-1;
    int lb = leftB,rb = N;
    while(lb < rb) {
        int mid = (lb + rb) / 2;
        if(mainSeq[mid] <= limit){
            lb = mid;
        } else
            rb = mid - 1;
    }
    return lb;
}

int main() {
    int N,p;
    cin >> N >> p;
    vector<int> mainSeq(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d",&mainSeq[i]);
    }
    sort(mainSeq.begin(),mainSeq.end(),less<int>());
    int maxCounts = 0,leftB = 0,rightB;
    while(true){
        int limit = mainSeq[leftB] * p;
        rightB = Search(leftB,N,limit,mainSeq);
        int tempCount = rightB - leftB + 1;
        if(tempCount > maxCounts){
            maxCounts = tempCount;
        }
        leftB++;
        if(leftB >= N-1 || (N - leftB) < maxCounts || limit > mainSeq[N-1]){
            break;
        }
    }
    cout << maxCounts;
    return 0;
}
