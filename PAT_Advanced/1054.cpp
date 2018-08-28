#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//PAT Advanced 1054 The Dominant Color

int main(){
    vector<unsigned long> colorList;
    int M,N;
    cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            unsigned long int K;
            scanf("%lu",&K);
            colorList.push_back(K);
        }
    }
    sort(colorList.begin(),colorList.end(),greater<unsigned long>());
    unsigned long ptr=0,freq=0,maxColor=0;
    freq = count(colorList.begin(),colorList.end(),maxColor);
    for (int i = 0; i < colorList.size(); ++i) {
        if(ptr != colorList[i]){
            ptr = colorList[i];
            int ptrFreq = count(colorList.begin()+i,colorList.end(),ptr);
            if(ptrFreq > freq){
                maxColor = ptr;
                freq = ptrFreq;
            }
        }
    }
    cout << maxColor;
    return 0;
}
