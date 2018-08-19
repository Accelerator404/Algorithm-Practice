#include <iostream>
#include <algorithm>
using namespace std;

//PAT Advanced 1024 Palindromic Number

bool check(long long int num){
    string str = to_string(num);
    for (int i = 0; i < (str.length()+1)/2; ++i) {
        if(str[i] != str[str.length()-1-i]){
            return false;
        }
    }
    return true;
}

long long int reverseInt(long long int N){
    string u = to_string(N);
    reverse(u.begin(),u.end());
    long long int rev = strtol(u.c_str(), nullptr,10);
    return rev;
}

int main(){
    long long int N,K,count = 0;
    cin >> N >> K;
    while (count<K){
        if(check(N)){
            printf("%lld\n%lld\n",N,count);
            return 0;
        }
        N += reverseInt(N);
        count++;
    }
    printf("%lld\n%lld\n",N,count);
    return 0;
}
