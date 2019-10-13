#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced 1101 Quick Sort

/*
 * 在输入时保存原序列每一位左侧最大数，再对原序列做一次排序。若原序列中某一位同时满足
 * 1.比左侧所有数大
 * 2.排序后位置不变
 * 则该位是锚点候选。
 */

bool compare(int a,int b){
    return a<b;
}

int main(){
    int N,tMaxVal;
    vector<int> seq1,seq2,lMaxVal,pivot;
    cin >> N;
    seq1.resize(N);seq2.resize(N);lMaxVal.resize(N);
    tMaxVal = 0;
    for (int i = 0; i < N; ++i){
        scanf("%d",&seq1[i]);
        if(i>0 && seq1[i-1] > tMaxVal){
            tMaxVal = seq1[i-1];
        }
        lMaxVal[i] = tMaxVal;
    }
    seq2 = seq1;
    sort(seq2.begin(),seq2.end(),compare);
    for (int i = 0; i < N; ++i) {
        if(seq1[i] == seq2[i] && seq1[i] >= lMaxVal[i])
            pivot.push_back(seq1[i]);
    }
    printf("%d\n",pivot.size());
    bool first = false;
    for (int i = 0; i < pivot.size(); ++i) {
        if(!first)
            first = true;
        else
            printf(" ");
        printf("%d",pivot[i]);
    }
    printf("\n");
    return 0;
}
