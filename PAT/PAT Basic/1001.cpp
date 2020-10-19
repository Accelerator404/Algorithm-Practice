#include <iostream>

using namespace std;

//PAT Basic No.1001 “害死人不偿命的(3n+1)猜想”

int main(){
    int n,count = 0;
    cin >> n;
    while(n > 1){
        if(n % 2 == 0){
            n /= 2;
        } else{
            n = 3 * n + 1;
            n /= 2;
        }
        count++;
    }
    if(n == 1)
        cout << count << endl;

    return 0;
}