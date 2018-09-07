#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//PAT Advanced Level 1113 Integer Set Partition

const int INF = INT32_MAX;

int main() {
    int N;
    cin >> N;
    vector<int> seq(N),sum(N),rsum(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d",&seq[i]);
    }
    sort(seq.begin(),seq.end());
    int minN1N2 = INF,maxS1S2 = 0,S1 = 0,S2 = 0;
    sum[0] = seq[0];
    rsum[N-1] = seq[N-1];
    for (int i = 1; i < N; ++i) {
        sum[i] = sum[i-1] + seq[i];
    }
    for (int i = N-2; i >= 0; --i) {
        rsum[i] = rsum[i+1] + seq[i];
    }
    for (int i = 0; i < N-1; ++i) {
        S1 = sum[i],S2 = rsum[i+1];
        int n1 = i + 1,n2 = N - n1;
        if(abs(n1-n2) < minN1N2){
            minN1N2 = abs(n1-n2);
            maxS1S2 = abs(S1-S2);
        }
        else if(abs(n1-n2) == minN1N2 && maxS1S2 < abs(S1-S2))
            maxS1S2 = abs(S1-S2);
    }
    cout << minN1N2 << ' ' << maxS1S2;
    return 0;
}
