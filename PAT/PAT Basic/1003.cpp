#include <iostream>
#include <cstdio>

using namespace std;

#define _for(i, a, b) for(int i = (a); i < b;i++)

// PAT Basic 1003. 我要通过

long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

int main() {
    int n;
    n = readint();
    _for(i, 0, n) {
        string s;
        bool cont = true;
        int pos_P = -1, pos_T = -1;
        cin >> s;
        _for(j, 0, s.length()) {
            if (s[j] == 'P') {
                if (pos_P < 0) {
                    pos_P = j;
                } else {
                    cont = false;
                    break;
                }
            } else if (s[j] == 'T') {
                if (pos_T < 0) {
                    pos_T = j;
                } else {
                    cont = false;
                    break;
                }
            }
        }
        if (!cont) {
            cout << "NO" << endl;
            continue;
        }
        int pre_A = 0, mid_A = 0, post_A = 0;
        _for(j, 0, pos_P) {
            if (s[j] == 'A') {
                pre_A++;
            } else {
                cont = false;
                break;
            }
        }
        _for(j, pos_P + 1, pos_T) {
            if (s[j] == 'A') {
                mid_A++;
            } else {
                cont = false;
                break;
            }
        }
        if (pos_T < s.length() - 1)
            _for(j, pos_T + 1, s.length()) {
                if (s[j] == 'A') {
                    post_A++;
                } else {
                    cont = false;
                    break;
                }
            }
        if (!cont || (pre_A * mid_A != post_A) || mid_A < 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
