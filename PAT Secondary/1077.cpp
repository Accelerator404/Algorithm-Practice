#include <iostream>
using namespace std;

//PAT Level.2 No.1077 “互评成绩计算”

int calResult(int & N,int & M){
    int G1 = 0,G2;
    int validCount = N - 1,maxInput = 0,minInput = 100;
    int inputNum[N - 1];
    cin >> G2;
    for (int j = 0; j < N - 1; ++j) {
        cin >> inputNum[j];
    }
    for (int i = 0; i < N - 1; ++i) {
        int input = inputNum[i];
        if(input > M || input < 0){
            validCount--;
            continue;
        }
        if(input < minInput)
            minInput = input;
        if(input > maxInput)
            maxInput = input;
        G1 += input;
    }
    G1 = G1 - maxInput - minInput;
    validCount -= 2;
    G1 = G1/validCount;
    //int抹零，所以加0.5实现四舍五入
    return (G1 + G2 + 1)/2;
}

int main() {
    int N,M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cout << calResult(N,M) << endl;
    return 0;
}
