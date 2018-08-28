#include <iostream>
#include <string>
using namespace std;

//PAT Advanced 1050 String Subtraction

int main(){
    bool S2List[128] = {false};
    string strS1,strS2;
    getline(cin,strS1);
    getline(cin,strS2);
    for (auto i = strS2.begin(); i != strS2.end(); ++i) {
        if(!S2List[*i])
            S2List[*i] = true;
    }
    for (auto i = strS1.begin(); i != strS1.end();) {
        if(S2List[*i]){
            strS1.erase(i);
        } else
            i++;
    }
    cout << strS1;
    return 0;
}
