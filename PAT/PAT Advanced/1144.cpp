#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//PAT (Advanced Level) 1144 The Missing Number

int main(){
    int N,minPInt = 1 ;
    vector<int> list;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tgt;
        scanf("%d",&tgt);
        if(tgt > 0)
            list.push_back(tgt);
    }
    sort(list.begin(),list.end(),less<int>());
    for (int i = 0; i < list.size(); ++i) {
        if(list[i]==minPInt)
            minPInt++;
        if(minPInt < list[i])
            break;
    }
    cout << minPInt;
    return 0;
}
