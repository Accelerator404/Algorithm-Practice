#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced Level 1068 Find More Coins

int main() {
    int n, m;
    //数组开大一点避免爆栈
    vector<vector<int>> dp(10010,vector<int>(105));
    vector<int> coins(10010);
    bool choice[10010][105];
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &coins[i]);
    sort(coins.begin()+1, coins.begin()+1+n, greater<int>());
    for(int i = 1; i <= n; i++) {
        for(int j = coins[i]; j <= m; j++) {
            if(dp[i-1][j] <= dp[i-1][j-coins[i]] + coins[i]) {
                choice[i][j] = true;
                dp[i][j] = dp[i-1][j-coins[i]] + coins[i];
            } else{
                dp[i][j] = dp[i-1][j];
                choice[i][j] = false;
            }
        }
    }
    if(dp[n][m] != m) printf("No Solution");
    else {
        vector<int> arr;
        int v = m, index = n;
        while(v > 0) {
            if(choice[index][v]) {
                arr.push_back(coins[index]);
                v -= coins[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}
