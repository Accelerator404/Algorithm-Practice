#include <iostream>
#include <vector>
using namespace std;

//PAT Advanced 1005 Spell It Right


int main(){
    string N,res;
    cin >> N;
    int sum = 0;
    vector<string> words = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for (int i = 0; i < N.length(); ++i) {
        char k = N[i];
        int d = k - '0';
        sum += d;
    }
    res = to_string(sum);
    bool first = true;
    for (int j = 0; j < res.length(); ++j) {
        if(first){
            cout << words[res[j]-'0'];
            first = false;
        }
        else
            cout << ' ' << words[res[j]-'0'];
    }
    return 0;
}
