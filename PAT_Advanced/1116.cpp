#include <iostream>
#include <cmath>
using namespace std;

//PAT Advanced 1116 Come on! Let's C

bool isPrime(int num){
    if(num <= 1)
        return false;
    else if (num == 2 || num == 3)
        return true;
    int range = sqrt((double)num);
    for (int i = 2; i <= range; ++i) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main(){
    bool isChecked[10001];
    int rankList[10001];
    fill(rankList,rankList+10001,-1);
    fill(isChecked,isChecked+10001,false);
    int N,K;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int j;
        scanf("%d",&j);
        rankList[j] = i;
    }
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int q;
        scanf("%d",&q);
        printf("%04d: ",q);
        if(rankList[q] == -1){
            printf("Are you kidding?\n");
            continue;
        }
        else if(isChecked[q])
            printf("Checked\n");
        else if(rankList[q] == 1)
            printf("Mystery Award\n");
        else if(isPrime(rankList[q]))
            printf("Minion\n");
        else
            printf("Chocolate\n");
        isChecked[q] = true;
    }
    return 0;
}
