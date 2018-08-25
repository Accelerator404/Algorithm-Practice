#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//PAT Advanced 1109 Group Photo


/* 注意，该题未AC。
 */
struct student{
    string name;
    int height;
};

bool compare(student A,student B){
    if(A.height != B.height)
        return A.height < B.height;
    else
        return A.name < B.name;
}

bool compare2(student A,student B){
    if(A.height != B.height)
        return A.height > B.height;
    else
        return A.name < B.name;
}

int main(){
    int N,K,rowN,rear;
    cin >> N >> K;
    cin.sync_with_stdio(false);
    rowN = (int)floor(N/K);
    if(rowN * K < N || rowN * K > N)
        rear = N - rowN * (K - 1);
    else
        rear = rowN;
    vector<vector<student>> M(K,vector<student>(rowN + 2));
    vector<student> inbox(N);
    M[K-1].resize(rear + 2);
    for (int i = 0; i < N; ++i) {
        cin >> inbox[i].name >> inbox[i].height;
    }
    sort(inbox.begin(),inbox.end(),compare);
    for (int i = 0,p = 0; i < K ; ++i) {
        int rSize = (i == K-1)?rear:rowN;
        vector<student> thisRow(rSize);
        for (int j = 0; j < rSize; ++j,++p) {
            thisRow[j] = inbox[p];
        }
        sort(thisRow.begin(),thisRow.end(),compare2);
        int mid = (int)floor(rSize/2+1);
        M[i][mid] = thisRow[0];
        for (int k = 1;; ++k) {
            int pL = mid - k,pR = mid + k;
            if(pL <= 0)
                break;
            M[i][pL] = thisRow[2*k-1];
            if(pR >= rSize + 1)
                break;
            M[i][pR] = thisRow[2*k];
        }
    }
    for (int i = K-1; i >= 0; --i) {
        int rSize = (i == K-1)?rear:rowN;
        for (int j = 1; j <= rSize; ++j) {
            if(j == 1)
                printf("%s",M[i][j].name.c_str());
            else
                printf(" %s",M[i][j].name.c_str());
        }
        printf("\n");
    }
    return 0;
}
