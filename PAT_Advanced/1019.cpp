#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced 1019 General Palindromic Number

int main(){
    long long int N,b;
    cin >> N >> b;
    long long int tempDigit = 0;
    vector<long long int> result,reverseResult;
    while (N > 0){
        tempDigit = N % b;
        result.push_back(tempDigit);
        N /= b;
    }
    reverseResult = result;
    reverse(result.begin(),result.end());
    bool isPalindromic = true;
    for (int i = 0; i < result.size(); ++i) {
        if(result[i] != reverseResult[result.size()-i]){
            cout << "No" << endl;
            isPalindromic = false;
            break;
        }
    }
    if(isPalindromic)
        cout << "Yes" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if(i != result.size()-1)
            cout << ' ';
    }
    return 0;
}
