#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

//PAT Advanced 1059 Prime Factors

bool isPrime(long int num){
    if(num <= 1)
        return false;
    if(num > 2 && num % 2 == 0)
        return false;
    long int range = sqrt(num + 1.0);
    for (int i = 3; i <= range; ++i) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main(){
    long int N,Left;
    map<long int,int> seq;
    cin >> N;
    Left = N;
    if(Left == 1)
        seq[1] = 1;
    while(Left > 1){
        if(isPrime(Left)){
            if(seq.find(Left) == seq.end())
                seq[Left] = 1;
            else
                seq[Left]++;
            break;
        }
        for (int i = 2; i < Left; ++i) {
            if(Left % i == 0 && isPrime(i)){
                Left = Left / i;
                if(seq.find(i) == seq.end())
                    seq[i] = 1;
                else
                    seq[i]++;
                break;
            }
        }
    }
    printf("%ld=",N);
    for (auto it = seq.begin(); it != seq.end(); ++it) {
        if(it != seq.begin())
            printf("*");
        if(it->second == 1)
            printf("%ld",it->first);
        else
            printf("%ld^%d",it->first,it->second);
    }
    printf("\n");
    return 0;
}
