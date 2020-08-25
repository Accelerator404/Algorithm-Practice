#include <iostream>
#include <cstdio>
using namespace std;

//PAT Advanced 1002 A+B for Polynomials


int main(){
    int K1,K2,count=0;
    float coin[1001]={0};
    cin >> K1;
    for (int i = 0; i < K1; ++i) {
        int expo;
        float co;
        cin >> expo >> co;
        coin[expo] +=co;
    }
    cin >> K2;
    for (int i = 0; i < K2; ++i) {
        int expo;
        float co;
        cin >> expo >> co;
        coin[expo] +=co;
    }
    for (int k = 0; k < 1001; ++k) {
        if(coin[k] != 0.0)
            count++;
    }
    cout << count;
    for (int j = 1000; j >=0 ; --j) {
        if(coin[j] != 0.0){
            printf(" %d %.1f",j,coin[j]);
        }
    }
    return 0;
}
