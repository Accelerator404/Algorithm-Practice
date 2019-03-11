#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string input;
    while(cin >> input)
    {
        if(input == "end")break;
        bool flag_acc = true;
        if(input.find_first_of("aeiou") == string::npos){
            flag_acc = false;
        }
        if(input.length() >= 3 && flag_acc){
            for(int i = 0;i <= input.length()-3;i++){
                if(input.substr(i,3).find_first_not_of("aeiou") == string::npos
                   || input.substr(i,3).find_first_of("aeiou") == string::npos){
                    flag_acc = false;
                    break;
                }
            }
        }
        if(input.length() >= 2 && flag_acc){
            for(int i = 0;i < input.length()-1;i++){
                if(input[i] == input[i+1]
                   && input.substr(i,2) != "ee" && input.substr(i,2) != "oo"){
                    flag_acc = false;
                    break;
                }
            }
        }
        cout << "<"+input+"> is";
        if(!flag_acc)
            cout <<" not";
        cout << " acceptable." << endl;
    }
    return 0;
}
