#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//PAT Advanced Level 1038 Recover the Smallest Number

//在sort的过程后，排在最前面的肯定是最小的数，如果按照ab<ba排序，最前面就是两两组合最小的结果
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
