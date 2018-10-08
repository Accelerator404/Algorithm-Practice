#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

//PAT (Advanced Level) 1088 Rational Arithmetic

struct fraction{
    long long int numer,deno;
};

long long int gcd(long long int a,long long int b){
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

string formatFraction(fraction n){
    long long int & numer = n.numer;
    long long int & deno = n.deno;
    bool isPositive = false;
    if(deno == 0)
        return "Inf";
    if(numer == 0)
        return "0";
    if(numer * deno > 0)
        isPositive = true;
    numer = abs(numer);
    deno = abs(deno);
    if(numer == deno){
        return isPositive?"1":"-1";
    }
    long long int g = gcd(numer,deno),x,y;
    numer /= g;
    deno /= g;
    x = numer % deno;
    y = numer / deno;
    string result;
    if(y > 0)
        result += to_string(y);
    if(y > 0 && x != 0)
        result += " ";
    if(x != 0)
        result += to_string(x) + "/" + to_string(deno);
    if(!isPositive)
        result = "(-" + result + ")";
    return result;
}

void getNumDeno(string fraction,struct fraction & num){
    if(fraction.length() < 3)
        return;
    sscanf(fraction.c_str(),"%lld/%lld",&num.numer,&num.deno);
}

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    fraction num1,num2,sum,diff,product,quo;
    getNumDeno(s1,num1);
    getNumDeno(s2,num2);
    sum.deno = num1.deno * num2.deno;
    sum.numer = num1.numer * num2.deno + num1.deno * num2.numer;
    diff.deno = sum.deno;
    diff.numer = num1.numer * num2.deno - num1.deno * num2.numer;
    product.deno = sum.deno;
    product.numer = num1.numer*num2.numer;
    quo.deno = num1.deno * num2.numer;
    quo.numer = num1.numer * num2.deno;
    s1 = formatFraction(num1);
    s2 = formatFraction(num2);
    cout << s1 << " + " << s2 << " = " << formatFraction(sum) << endl;
    cout << s1 << " - " << s2 << " = " << formatFraction(diff) << endl;
    cout << s1 << " * " << s2 << " = " << formatFraction(product) << endl;
    cout << s1 << " / " << s2 << " = " << formatFraction(quo) << endl;
    return 0;
}
