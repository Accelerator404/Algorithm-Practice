#include <iostream>
#include <vector>
#include <string>
using namespace std;

//PAT Advanced 1035 Password

int main(){
    vector<pair<string,string>> modified;
    int N,m = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string name,passwd;
        cin >> name >> passwd;
        bool modify = false;
        for (int j = 0; j < passwd.length(); ++j) {
            if(passwd[j] == '1'){
                passwd[j] = '@';
                modify = true;
            }
            else if(passwd[j] == '0'){
                passwd[j] = '%';
                modify = true;
            }
            else if(passwd[j] == 'l'){
                passwd[j] = 'L';
                modify = true;
            }
            else if(passwd[j] == 'O'){
                passwd[j] = 'o';
                modify = true;
            }
        }
        if(modify){
            m++;
            pair<string,string> s(name,passwd);
            modified.push_back(s);
        }
    }
    if(m == 0 && N > 1)
        cout << "There are " << N << " accounts and no account is modified";
    else if(m == 0 && N == 1)
        cout << "There is " << N << " account and no account is modified";
    else{
        cout << m << endl;
        for (int i = 0; i < m; ++i) {
            cout << modified[i].first << ' ' << modified[i].second << endl;
        }
    }
    return 0;
}
