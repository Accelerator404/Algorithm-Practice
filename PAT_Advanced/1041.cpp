#include <iostream>
#include <vector>
using namespace std;

//PAT Advanced 1041 Be Unique

int main(){
    vector<int> list(100001,0),seq;
    int N;
    cin >> N;
    seq.resize(N);
    for (int i = 0; i < N; ++i){
        int K;
        cin >> K;
        list[K]++;
        seq[i] = K;
    }
    for (int i = 0; i < N; ++i) {
        if(list[seq[i]] == 1){
            cout << seq[i];
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}
