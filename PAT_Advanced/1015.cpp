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
    for (int i = 0; i < peak; ++i) {
        unsigned long int exp = peak - 1;
        res += (temp[i] - '0') * pow(radix,exp);
        exp--;
    }
    return res;
}

long int to_otherRadix(long int num,int radix){
    string temp;
    long int pRes = 1,pLef;
    while (pRes > 0){
        pLef = num % radix;
        pRes = num / radix;
        temp += to_string(pLef);
    }
    reverse(temp.begin(),temp.end());
    return strtol(temp.c_str(), nullptr,10);
}

bool isPrime(long int num){
    if(num == 2)
        return true;
    else if(num == 0 || num == 1)
        return false;
    if(num % 2 !=0){
        long int range = sqrt(num) + 2;
        for (int i = 3; i <= range ; ) {
            if(num % i == 0)
                return false;
            i += 2;
        }
        return true;
    }
    else{
        return false;
    }
}

int main() {
    long int N;
    while (cin >> N){
        int D;
        cin >> D;
        if(N < 0)
            break;
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
