#include <iostream>
#include <vector>
using namespace std;

// PAT Advanced Level 201809 7-1 &
// PAT Advanced Level 1148 Werewolf - Simple Version

int main() {
    int N;
    cin >> N;
    vector<int> input((unsigned)N+1);
    for(int i = 1; i <= N ; i++){
        cin >> input[i];
    }
    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            //假设i,j是狼人
            bool flag = true;
            vector<int> toCheck(N+1,0);
            toCheck[i] = toCheck[j] = 1;
            int count = 0,countW = 0;
            for (int k = 1; k <= N; ++k) {
                //统计总体说谎情况
                if((input[k] > 0 && toCheck[input[k]] == 1) ||
                    (input[k] < 0 && toCheck[abs(input[k])] == 0)){
                    count++;
                    //说谎者是狼人
                    if(k == i || k == j)
                        countW++;
                }
            }
            //有两人说谎，且正好有一名狼人说谎则满足条件
            if(count != 2 || countW != 1)
                continue;
            cout << i << ' ' << j;
            return 0;
        }
    }
    cout << "No Solution" << endl;
    return 0;
}
