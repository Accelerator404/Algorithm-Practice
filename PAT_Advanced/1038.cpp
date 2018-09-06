#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//PAT Advanced Level 1038 Recover the Smallest Number

bool compare(string a, string b){
    return a+b < b+a;
}

int main() {
    int N;
    cin >> N;
    vector<string> data(N);
    for(int i = 0;i < N; i++){
        cin >> data[i];
    }
    sort(data.begin(),data.end(),compare);
    string res;
    for(int i = 0;i < N;i++){
        res += data[i];
    }

    while(res[0] == '0' && res != "0"){
        res = res.substr(1,res.size()-1);
    }
    cout << res;
    return 0;
}
