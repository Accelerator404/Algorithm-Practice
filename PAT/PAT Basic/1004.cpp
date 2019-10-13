#include <iostream>
#include <map>

using namespace std;

//PAT Advanced No.1004 “成绩排名”

int main(){
    map<int,string> mp1,mp2;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string name,ID;
        int score;
        cin >> name >> ID >> score;
        mp1.insert(make_pair(score,name));
        mp2.insert(make_pair(score,ID));
    }
    auto it1 = mp1.end(),it2 = mp2.end();
    cout<<(--it1)->second<<" "<<(--it2)->second<<endl;
    cout<<mp1.begin()->second<<" "<<mp2.begin()->second<<endl;
    return 0;
}
