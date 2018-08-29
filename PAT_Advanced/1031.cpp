#include <iostream>
#include <vector>
using namespace std;

//PAT Advanced 1031 Hello World for U

int main(){
    int n1,n2,n3;
    string str,blank;
    cin >> str;
    n1 = n3 = (str.length()+2)/3;
    n2 = str.length()+2 - n1 - n3;
    if(n2 > 2){
        string tmp(n2-2,' ');
        blank = tmp;
    }
    for (int i = 0; i < n1-1; ++i) {
        cout << str[i] << blank << str[str.length() - 1 - i] << endl;
    }
    cout << str.substr(n1-1,n2) << endl;
    return 0;
}
