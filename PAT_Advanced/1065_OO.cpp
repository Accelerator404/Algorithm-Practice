#include <iostream>
#include <vector>
#include <string>
using namespace std;

//PAT Advanced 1065 A+B and C

/*
 * 对大整数类进行了扩展，支持整数（包括负数）加减与输入输出，但显然对于一道20分的题目实在用力过猛
 */

class bigInt{
public:
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    bool notNegative = true;
    vector<int> s;
    bigInt(long long num = 0){*this = num;}
    bigInt operator = (long long num){
        s.clear();
        if(num < 0){
            notNegative = false;
            num = abs(num);
        }
        do{
            s.push_back(num%BASE);
            num /= BASE;
        }while(num > 0);
        return *this;
    }
    bigInt operator = (const string & str){
        s.clear();
        int x,len = (str.length()-1)/WIDTH+1;
        for (int i = 0; i < len; ++i) {
            int end = str.length() - i*WIDTH;
            int start = max(0,end - WIDTH);
            sscanf(str.substr(start,end-start).c_str(),"%d",&x);
            s.push_back(x);
        }
        if(str[0] == '-'){
            notNegative = false;
            s[s.size()-1] = abs(s[s.size()-1]);
        }
        return  *this;
    }
    bigInt operator-(const bigInt& b)   //重载减号,基于加法与非负减法的组合实现
    {
        bigInt c;
        bigInt p = *this,q = b;
        c.s.clear();
        if(*this>b && b.notNegative){
            int i,g;
            for(i=0,g=0;;i++){
                if(g==0&&i>=b.s.size()) break;
                int x=g;
                if(s[i]<b.s[i]){
                    s[i+1]-=1;
                    s[i]=s[i]+BASE;
                }
                if(i<s.size()) x+=s[i];
                if(i<b.s.size()) x-=b.s[i];
                c.s.push_back(x%BASE);
                g=x/BASE;
            }
            int x=0;
            for(;i<s.size();i++){
                x+=s[i];
                c.s.push_back(x%BASE);
                x=x/BASE;
            }
        } else if(*this == b){
            c = 0;
        }else{
            if(b.notNegative)
                q.notNegative = false;
            else
                q.notNegative = true;
            c = p + q;
        }
        return c;
    }
    bigInt operator+(const bigInt& b) const{
        bigInt c;
        c.s.clear();
        if(notNegative && b.notNegative){
            for (int i = 0,g = 0; ; ++i) {
                if(g == 0&& i>=s.size()&&i>=b.s.size())break;
                int x = g;
                if(i<s.size()) x+= s[i];
                if(i<b.s.size()) x+= b.s[i];
                c.s.push_back(x % BASE);
                g = x/BASE;
            }
            c.notNegative = true;
        }
        else if(!notNegative && !b.notNegative){
            bigInt p = *this,q = b;
            p.notNegative = true;q.notNegative = true;
            c = p + q;
            c.notNegative = false;
        } else if(notNegative){
            bigInt d = b;
            c = * this;
            d.notNegative = true;
            if(*this > d)
                c = c - d;
            else if (*this == d)
                c = 0;
            else {
                c = d - c;
                c.notNegative = false;
            }
        } else{
            c = b + *this;
        }
        return c;
    }
    bool operator < (const bigInt&b) const {
        if(notNegative != b.notNegative)
            return !notNegative;
        if(s.size() != b.s.size() && notNegative)
            return s.size() <b.s.size();
        else if(s.size() != b.s.size() && !notNegative)
            return s.size() > b.s.size();
        for (int i = s.size()-1; i >= 0; --i) {
            if(s[i] != b.s[i] && notNegative)
                return s[i] < b.s[i];
            else if (s[i] != b.s[i] && !notNegative)
                return s[i] > b.s[i];
        }
        return false;
    }
    bool operator > (const bigInt & b) const {
        return b < *this;
    }
    bool operator == (const bigInt & b) const {
        return (b.s == s && b.notNegative == notNegative);
    }
};

istream& operator >> (istream& in,bigInt& x){
    string s;
    if(!(in >> s)) return in;
    x = s;
    return in;
}

ostream& operator << (ostream &out, const bigInt& x) {
    if(!x.notNegative)
        out << '-';
    out << x.s.back();
    for(int i = x.s.size()-2; i >= 0; i--) {
        string buf;
        char b[20];
        sprintf(b, "%08d", x.s[i]);
        buf = b;
        for(int j = 0; j < buf.length(); j++) out << buf[j];
    }
    return out;
}

int main(){
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        bigInt A,B,C;
        cin >> A >> B >> C;
        cout << "Case #" << i;
        if(A+B>C)
            cout << ": true" << endl;
        else
            cout << ": false" << endl;
    }
    return 0;
}
