#include <iostream>
using namespace std;

//PAT Advanced 1093 Count PAT's

int main(){
    long int res = 0;
    string input;
    int countP = 0,countT = 0;
    int arrayP[100001];
    cin >> input;
    for (int i = 0; i < input.length(); ++i) {
        if(input[i] == 'P'){
            countP++;
        } else if(input[i] == 'A'){
            arrayP[i] = countP;
        }
    }
    //反序计数T，遇到A则：该位置A可形成的PAT数目 = A前P数目 * A后T数目
    //也可以采用先统计一次总countP，然后遇到一次A就将countP--的操作，
    //这样不需要用数组存储每一个A前面的P数目
    for (int i = input.length()-1; i >= 0; --i) {
        if(input[i] == 'T')
            countT++;
        else if(input[i] == 'A')
            res += countT * arrayP[i];
    }
    cout << res % 1000000007;
    return 0;
}
