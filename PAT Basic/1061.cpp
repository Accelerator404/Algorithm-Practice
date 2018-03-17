#include <iostream>
#include <vector>
using namespace std;

//PAT Advanced No.1061 “判断题”

int main(){
    int N,M;
    vector<int> point,answerset,score;
    cin >> N >> M;
    point.resize(M);answerset.resize(M);score.resize(N);
    for(int i = 0;i<M;i++){
        cin >> point[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> answerset[i];
    }
    for (int i = 0; i < N; ++i) {
        score[i] = 0;
        for (int j = 0; j < M; ++j) {
            int tmp;
            cin >> tmp;
            if(answerset[j] == tmp){
                score[i] += point[j];
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << score[i] << endl;
    }
    return 0;
}
