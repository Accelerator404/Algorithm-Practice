#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced Level 1056 Mice and Rice

int main() {
    int Np,Ng,Round = 1;
    cin >> Np >> Ng;
    vector<int> mice(Np),groups,ranks(Np);
    for(int i = 0;i < Np;i++){
        scanf("%d",&mice[i]);
    }
    groups.resize(Np);
    for(int i = 0;i < Np;i++){
        int a;
        scanf("%d",&a);
        groups[i] = a;
    }
    while(groups.size() > 0){
        if(groups.size()==1){
            ranks[groups[0]] = Round;
            groups.clear();
            break;
        }
        vector<int> nextRound;
        for(int i = 0; i< groups.size();i+=Ng){
            int range = min(i+Ng,(int)groups.size()),groupChampion = -1,maxMouse = -1;
            for(int j = i; j < range;j++){
                if(mice[groups[j]] >= maxMouse){
                    maxMouse = mice[groups[j]];
                    groupChampion = groups[j];
                }
                ranks[groups[j]] = Round;
            }
            if(groupChampion >= 0)
                nextRound.push_back(groupChampion);
        }
        groups.clear();
        groups = nextRound;
        Round++;
    }
    vector<int> rankTranslate(Round+1);
    int pCountOfRank = 0;
    for(int i = Round; i > 0;i--){
        if(i == Round)
            rankTranslate[i] = 1;
        else
            rankTranslate[i] = rankTranslate[i+1] + pCountOfRank;
        pCountOfRank = count(ranks.begin(),ranks.end(),i);
    }
    for(int i = 0;i < Np;i++){
        if(i > 0)
            printf(" ");
        printf("%d",rankTranslate[ranks[i]]);
    }
    return 0;
}
