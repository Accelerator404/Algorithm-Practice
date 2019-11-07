#include <iostream>
using namespace std;

/*
 * ZJU Data Structure Mooc 19 Fall
 * 02-线性结构2 一元多项式的乘法与加法运算
 * 设计函数分别求两个一元多项式的乘积与和。
 * 输入格式:
 * 输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数
 * （绝对值均为不超过1000的整数）。数字间以空格分隔。
 *
 * 输出格式:
 * 输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
 * 数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。
 */

// 注意，虽然输入的范围是-1000~+1000,但是若进行乘法运算，就可能会产生-2000~+2000的项，所以数组范围要大
long long int& getCoe(long long int power,long long int* dest){
    return dest[power+2020];
}

bool isZeroPolynomial(long long int* dest){
    for (int i = -2000; i <= 2000; ++i){
        if(getCoe(i,dest) != 0)
            return false;
    }
    return true;
}

void readPolynomial(long long int* dest){
    long long int l;
    cin >> l;
    while (l-->0){
        long long int coe,pow;
        cin >> coe >> pow;
        getCoe(pow,dest) = coe;
    }
}

void printPolynomial(long long int* poly){
    bool first = true;
    long long int count = 0;
    if(isZeroPolynomial(poly)){
        cout << "0 0" << endl;
        return;
    }
    for (int i = 2000; i >= -2000; --i) {
        long long int coe = getCoe(i,poly);
        if(coe != 0){
            if(!first)
                cout << ' ';
            else
                first = false;
            cout << coe << ' ' << i ;
            count++;
        }
    }
    cout << endl;
}

long long int* addPolynomial(long long int* a,long long int* b){
    long long int* result;
    result = new long long int[4040];
    fill(result,result+4040,0);
    for (int i = -2000; i <= 2000; ++i) {
        getCoe(i,result) = getCoe(i,a) + getCoe(i,b);
    }
    return result;
}

long long int* multiPolynomial(long long int* a,long long int* b){
    long long int* result;
    result = new long long int[4040];
    fill(result,result+4040,0);
    if(isZeroPolynomial(a) || isZeroPolynomial(b))
        return result;
    for (int i = -2000; i <= 2000; ++i) {
        if(getCoe(i,a) != 0){
            for (int j = -2000; j <= 2000; ++j) {
                if(getCoe(j,b) != 0){
                    getCoe(i+j,result) += getCoe(i,a) * getCoe(j,b);
                }
            }
        }
    }
    return result;
}

int main(){
    long long int a[4040],b[4040];
    fill(a,a+4040,0);
    fill(b,b+4040,0);
    readPolynomial(a);
    readPolynomial(b);
    printPolynomial(multiPolynomial(a,b));
    printPolynomial(addPolynomial(a,b));
    return 0;
}