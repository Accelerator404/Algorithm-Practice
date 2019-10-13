#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//PAT Advanced 1037 Magic Coupon

/*
 * 优惠券可以不用，故对两序列排序，负优惠券×负商品，正优惠券×正商品，剩余正×负情况不计入
 */

int main(){
    int Nc,Np,maxCashBack = 0;
    vector<int> couponSeq,productSeq;
    scanf("%d",&Nc);
    couponSeq.resize(Nc);
    for (int i = 0; i < Nc; ++i) {
        scanf("%d",&couponSeq[i]);
    }
    scanf("%d",&Np);
    productSeq.resize(Np);
    for (int i = 0; i < Np; ++i) {
        scanf("%d",&productSeq[i]);
    }
    sort(couponSeq.begin(),couponSeq.end(),less<int>());
    sort(productSeq.begin(),productSeq.end(),less<int>());
    for (int i = 0; i < Nc && i < Np; ++i) {
        if(couponSeq[i] >= 0 || productSeq[i] >= 0)
            break;
        maxCashBack += couponSeq[i] * productSeq[i];
    }
    for (int i = 0; i < Nc && i < Np; ++i) {
        if(couponSeq[Nc-1-i] <=0 || productSeq[Np-1-i] <= 0)
            break;
        maxCashBack += couponSeq[Nc-1-i] * productSeq[Np-1-i];
    }
    printf("%d",maxCashBack);
    return 0;
}
