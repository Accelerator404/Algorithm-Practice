#include <iostream>
#include <iomanip>
using namespace std;

//PAT Advanced 1011 World Cup Betting

int main(){
    float odd[9],profit = 1.0,maxOdd[3] = {0.0};
    unsigned int p[3];
    char symbol[3] = {'W','T','L'};
    for (unsigned int i = 0; i < 9; ++i) {
        cin >> odd[i];
        if(i < 3 && odd[i] > maxOdd[0]){
            p[0] = i;
            maxOdd[0] = odd[i];
        } else if(i>=3 && i < 6 && odd[i] > maxOdd[1]){
            p[1] = i % 3;
            maxOdd[1] = odd[i];
        }
        else if(i >= 6 && i < 9 && odd[i] > maxOdd[2]){
            p[2] = i % 3;
            maxOdd[2] = odd[i];
        }
    }
    for (int j = 0; j < 3; ++j) {
        cout << symbol[p[j]] << ' ';
        profit *= maxOdd[j];
    }
    profit = (profit * 0.65) * 2 - 2;
    cout << setiosflags(ios::fixed) << setprecision(2) << profit;
    return 0;
}
