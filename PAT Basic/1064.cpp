#include <iostream>
#include <vector>
using namespace std;

//PAT Advanced No.1064 “朋友数”

//注意：题设说明：我们默认一个整数自己是自己的朋友
int friendCode(int a){
    string ai=to_string(a);
    int codeA = 0;
    for (int i = 0; i < ai.length(); ++i) {
        codeA += ai[i] - '0';
    }
    return codeA;
}
int main(){
    int N;
    cin >> N;
    //我们知道最大数为9999，故最大各位数之和为9+9+9+9 = 36，开一个36的数组即可
    vector <int> friendCodeList(37,0),endList;
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        friendCodeList[friendCode(number)]++;
    }
    for (int i = 1; i < 37; ++i) {
        if(friendCodeList[i] > 0)
            endList.push_back(i);
    }
    cout << endList.size() << endl;
    bool first = true;
    for (int i = 0; i < endList.size(); ++i) {
        if(first)
            first = false;
        else
            cout <<' ';
        cout << endList[i];
    }
    cout << endl;
    return 0;
}
