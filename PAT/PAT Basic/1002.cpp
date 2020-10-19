#include <iostream>

using namespace std;

//PAT Basic No.1002 “写出这个数”

string digit[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main(){
    int sum = 0;
    string input,sumS;
    cin >> input;
    for (int i = 0; i < input.length(); ++i) {
        sum += input.at(i) - 48;
    }
    sumS = to_string(sum);
    for (int j = 0; j < sumS.length(); ++j) {
        cout << digit[sumS.at(j) - 48];
        if(j < sumS.length() - 1)
            cout << ' ';
    }
    cout << endl;
    return 0;
}