#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced 1006 Sign In and Sign Out

struct log{
    string ID;
    int signInTime,signOutTime;
};

int getTimeSeconds(){
    int h,m,s,result;
    char np1,np2;
    scanf("%d%c%d%c%d",&h,&np1,&m,&np2,&s);
    result = 3600 * h + 60 * m + s;
    return result;
}

bool compareSignInTime(log log1,log log2){
    return log1.signInTime < log2.signInTime;
}

bool compareSignOutTime(log log1,log log2){
    return log1.signOutTime > log2.signOutTime;
}

int main(){
    unsigned int n;
    vector<log> signLog;
    cin >> n;
    signLog.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> signLog[i].ID;
        signLog[i].signInTime = getTimeSeconds();
        signLog[i].signOutTime = getTimeSeconds();
    }
    sort(signLog.begin(),signLog.end(),compareSignInTime);
    cout << signLog[0].ID << ' ';
    sort(signLog.begin(),signLog.end(),compareSignOutTime);
    cout << signLog[0].ID << endl;
    return 0;
}
