#include <iostream>
#include <vector>
using namespace std;

//PAT Advanced Level 1128 N Queens Puzzle

int main() {
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int N;
        cin >> N;
        vector<int> row(N);
        bool isSolution = true;
        for (int j = 0; j < N; ++j) {
            cin >> row[j];
            for (int k = 0; k < j; ++k) {
                if(row[j] == row[k] || abs(row[j]-row[k]) == abs(j-k)){
                    isSolution = false;
                    break;
                }
            }
        }
        if(isSolution)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
