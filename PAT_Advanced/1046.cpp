#include <iostream>
#include <vector>
using namespace std;

//PAT Advanced 1046 Shortest Distance

int main(){
    int N,M,circuitL = 0;
    vector<int> D,distFromE1;
    cin >> N;
    D.resize(N+1),distFromE1.resize(N+1);
    distFromE1[1] = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d",&D[i]);
        if(i>1)
            distFromE1[i] = distFromE1[i-1] + D[i-1];
        circuitL += D[i];
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
        dist = distFromE1[Eb] - distFromE1[Ea];
        if(dist > circuitL - dist)
            printf("%d\n",circuitL - dist);
        else
            printf("%d\n",dist);
    }
    return 0;
}
