#include <iostream>
using namespace std;

//PAT Advanced Level 1132 Cut Integer

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        long long int Z,a,b;
        cin >> Z;
        string Zt = to_string(Z);
        a = stoll(Zt.substr(0,Zt.length()/2), nullptr,10);
        b = stoll(Zt.substr(Zt.length()/2,Zt.length()/2), nullptr,10);
        long long int pro = a * b;
        if(pro > 0 && Z % pro == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
