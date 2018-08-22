#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

//PAT Advanced 1105 Spiral Matrix

int findM(int N){
    int roof = ceil(sqrt(N))+1,m = N,n = 1;
    for (int i = roof; i >= 1; --i) {
        if(n > m)
            break;
        if(N % i == 0){
            m = i;
            n = N / m;
        }
    }
    return m;
}

int main(){
    int N,Matrix[10001][10001];
    cin >> N;
    vector<int> seq(N);
    for (int i = 0; i < N; ++i) {
        cin >> seq[i];
    }
    sort(seq.begin(),seq.end(),greater_equal<int>());
    //todo

    return 0;
}
