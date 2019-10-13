#include <iostream>
#include <string>
using namespace std;

// PAT Advanced Level 1140 Look-and-say Sequence

/*
 * 这题的关键在于是第i+1个字符串是对第i个字符串的描述，亦即将i字符串中每p个连续D记为Dp
 */

int main() {
    string str;
    int n;
    cin >> str >> n;
    while (--n > 0){
        string t;
        for (int i = 0; i < str.length(); ++i) {
            int substrLen = 1;
            for (int j = i+1; j < str.length() && str[j] == str[i]; ++j) {
                substrLen++;
            }
            t += str[i] + to_string(substrLen);
            i += substrLen-1;
        }
        str = t;
    }
    cout << str;
    return 0;
}
