#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//PAT Advanced 1046 Shortest Distance

int main(){
    int N,M,circultL = 0;
    vector<int> D;
    cin >> N;
    D.resize(N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d",&D[i]);
        circultL += D[i];
    }
    cin >> M;
    while (M-- > 0){
        int Ea,Eb,dist = 0;
        scanf("%d%d",&Ea,&Eb);
        if(Ea > Eb){
            int tmp;
            tmp = Eb;
            Eb = Ea;
            Ea = tmp;
        }
        for (int i = Ea; i < Eb; ++i) {
            dist += D[i];
        }
        if(dist > circultL - dist)
            printf("%d\n",circultL - dist);
        else
            printf("%d\n",dist);
    }
    return 0;
}
