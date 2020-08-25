#include <iostream>
#include <string>
using namespace std;

//PAT Advanced 1001 A+B Format


int main(){
    int a,b,sum;
    string sep,fin;
    bool nega = false;
    cin>>a>>b;
    sum = a+b;
    if(sum<0){
        nega =true;
        sum = -sum;
    }
    sep = to_string(sum);
    while(sep.length()>3){
        fin = ',' + sep.substr(sep.length()-3,sep.length()) + fin;
        sep = sep.substr(0,sep.length()-3);
    }
    fin = sep+fin;
    if(nega)
        fin = '-' + fin;
    cout << fin << endl;
    return 0;
}
