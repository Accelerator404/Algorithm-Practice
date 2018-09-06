#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced Level 1044 Shopping in Mars

struct result{
    int startPos,endPos,totalValue;
};

int N,M;

void Search(int i,int &j,int &tempVal,const vector<int>& chainSum){
    int left = i,right = N;
    while (left < right){
        int mid = (left + right)/2;
        if(chainSum[mid] - chainSum[i-1] >= M)
            right = mid;
        else
            left = mid+1;
    }
    j = right;
    tempVal = chainSum[j] - chainSum[i-1];
}

bool compare(result A,result B){
    if(A.totalValue != B.totalValue)
        return A.totalValue < B.totalValue;
    else
        return A.startPos < B.startPos;
}

int main() {
    cin >> N >> M;
    vector<int> chainSum(N+1);
    vector<result> res;
    for(int i = 1;i <= N;i++){
        scanf("%d",&chainSum[i]);
        chainSum[i] += chainSum[i-1];
    }
    int minVal = chainSum[N];
    for(int i = 1;i <= N;i++){
        int value = 0, j;
        Search(i,j,value,chainSum);
        if(value > minVal)
            continue;
        if(value >= M){
            if(value < minVal){
                res.clear();
                minVal = value;
            }
            result t;
            t.startPos = i;
            t.endPos = j;
            t.totalValue = value;
            res.push_back(t);
        }
    }
    sort(res.begin(),res.end(),compare);
    for(int i = 0; i < res.size();i++){
        if(res[i].totalValue == minVal)
            printf("%d-%d\n",res[i].startPos,res[i].endPos);
        else
            break;
    }
    return 0;
}
