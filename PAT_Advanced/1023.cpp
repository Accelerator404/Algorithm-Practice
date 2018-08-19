#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

//PAT Advanced 1023 Have Fun with Numbers

//作为BigInt类的练习，参见紫皮书5.3（p124）

//BigInt Class Begin
struct BigInt{
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;
    BigInt(long long num = 0){*this = num;}
    BigInt operator = (long long num){
        s.clear();
        do{
            s.push_back(num % BASE);
            num /= BASE;
        }while (num > 0);
        return *this;
    }
    BigInt operator = (const string & str){
        s.clear();
        int x,len = (str.length() -1)/WIDTH+1;
        for (int i = 0; i < len; ++i) {
            int end = str.length() - i*WIDTH;
            int start = max(0,end-WIDTH);
            sscanf(str.substr(start,end - start).c_str(),"%d",&x);
            s.push_back(x);
        }
        return *this;
    }
    BigInt operator + (const BigInt& b) const{
        BigInt c;
        c.s.clear();
        for (int i = 0,g = 0; ; ++i) {
            if(g == 0 && i>=s.size() && i >= b.s.size())break;
            int  x = g;
            if(i < s.size()) x += s[i];
            if(i < b.s.size()) x += b.s[i];
            c.s.push_back(x % BASE);
            g = x/BASE;
        }
        return c;
    }
    BigInt operator +=(const BigInt& b){
        *this = *this +b;
        return *this;
    }
    bool operator < (const BigInt& b) const {
        if(s.size() != b.s.size())
            return s.size() < b.s.size();
        for (int i = s.size()-1; i >= 0; --i) {
            if(s[i] != b.s[i])
                return s[i] < b.s[i];
        }
        return false;
    }
    bool operator > (const BigInt& b) const{
        return b < *this;
    }
};

ostream& operator << (ostream &out, const BigInt& x){
    out << x.s.back();
    for (int i = x.s.size()-2; i >= 0 ; --i) {
        char buffer[20];
        sprintf(buffer,"%08d",x.s[i]);
        for (int j = 0; j < strlen(buffer); ++j)
            out << buffer[j];
    }
    return out;
}

istream& operator >> (istream& in,BigInt& x){
    string s;
    if(!(in >> s)) return in;
    x = s;
    return in;
}

//BigInt Class End

int main(){
    vector<int> book1(10,0),book2(10,0);
    BigInt s,s2;
    cin >> s;
    s2 = s + s;
    //大整数类内部分段存为int[],对每一个int进行辗转相除或者转为string求出每位数字
    for (int i = 0; i < s.s.size(); ++i) {
        int partial = s.s[i];
        while (partial>0){
            int k = partial %10;
            book1[k]++;
            partial /= 10;
        }
    }
    for (int i = 0; i < s2.s.size(); ++i) {
        int partial = s2.s[i];
        while (partial>0){
            int k = partial %10;
            book2[k]++;
            partial /= 10;
        }
    }
    for (int i = 0; i < 10; ++i) {
        if(book1[i] != book2[i]){
            cout << "No" << endl;
            cout << s2 << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << s2 << endl;
    return 0;
}
