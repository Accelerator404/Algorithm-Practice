#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//PAT Advanced 1100 Mars Numbers

/*
 * 值得注意的是两位火星数第一位为零时，火星数只写出第二位，如13写作tam而不是tam tret
 */

string digitM[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string digitM2[13] = {"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main(){
    int N;
    cin >> N;
    getchar();
    for (int i = 0; i < N; ++i) {
        string input,mars;
        int earth,b13d1 = 0,b13d2 = 0;
        getline(cin,input);
        if (input[0] >= '0' && input[0] <= '9'){
            earth = strtol(input.c_str(),nullptr,10);
            b13d1 = earth % 13;
            b13d2 = (int)(earth / 13.0);
            if(b13d2 > 0 && b13d1 > 0)
                mars = digitM2[b13d2] + ' ' + digitM[b13d1];
            else if(b13d2 > 0 && b13d1 == 0)
                mars = digitM2[b13d2];
            else
                mars = digitM[b13d1];
            cout << mars << endl;
        }
        else{
            for (int j = 1; j < 13; ++j) {
                if(input.find(digitM2[j]) != string::npos){
                    b13d2 = j;
                    break;
                }
            }
            for (int j = 0; j < 13; ++j) {
                if(input.find(digitM[j]) != string::npos){
                    b13d1 = j;
                    break;
                }
            }
            earth = b13d2*13+b13d1;
            cout << earth << endl;
        }
    }
    return 0;
}
