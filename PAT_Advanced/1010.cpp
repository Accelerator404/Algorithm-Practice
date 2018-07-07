#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

//PAT Advanced 1010 Radix

//因为进制转换到10进制比较容易：第x位乘以原进制的x次幂（个位=0位）
//所以将目标转换到10进制进行比较，准备一个转换m进制到10进制的函数
long long int convert_to_Dec(string num,long long int radix){
    int index = 0,temp = 0;
    long long int result = 0;
    for (auto it = num.rbegin(); it != num.rend(); it++) {
        temp = isdigit(*it)?*it - '0':*it - 'a' + 10;  //三目运算符
        result += temp * pow(radix,index++);
    }
    return result;
}

long long find_Radix(long long int basicByDec, string target) {
    char it = *max_element(target.begin(), target.end());
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    long long high = max(basicByDec, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert_to_Dec(target, mid);
        //如果以测试进制mid转换的结果比给出进制的数大，说明target的进制小于mid，用二分法缩小范围
        if (t < 0 || t > basicByDec) high = mid - 1;
        else if (t == basicByDec) return mid;
        //反之取mid以上的范围
        else low = mid + 1;
    }
    return -1;
}

int main(){
    int tag,radix;
    string N1,N2;
    cin >> N1 >> N2 >> tag >> radix;
    if(N1 == N2){
        cout << radix;
        return 0;
    }
    string basic,target;
    if(tag == 1){
        target = N2;
        basic = N1;
    }
    else if(tag == 2){
        target = N1;
        basic = N2;
    }
    long long int basicByDec = convert_to_Dec(basic,radix);
    long long int resultRadix = find_Radix(basicByDec,target);
    if(resultRadix == -1)
        cout << "Impossible" << endl;
    else
        cout << resultRadix << endl;
    return 0;
}
