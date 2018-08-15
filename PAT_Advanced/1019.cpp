#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced 1019 General Palindromic Number

/* 第一步，余数法
 * 第二步，反转余数列
 * 第三步，比较首尾
 */

int main(){
    int N,b;
    cin >> N >> b;
    if(N == 0){
        cout << "Yes" << endl << 0 << endl;
        return 0;
    }
    int tempDigit = 0;
    vector<int> result;
    while (N > 0){
        tempDigit = N % b;
        result.push_back(tempDigit);
        N /= b;
    }
    reverse(result.begin(),result.end());
    bool isPalindromic = true;
    for (int i = 0; i < result.size()/2 + 1; ++i) {
        if(result[i] != result[result.size()-1-i]){
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
