#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//PAT Advanced 1073 Scientific Notation

int main(){
    bool positive;
    int power;
    string factor,str,res;
    cin >> str;
    if(str[0] == '-')
        positive = false;
    else
        positive = true;
    factor = str.substr(1,str.find_first_of('E')-1);
    power = stoi(str.substr(str.find_first_of('E')+1,string::npos));
    unsigned long accu = str.find_first_of('E') - str.find_first_of('.') - 1;
    if(!positive)
        cout << '-';
    if(power == 0)
        cout << factor;
    else if(power >= accu && power > 0)
        res = factor[0] + factor.substr(2,string::npos) + string(power - accu,'0');
    else if(power > 0 && power < accu){
        res = factor[0] + factor.substr(2,power) + '.' + factor.substr(power+2,string::npos);
    } else if(power == -1){
        res = "0.";
        res += factor[0] + factor.substr(2,string::npos);
    }
    else if(power < -1){
        res = "0." + string(abs(power)-1,'0');
        res += factor[0] + factor.substr(2,string::npos);
    }
    cout << res;
    return 0;
}
