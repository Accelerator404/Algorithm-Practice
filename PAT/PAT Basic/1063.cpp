#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//PAT Advanced No.1063 “计算谱半径”

float radius(int a,int b){
    float sum = a*a+b*b;
    sum = sqrt(sum);
    return sum;
}

int main(){
    int N;
    float maxR = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int real ,imaginary;
        cin >> real >> imaginary;
        float R = radius(real,imaginary);
        if(maxR < R)
            maxR = R;
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << maxR << endl;
    return 0;
}
