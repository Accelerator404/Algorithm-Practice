#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

//PAT (Advanced Level) 1048 Find Coins

int M,N;
map<int,int> coins;

void input(){
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int coin;
        scanf("%d",&coin);
        if(coins.find(coin) == coins.end())
            coins[coin] = 1;
        else
            coins[coin]++;
    }
}

int checkCoinValue(int v1){
    int v2 = -1;
    if(v1 * 2 == M && coins[v1] > 1)
        return v1;
    if(coins.find(M - v1) != coins.end() && v1 * 2 != M )
        return M - v1;
    return v2;
}
int main(){
    input();
    for (auto it = coins.begin(); it != coins.end() ; ++it) {
        int v2 = checkCoinValue(it->first);
        if(v2 == -1)
            continue;
        else{
            cout << it->first << ' ' << v2;
            return 0;
        }
    }
    cout << "No Solution" << endl;
    return 0;
}
