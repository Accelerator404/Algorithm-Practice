#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//PAT Advanced 1106 Lowest Price in Supply Chain

/*
 * 价格只与深度相关，统计深度即可，深度越小越便宜，在同一深度则价格相同。
 */

struct node{
    //retailer:character == 0; distributor:character == 1; root supplier:character == -1;
    int character,depth;
    vector<int> subID;
};

int minDepth = 99999999;

void traversal(int ID,vector<node> & chainList){
    if(chainList[ID].character != 0){
        for (int i = 0; i < chainList[ID].subID.size(); ++i) {
            chainList[chainList[ID].subID[i]].depth = chainList[ID].depth + 1;
            traversal(chainList[ID].subID[i],chainList);
        }
    }
    else if(chainList[ID].depth < minDepth)
        minDepth = chainList[ID].depth;
}

int main(){
    int N;
    double P,r;
    vector<node> chainList;
    vector<int> retailerIDList;
    cin >> N >> P >> r;
    chainList.resize(N);
    for (int i = 0; i < N; ++i) {
        int Ki;
        cin >> Ki;
        if(Ki == 0){
            chainList[i].character = 0;
            retailerIDList.push_back(i);
        }
        else{
            chainList[i].subID.resize(Ki);
            for (int j = 0; j < Ki; ++j) {
                scanf("%d",&chainList[i].subID[j]);
            }
            chainList[i].character = (i == 0)?-1:1;
        }
    }
    chainList[0].depth = 0;
    traversal(0,chainList);
    int count = 0;
    for (int i = 0; i < retailerIDList.size(); ++i)
        if(chainList[retailerIDList[i]].depth == minDepth)
            count++;
    double minPrice = P * pow(1 + r/100.0,minDepth);
    printf("%.04f %d\n",minPrice,count);
    return 0;
}
