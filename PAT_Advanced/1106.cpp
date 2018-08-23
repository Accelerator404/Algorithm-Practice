#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

//PAT Advanced 1106 Lowest Price in Supply Chain

struct node{
    //retailer:character == 0; distributor:character == 1; root supplier:character == -1;
    int character;
    double price;
    vector<int> subID;
};

double accuFormat(double input){
    double u;
    char str[16];
    sprintf(str,"%.04f",input);
    sscanf(str,"%lf",&u);
    return u;
}

void traversal(int ID,vector<node> & chainList,const double & r){
    if(chainList[ID].character != 0){
        for (int i = 0; i < chainList[ID].subID.size(); ++i) {
            chainList[chainList[ID].subID[i]].price = accuFormat(chainList[ID].price * (1.0 + r * 0.01));
            traversal(chainList[ID].subID[i],chainList,r);
        }
    } else
        return;
}

bool compare(node retailerA,node retailerB){
    return retailerA.price < retailerB.price;
}

int main(){
    int N;
    double P,r;
    vector<node> chainList,retailerList;
    vector<int> retailerIDList;
    cin >> N >> P >> r;
    chainList.resize(N);
    for (int i = 0; i < N; ++i) {
        int Ki;
        cin >> Ki;
        if(Ki == 0){
            chainList[i].character = 0;
            retailerIDList.push_back(i);
            continue;
        }
        else{
            chainList[i].subID.resize(Ki);
            for (int j = 0; j < Ki; ++j) {
                scanf("%d",&chainList[i].subID[j]);
            }
        }
        chainList[i].character = (i == 0)?-1:1;
    }
    chainList[0].price = P;
    traversal(0,chainList,r);
    for (int i = 0; i < retailerIDList.size(); ++i)
        retailerList.push_back(chainList[retailerIDList[i]]);
    sort(retailerList.begin(),retailerList.end(),compare);
    double minPrice = retailerList[0].price;
    int count = 0;
    for (int i = 0; i < retailerList.size(); ++i) {
        if(retailerList[i].price <= minPrice + 0.00009){
            count++;
        } else break;
    }
    printf("%.04f %d\n",minPrice,count);
    return 0;
}
