#include <iostream>
using namespace std;

//PAT Advanced 1027 Colors in Mars

char radixConvert(int i){
    if(i < 10){
        return to_string(i)[0];
    }
    switch(i){
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
    }
}

int main(){
    int c[3];
    string color = "#";
    cin >> c[0] >> c[1] >> c[2];
    for (int i = 0; i < 3; ++i) {
        if(c[i] < 13){
            color += '0';
            color += radixConvert(c[i]);
        }
        else{
            color += radixConvert(c[i]/13);
            color += radixConvert(c[i]%13);
        }
    }
    cout << color;
    return 0;
}
