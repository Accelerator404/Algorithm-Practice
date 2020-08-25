#include <iostream>
#include <string>
using namespace std;

//PAT Advanced 1040 Longest Symmetric String

int main(){
    int len = 0;
    string s;
    bool isSymmetric[1002][1002];
    getline(cin,s);
    const int div = s.length();
    //for (int i = 0; i < div; ++i)
    //    fill(isSymmetric[i],isSymmetric[i]+div,false);
    if(div) len = 1;
    for (int i = 0; i < div; ++i) {
        isSymmetric[i][i] = true;
        if(i+1 < div && s[i] == s[i+1]){
            isSymmetric[i][i+1] = true;
            len = 2;
        }
    }
    //依次遍历3、4、5……s.length()长度的子字串
    for (int i = 3; i <= div; ++i) {
        for (int j = 0; i + j -1 < div; ++j) {
            int last = i + j - 1;
            if(s[j] == s[last] && isSymmetric[j+1][last-1]){
                isSymmetric[j][last] = true;
                len = i;
            }
        }
    }
    cout << len;
    return 0;
}
