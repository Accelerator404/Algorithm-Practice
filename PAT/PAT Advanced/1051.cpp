#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

//PAT Advanced 1051 Pop Sequence

int main(){
    int M,N,K;
    cin >> M >> N >> K;
    for (int p = 0; p < K; ++p) {
        vector<int> inputSeq(N+1);
        stack<int> emuS;
        for (int i = 1; i <= N; ++i)
            scanf("%d",&inputSeq[i]);
        int curr = 1;
        for (int i = 1; i <= N; ++i) {
            emuS.push(i);
            if(emuS.size() > M)
                break;
            //只要栈顶=弹出序列当前数，就一直弹出直到不满足条件，再进入下一个入栈循环
            while (!emuS.empty() && emuS.top() == inputSeq[curr]){
                emuS.pop();
                curr++;
            }
        }
        if(curr == N+1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
