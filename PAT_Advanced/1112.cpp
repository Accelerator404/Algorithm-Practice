#include <iostream>
#include <vector>
#include <map>
using namespace std;

//PAT Advanced Level 1112 Stucked Keyboard

int main() {
    map<char,bool> isStuck;
    map<int,char> detectSeq;
    int k,p = 1;
    string s,origin;
    cin >> k >> s;
    for (int i = 0; i < s.length(); ++i) {
        if(isStuck.find(s[i]) == isStuck.end()){
            isStuck[s[i]] = true;
            detectSeq[p] = s[i];
            p++;
        }
        if(s.substr(i,k) != string(k,s[i]))
            isStuck[s[i]] = false;
        else
            i += k-1;
    }
    //注意输出顺序为字符的发现顺序
    for (int i = 1; i < p; ++i) {
        if(isStuck[detectSeq[i]])
            cout << detectSeq[i];
    }
    cout << endl;
    for (int i = 0; i < s.length(); ++i) {
        origin += s[i];
        if(isStuck[s[i]])
            i += k-1;
    }
    cout << origin << endl;
    return 0;
}
