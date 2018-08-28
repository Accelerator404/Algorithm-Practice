#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

//PAT Advanced 1015 Reversible Primes

long int to_decimal(long int num,int radix){
    string temp = to_string(num);
    unsigned long int peak = temp.length();
    long int res = 0;
    unsigned long int exp = peak - 1;
    for (int i = 0; i < peak; ++i) {
        res += (temp[i] - '0') * pow(radix,exp);
        exp--;
    }
    return res;
}

long int to_otherRadix(long int num,int radix){
    if(radix == 10)
        return num;
    string temp;
    long int pLef;
    while (num > 0){
        pLef = num % radix;
        num = num / radix;
        temp += to_string(pLef);
    }
    reverse(temp.begin(),temp.end());
    return strtol(temp.c_str(), nullptr,10);
}

bool isPrime(long int num){
    if(num <= 1)
        return false;
    if(num > 2 && num%2 == 0)
        return false;
    long int range = sqrt(num + 1.0);
    for (int i = 3; i <= range; ++i) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main() {
    long int N;
    while (cin >> N){
        if(N < 0)
            break;
        int D;
        cin >> D;
        if(!isPrime(N)) {
            cout << "No" << endl;
            continue;
        }
        string temp = to_string(to_otherRadix(N,D));
        reverse(temp.begin(),temp.end());
        long int revN = to_decimal(strtol(temp.c_str(), nullptr,10),D);
        if(isPrime(revN))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
