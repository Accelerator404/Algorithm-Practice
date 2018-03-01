#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

//PAT Level.2 No.1080 “MOOC期终成绩”

class student{
public:
    string ID;
    int codeG,midG,finalG,G;
    student(string nm = "",int p = -1,int m = -1,int f= -1,int a = 0):ID(nm),codeG(p),midG(m),finalG(f),G(a){};
};

map<string,student> mp;
vector<student> v;

int calTotalG(student & pupil){
    double tmpG;
    if(pupil.midG > pupil.finalG)
        tmpG = (0.4 * pupil.midG + 0.6 * pupil.finalG);
    else
        tmpG = pupil.finalG;
    return round(tmpG);
}

bool compare(const student &a,const student &b){
    return a.G==b.G?a.ID<b.ID:a.G>b.G;
}
int main() {
    int P,M,N;
    cin >> P >> M >> N;
    string str;
    int grade;
    for (int i = 0; i < P; ++i) {
        cin >> str >> grade;
        mp[str] = student(str,grade,-1,-1,0);
    }
    for (int j = 0; j < M; ++j) {
        cin >> str >> grade;
        if(mp.count(str))
            mp[str].midG = grade;
        else
            mp[str] = student(str,-1,grade,-1,0);
    }
    //上述两次都没加入名单的学生显然没有前两次的成绩
    for (int j = 0; j < N; ++j) {
        cin >> str >> grade;
        if(mp.count(str))
            mp[str].finalG = grade;
        else
            mp[str] = student(str,-1,-1,grade,0);
    }
    for (auto &all:mp){
        auto &pupil = all.second;
        if(pupil.codeG < 200)
            continue;
        pupil.G = calTotalG(pupil);
        //成绩达标者加入队列
        if(pupil.G >= 60)
            v.push_back(pupil);
    }
    sort(v.begin(),v.end(),compare);

    for (auto &success:v) {
            cout << success.ID << ' ' << success.codeG << ' ' << success.midG << ' ' << success.finalG << ' '
                 << success.G << endl;
    }
    return 0;
}
