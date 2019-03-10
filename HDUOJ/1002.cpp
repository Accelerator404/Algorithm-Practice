#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i=1;i <= T;i++){
        string num1,num2;
        int ptr,l1,l2;
        cin >> num1 >> num2;
        if(i > 1)printf("\n");
        cout << "Case " << i << ':' << endl;
        cout << num1 << " + " << num2 << " = ";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        while(num1.at(num1.length()-1) == '0'){
            num1.erase(num1.length()-1);
        }
        while(num2.at(num2.length()-1) == '0'){
            num2.erase(num2.length()-1);
        }
        l1 = num1.length();
        l2 = num2.length();
        string dull(abs(l1-l2),'0');
        string resultS(max(l1,l2)+1,'0');
        if(l1 > l2){
            num2 += dull;
        }
        else if(l2 > l1){
            num1 += dull;
        }
        for(ptr = 0;ptr < max(l1,l2);ptr++){
            unsigned int p = num1[ptr] + num2[ptr] + resultS[ptr] - 3*'0';
            resultS[ptr+1] = p/10 + '0';
            resultS[ptr] = p%10 + '0';
        }
        while(resultS.at(resultS.length()-1) == '0'){
            resultS.erase(resultS.length()-1);
        }
        reverse(resultS.begin(),resultS.end());
        cout << resultS << endl;
    }
    return 0;
}
