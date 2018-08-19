#include <iostream>
#include <vector>
using namespace std;

//PAT Advanced 1023 Have Fun with Numbers


int main(){
    vector<int> numberCount(10,0),numberCountD(10,0);
    long long int num,numD;
    string n1,n2;
    cin >> num;
    numD = 2* num;
    n1 = to_string(num);
    n2 = to_string(numD);
    if(n1.length()!=n2.length()){
        cout << "No" << endl;
        cout << numD << endl;
        return 0;
    }
    for (int i = 0; i < n1.length(); ++i) {
        numberCount[n1[i]-'0']++;
        numberCountD[n2[i]-'0']++;
    }
    for (int i = 0; i < 10; ++i) {
        if(numberCount[i] != numberCountD[i]){
            cout << "No" << endl;
            cout << numD << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << numD << endl;
    return 0;
}
