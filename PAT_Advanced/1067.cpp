#include <iostream>
using namespace std;

//PAT Advanced 1067 Sort with Swap(0,i)

int main(){
    int N,opt = 0,Array[100003];
    scanf("%d",&N);
    for (int i = 0; i < N; ++i) {
        scanf("%d",&Array[i]);
    }
    for (int i = 1; i < N; ++i) {
        if(Array[i] != i){
            while (Array[0] != 0){
                //将0处数字归位,直到0归位
                swap(Array[0],Array[Array[0]]);
                opt++;
            }
            if(Array[i] != i){
                //如果i还没有归位，放到0位置，在下一轮操作中会归位
                swap(Array[0],Array[i]);
                opt++;
            }
        }
    }
    cout << opt;
    return 0;
}
