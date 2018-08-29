#include <iostream>
#include <map>
#include <string>
using namespace std;

//PAT Advanced 1084 Broken Keyboard

int main(){
    string str1,str2;
    map<char,int> pList;
    cin >> str1 >> str2;
    for (int i = 0; i < str1.length(); ++i) {
        if(str1[i] >= 'a' && str1[i] <= 'z')
            str1[i] += 'A' - 'a';
        if(pList.find(str1[i]) == pList.end())
            pList[str1[i]] = 1;
        else
            pList[str1[i]]++;
    }
    for (int i = 0; i < str2.length(); ++i) {
        if(str2[i] >= 'a' && str2[i] <= 'z')
            str2[i] += 'A' - 'a';
        pList[str2[i]]--;
    }
    for (int i = 0; i < str1.length(); ++i) {
        if(pList[str1[i]] > 0){
            cout << str1[i];
            pList[str1[i]] = 0;
        }
    }
    return 0;
}
