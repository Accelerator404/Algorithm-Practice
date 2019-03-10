#include <iostream>
#include <cstdio>
using namespace std;
//问题主要在于等差求和的中间数可能溢出int32，偷懒直接上int64即可

int main()
{
    long long int n;
    while(cin >> n){
        long long int sum;
        if(n%2 == 0)
            sum = ((1+n)*n)/2;
        else
            sum = (1+(n-1))*(n-1)/2 + n;
        printf("%d\n\n",sum);
    }
    return 0;
}
