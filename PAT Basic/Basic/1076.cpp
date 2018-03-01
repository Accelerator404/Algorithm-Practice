#include <iostream>
#include <string>
using namespace std;

//PAT Level.2 No.1076 “WiFi密码”

int getResult(){
    string str[4];
    char answer;
    for (int i = 0; i < 4; ++i) {
        cin >> str[i];
        if(str[i].at(2) == 'T')
            answer = str[i].at(0);
    }
    if(answer == 'A')
        return 1;
    else if(answer == 'B')
        return 2;
    else if(answer == 'C')
        return 3;
    else if(answer == 'D')
        return 4;
}

int main() {
    int count;
    cin >> count;
    while (--count >= 0)
        cout << getResult();
    cout << endl;
    return 0;
}
