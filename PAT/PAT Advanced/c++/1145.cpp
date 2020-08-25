#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//PAT Advanced Level 1145 Hashing - Average Search Time

bool isPrime(int num){
    if(num <= 1)
        return false;
    else if(num == 2 || num == 3)
        return true;
    int range = sqrt((double)num);
    for (int i = 2; i <= range; ++i) {
        if(num%i == 0)
            return false;
    }
    return true;
}

int main() {
    int MSize,N,M,TSize;
    vector<int> hashTable;
    cin >> MSize >> N >> M;
    TSize = MSize;
    while(!isPrime(TSize))
        TSize++;
    hashTable.resize(TSize);
    for (int i = 0; i < N; ++i) {
        int input;
        scanf("%d",&input);
        int j = 0;
        bool inserted = false;
        while(j < TSize){
            int Hkey = (input + j*j) % TSize;
            if(hashTable[Hkey] != 0)
                j++;
            else{
                hashTable[Hkey] = input;
                inserted = true;
                break;
            }
        }
        if(!inserted)
            printf("%d cannot be inserted.\n",input);
    }
    int searchTime = 0;
    for (int i = 0; i < M; ++i) {
        int key;
        scanf("%d",&key);
        //比较操作的次数
        int cmpTime = 0;
        while(cmpTime <= TSize){
            int Hkey = (key + cmpTime*cmpTime) % TSize;
            cmpTime++;
            //如果在某一位没有检测到数，即为该位未冲突
            // 未冲突却未插入key，说明散列里没有这个key，退出查找
            if(hashTable[Hkey] == key || hashTable[Hkey] == 0)
                break;
        }
        searchTime += cmpTime;
    }
    printf("%.01f\n",((double)searchTime / M));

    return 0;
}
