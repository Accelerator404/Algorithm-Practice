#include <iostream>
using namespace std;

//PAT Advanced 1104 Sum of Number Segments

int main(){
    int N;
    double sumS = 0.0;
    double seq[100001];
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        double q;
        scanf("%lf",&q);
        seq[i] = q;
        double sum = seq[i] * i * (N - i + 1);
        sumS += sum;
    }
    printf("%.2f\n",sumS);
    return 0;
}
