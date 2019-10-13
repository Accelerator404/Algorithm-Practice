#include <iostream>
#include <cmath>
using namespace std;

//PAT Basic No.1007

int primeList[30000] = {0},primeNum = 0;
bool prime(int a){
    if(a == 1 || a % 2 == 0)
        return false;
    else if(a == 2){
        return true;
    } else{
        int i = 0;
        while (sqrt(a) >= primeList[i] && primeNum >= i + 1){
            if(a % primeList[i] == 0)
                return false;
            i++;
        }
        return true;
    }
}

int main() {
    int n;
    int count = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        if(prime(i)){
            primeList[primeNum] = i;
            primeNum++;
        }
    for (int i = 1;i < primeNum;++i) 
        if(primeList[i] - primeList[i - 1] == 2)
            count++; 
    cout << count << endl;
    return 0;
}
