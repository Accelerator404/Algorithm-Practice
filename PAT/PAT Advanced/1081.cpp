#include <iostream>
#include <cmath>
using namespace std;

//PAT Advanced 1081 Rational Sum

/*
 * 1.采用递归方式求分子分母公约数，加法运算前后均进行约分；
 * 2.注意输出格式，当结果为0时只输出一个0。
 */

struct rationalNum {
    long long int num,deno;
};

long long int gcd(long long a, long long b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

int main(){
    int N;
    rationalNum res;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        rationalNum temp;
        char dumb;
        scanf("%lld%c%lld",&temp.num,&dumb,&temp.deno);
        long long int gcdval = gcd(temp.num,temp.deno);
        temp.num /= gcdval;
        temp.deno /= gcdval;
        if(i == 0){
            res = temp;
            continue;
        } else{
            long long int numerSum,denoProduct;
            denoProduct = res.deno * temp.deno;
            numerSum = res.deno * temp.num + temp.deno * res.num;
            gcdval = gcd(numerSum,denoProduct);
            res.num = numerSum / gcdval;
            res.deno = denoProduct / gcdval;
        }
    }
    bool first = false;
    if(abs(res.num) >= abs(res.deno)){
        cout << res.num/res.deno;
        res.num %= res.deno;
        first =true;
    }
    if(res.num != 0){
        if(first)
            cout << ' ';
        cout << res.num << '/' << res.deno;
    }
    else if(!first)
        cout << 0;
    return 0;
}
