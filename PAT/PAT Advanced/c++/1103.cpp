#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//PAT Advanced 1103 Integer Factorization

/*
 * 有关DFS见算法笔记p273
 */
int N,K,P,upNi,maxFactorSum = -1;
vector<int> seq,tempSeq,subPower;

void init() {
    int temp = 0, index = 1;
    while (temp <= N) {
        subPower.push_back(temp);
        temp = pow(index,P);
        index++;
    }
}

void dfs(int index,int tempSum,int pos,int factorSum){
    if(pos == K){
        if(tempSum == N && factorSum > maxFactorSum){
            seq = tempSeq;
            maxFactorSum = factorSum;
        }
        return;
    }
    while (index >= 1){
        if(tempSum + subPower[index] <= N){
            tempSeq[pos] = index;
            dfs(index,tempSum + subPower[index],pos+1,factorSum + index);
        }
        if(index == 1) return;
        index--;
    }
}

int main(){
    cin >> N >> K >> P;
    init();
    upNi = subPower.size()-1;
    tempSeq.resize(K);
    dfs(upNi,0,0,0);
    if(maxFactorSum == -1){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << N << " = ";
    for (int i = 0; i < seq.size(); ++i) {
        if(i != 0)
            cout << " + ";
        cout << seq[i] << '^' << P;
    }
    return 0;
}
