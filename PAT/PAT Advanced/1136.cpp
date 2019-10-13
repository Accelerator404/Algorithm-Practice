#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced Level 1136 A Delayed Palindrome

bool isPalindromic(string & num){
    for (int i = 0; i <= (num.length()+1)/2; ++i) {
        if(num[i] != num[num.length() - i -1])
            return false;
    }
    return true;
}

string simplePlus(string a,string b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string res(max(a.length(),b.length())+1,'0');
    for (int i = 0; i < a.length(); ++i) {
        res[i] = res[i] + a[i] + b[i] - '0' - '0';
        if(res[i] > '9'){
            res[i+1] += (res[i] - '0') / 10;
            res[i] = '0' + ((res[i] - '0') % 10);
        }
    }
    if(res[a.length()] == '0')
        res.erase(a.length(),1);
    reverse(res.begin(),res.end());
    return res;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < 10; ++i) {
        if(isPalindromic(s))
            break;
        string A = s,B = s;
        reverse(B.begin(),B.end());
        s = simplePlus(A,B);
        cout << A << " + " << B << " = " << s << endl;
    }
    if(isPalindromic(s))
        cout << s <<" is a palindromic number." << endl;
    else
        cout << "Not found in 10 iterations." << endl;
    return 0;
}
