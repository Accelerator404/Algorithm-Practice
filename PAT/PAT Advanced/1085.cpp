#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced Level 1085 Perfect Sequence

/*
 * 使用遍历查找即可，没有使用二分查找的必要。
 */

int main() {
    long long int N,p;
    cin >> N >> p;
    vector<int> mainSeq(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d",&mainSeq[i]);
    }
    sort(mainSeq.begin(),mainSeq.end(),less<int>());
    int maxCounts = 0,tempCount = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+maxCounts; j < N; ++j) {
            if(mainSeq[j] <= mainSeq[i] * p){
                tempCount = j-i+1;
                if(tempCount > maxCounts)
                    maxCounts = tempCount;
            } else
                break;
        }
    }
    cout << maxCounts;
    return 0;
}
