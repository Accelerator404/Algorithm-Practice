#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//PAT Advanced 1109 Group Photo


/*
 * 不知怎么的，就在改每一行输出范围的过程中取得AC了。
 */
struct student{
    string name;
    int height;
};

bool compare(student A,student B){
    if(A.height != B.height)
        return A.height > B.height;
    else
        return A.name < B.name;
}

int main(){
    int N,K,rowN,rear;
    cin >> N >> K;
    //cin.sync_with_stdio(false);
    rowN = (int)floor(N/K);
    rear = N - rowN * (K - 1);
    vector<student> inbox(N);
    for (int i = 0; i < N; ++i) {
        cin >> inbox[i].name >> inbox[i].height;
    }
    sort(inbox.begin(),inbox.end(),compare);
    for (int i = 0,p = 0; i < K ; ++i) {
        int rSize = (i == 0)?rear:rowN;
        vector<student> thisRow(rSize+1),sorted(rSize+1);
        for (int j = 1; j < rSize+1; ++j,++p) {
            thisRow[j] = inbox[p];
        }
        int mid = (int)floor(rSize/2+1);
        int ptr = 1;
        sorted[mid] = thisRow[ptr];
        for (int k = 1;ptr <= rSize; ++k) {
            ptr++;
            if(ptr > rSize)
                break;
            sorted[mid - k] = thisRow[ptr];
            ptr++;
            if(ptr > rSize)
                break;
            sorted[mid + k] = thisRow[ptr];
        }
        for (int j = 1; j < rSize+1; ++j) {
            if(j == 1)
                printf("%s",sorted[j].name.c_str());
            else
                printf(" %s",sorted[j].name.c_str());
        }
        printf("\n");
    }
    return 0;
}
