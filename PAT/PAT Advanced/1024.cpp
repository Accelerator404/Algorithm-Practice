#include <iostream>
#include <algorithm>
using namespace std;

//PAT Advanced 1024 Palindromic Number

/*
 * 有两个测试点需要用到大整数相加
 */

string reverseBigInt(string N){
    reverse(N.begin(),N.end());
    return N;
}

bool check(string & str){
    if(str == reverseBigInt(str))
        return true;
    else
        return false;
}

string getReverseSum(string s1){
    string s2 = reverseBigInt(s1);
    //因为是两个相反数相加，从左往右计算进位是可行的
    int len = s1.length(), carry = 0;
    for(int i = 0; i < len; i++) {
        s1[i] = s1[i] + s2[i] + carry - '0';
        carry = 0;
        if(s1[i] > '9') {
            s1[i] = s1[i] - 10;
            carry = 1;
        }
    }
    if(carry) s1 += '1';
    reverse(s1.begin(), s1.end());
    return s1;
}

int main(){
    string N; int K,count = 0;
    cin >> N >> K;
    while (count<K){
        if(check(N)){
            printf("%s\n%d\n",N.c_str(),count);
            return 0;
        }
        N = getReverseSum(N);
        count++;
    }
    printf("%s\n%d\n",N.c_str(),count);
    return 0;
}
