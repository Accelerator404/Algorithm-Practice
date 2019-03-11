#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

//to_string要求C++11

int main()
{
    int N;
    cin >> N;
    for(int i=1;i <= N;i++){
        char target;
        string input,output;
        int count = 0;
        cin >> input;
        for(int j = 0;j < input.length();j++){
            if(j == 0){
                target = input[j];
                count++;
            }
            else if(target != input[j]){
                if(count>1){
                    output.append(to_string(count));
                }
                output+=target;
                count = 0;
                target = input[j];
                count++;
            }
            else{
                count++;
            }
        }
        if(count>1){
            output.append(to_string(count));
        }
        output+=target;
        cout << output << endl;
    }
    return 0;
}
