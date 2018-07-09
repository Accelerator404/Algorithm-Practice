#include <iostream>
#include <vector>
using namespace std;

//PAT Advanced 1007 Maximum Subsequence Sum

int main(){
    int K,sum,tempSum;
    unsigned int boundL,boundR,tempBoundL;
//    bool allOfTheseNumLowerThanZero = true;
    vector<int> Nseq;
    cin >> K;
    Nseq.resize(K);
    for (int i = 0; i < K; ++i) {
        cin >> Nseq[i];
//        if(Nseq[i] >= 0 && allOfTheseNumLowerThanZero)
//            allOfTheseNumLowerThanZero = false;
    }
    boundL = 0,sum = -1;
    tempSum = 0,tempBoundL = 0;
    for (int i = 0; i < K; ++i) {
        tempSum += Nseq[i];
        if(tempSum < 0){
            tempSum = 0;
            tempBoundL = i + 1;
        } else if(tempSum > sum){
            sum = tempSum;
            boundL = tempBoundL;
            boundR = i;
        }
    }
    if(sum < 0){
        sum = 0,boundL = 0,boundR=K-1;
    }
    cout << sum << ' ' << Nseq[boundL] << ' ' << Nseq[boundR] << endl;
    return 0;
}
