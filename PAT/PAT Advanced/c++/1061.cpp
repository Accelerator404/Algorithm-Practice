#include <iostream>
#include <string>
using namespace std;

//PAT Advanced 1061 Dating

int main(){
    string str[4],week[8] = {"","MON","TUE","WED","THU","FRI","SAT","SUN"};
    int weekday = 0,HH,MM;
    bool switchy = false,hourConfirmed = false;
    cin >> str[0] >> str[1] >> str[2] >> str[3];
    for (int i = 0; i < str[0].length(); ++i) {
        if((str[0][i]>= 'A' && str[0][i] <= 'G') && str[0][i] == str[1][i] && !switchy){
            weekday = str[0][i] - 'A' + 1;
            switchy = true;
            i++;
        }
        if((isdigit(str[0][i]) || (isupper(str[0][i]) && str[0][i] <= 'N'))
                && str[0][i] == str[1][i] && switchy){
            if(str[0][i] >= '0' && str[0][i] <= '9')
                HH = str[0][i] - '0';
            else
                HH = str[0][i] - 'A' + 10;
            hourConfirmed = true;
        }
        if(hourConfirmed)
            break;
    }
    for (int i = 0; i < str[2].length(); ++i) {
        if(isalpha(str[2][i]) && str[2][i] == str[3][i]){
            MM = i;
            break;
        }
    }
    printf("%s %02d:%02d\n",week[weekday].c_str(),HH,MM);
    return 0;
}
