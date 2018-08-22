#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

//PAT Advanced 1105 Spiral Matrix

int findN(int N){
    int i = sqrt((double)N);
    while(i >= 1) {
        if(N % i == 0)
            return i;
        i--;
    }
    return 1;
}

int main(){
    int N;
    cin >> N;
    vector<int> seq(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d",&seq[i]);
    }
    sort(seq.begin(),seq.end(),greater_equal<int>());
    int n = findN(N);
    int m = N/n;
    vector<vector<int>> matrix(m,vector<int>(n));
    //绕矩阵一圈为循环一次
    int level = m / 2 + m % 2,t = 0;
    for (int i = 0; i < level; ++i) {
        for (int j = i; j <= n-1-i && t < N; ++j) {
            matrix[i][j] = seq[t];
            t++;
        }
        for (int j = i + 1; j <= m - 1 - i ; ++j) {
            matrix[j][n - 1 - i] = seq[t];
            t++;
        }
        for (int j = n - 2 - i; j >= i; --j) {
            matrix[m - 1 -i][j] = seq[t];
            t++;
        }
        for (int j = m - 2 -i; j > i; --j) {
            matrix[j][i] = seq[t];
            t++;
        }
    }
    for (int i = 0; i < m; ++i) {
        bool first =true;
        for (int j = 0; j < n; ++j) {
            if(first){
                printf("%d",matrix[i][j]);
                first = false;
            }
            else
                printf(" %d",matrix[i][j]);

        }
        printf("\n");
    }
    return 0;
}
