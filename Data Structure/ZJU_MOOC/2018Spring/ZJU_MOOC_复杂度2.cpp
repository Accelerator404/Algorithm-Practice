#include<iostream>
#include<vector>
using namespace std;

int main(){
    int K;
    bool zero = false;
    cin >> K;
    vector<int> a;
    for(int i = 0;i < K;i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        if(tmp == 0)
            zero = true;
    }
    int leftsum = 0,finalsum = 0;
    int *seq1 = nullptr,*seq2 = nullptr,*be = nullptr,*en = nullptr;
    for(int i = 0;i < K; i++){
        leftsum+=a[i];
        if(seq1 == nullptr){
            seq1 = &a[i];
            seq2 = &a[i];
        } else{
            seq2 = &a[i];
        }
        if(leftsum > finalsum){
            finalsum = leftsum;
            be = seq1;
            en = seq2;
        }
        else if(leftsum < 0){
            seq1 = nullptr;
            seq2 = nullptr;
            leftsum = 0;
        }
    }
    if(finalsum > 0)
    cout << finalsum <<' '<< *be <<' ' << *en;
    else if( finalsum == 0 && !zero)
        cout << finalsum <<' '<< a[0] <<' ' << a[K-1];
    else
        cout << finalsum <<' '<< 0 <<' ' << 0;
    return 0;
}
