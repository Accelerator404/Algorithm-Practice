#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//PAT Advanced 1078 Hashing

/*
 * Quadratic probing(positive increments)即为正向二次探查法解决冲突
 */

bool isPrime(int i){
    if(i <= 1)
        return false;
    else if ( i == 2 || i == 3)
        return true;
    else{
        int range = sqrt((double)i);
        for (int j = 2; j <= range; ++j) {
            if(i%j == 0)
                return false;
        }
    }
    return true;
}

int main(){
    int MSize,TSize,N;
    vector<int> hashTable;
    cin >> MSize >> N;
    do{
        MSize++;
    } while (!isPrime(MSize));
    TSize = MSize;
    hashTable.resize(TSize);
    bool first = false;
    for (int i = 0; i < N; ++i) {
        int key;
        scanf("%d",&key);
        if(!first)
            first = true;
        else
            printf(" ");
        int Hkey = key % TSize;
        if(hashTable[Hkey] == 0){
            hashTable[Hkey] = key;
            printf("%d",Hkey);
        }
        else{
            bool successInsert = false;
            for (int j = 1; j < TSize; ++j) {
                Hkey = (key + j*j) % TSize;
                if(hashTable[Hkey] == 0){
                    hashTable[Hkey] = key;
                    printf("%d",Hkey);
                    successInsert = true;
                    break;
                }
            }
            if(!successInsert)
                printf("-");
        }
    }
    return 0;
}
