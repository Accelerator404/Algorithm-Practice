#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//PAT Advanced 1120 Friend Numbers

bool ifs(int k){
    if(k>=1)
        return true;
    else
        return false;
}

int main(){
    int N,counts;
    vector<int> input,list(37,0);
    cin >> N;
    input.resize(N);
    for (int i = 0; i < N; ++i){
        cin >> input[i];
        string p = to_string(input[i]);
        int c = 0;
        for (int j = 0; j < p.length(); ++j)
            c += p[j] - '0';
        list[c]++;
    }
    counts = count_if(list.begin(),list.end(),ifs);
    cout << counts << endl;
    bool first = false;
    for (int i = 0; i < 37; ++i) {
        if(list[i] > 0) {
            if (!first) {
                first = true;
            } else
                cout << ' ';
            cout << i;
        }
    }
    return 0;
}
