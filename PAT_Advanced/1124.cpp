#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced Level 1124 Raffle for Weibo Followers

int main() {
    int M,N,S;
    cin >> M >> N >> S;
    vector<string> follower(M+1),winner;
    for (int i = 1; i < M+1; ++i) {
        cin >> follower[i];
    }
    for (int i = 0; i * N + S <= M; ++i) {
        if(find(winner.begin(),winner.end(),follower[S+i*N]) == winner.end())
            winner.push_back(follower[S+i*N]);
        else{
            S++;
            --i;
        }
    }
    if(winner.empty())
        cout << "Keep going..." << endl;
    else
        for (int i = 0; i < winner.size(); ++i) {
            cout << winner[i] << endl;
        }
    return 0;
}
