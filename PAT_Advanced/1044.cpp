#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced Level 1044 Shopping in Mars

struct result{
    int startPos,endPos,totalValue;
};

bool compare(result A,result B){
    if(A.totalValue != B.totalValue)
        return A.totalValue < B.totalValue;
    else
        return A.startPos < B.startPos;
}

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> chainSum(N+1);
    vector<result> res;
    for(int i = 1;i <= N;i++){
        scanf("%d",&chainSum[i]);
        chainSum[i] += chainSum[i-1];
    }
    int minVal = 99999999;
    for(int i = 1;i <= N;i++){
        int value = 0;
        for(int j = i;j <= N;j++){
            value = chainSum[j] - chainSum[i-1];
            if(value >= M && value <= minVal){
                result t;
                t.startPos = i;
                t.endPos = j;
                t.totalValue = value;
                res.push_back(t);
                minVal = value;
                break;
            }
            else if(value > M && value > minVal){
                break;
            }
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
