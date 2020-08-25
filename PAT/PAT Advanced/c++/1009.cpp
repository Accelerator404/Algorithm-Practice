#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced 1009 Product of Polynomials
//可以用指数为底的数组存储多项式系数

int main(){
    unsigned int K1,K2,exp,count;
    double coe;
    vector<double> array(1001,0.0),Product(2001,0.0);
    cin >> K1;
    for (int i = 0; i < K1; ++i){
        cin >> exp >> coe;
        array[exp] += coe;
    }
    cin >> K2;
    for (int i = 0; i < K2; ++i){
        cin >> exp >> coe;
        for (int j = 0; j < 1001; ++j) {
            if(array[j] != 0.0)
                Product[exp + j] += coe * array[j];
        }
    }
    count = 0;
    for (int i = 0; i < 2001; ++i) {
        if(Product[i] != 0.0)
            count++;
    }
    cout << count;
    for (int i = 2000; i >= 0; --i) {
        if(Product[i] != 0.0)
            cout << ' ' << i << ' ' << setiosflags(ios::fixed) << setprecision(1) << Product[i];
    }
    cout << endl;
    return 0;
}
