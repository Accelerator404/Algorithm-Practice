#include <iostream>
using namespace std;

//Tomorrow never knows？
//甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，
//如果告诉你a day in the life,真的会是tomorrow never knows?相信学了计概之后这个不会是难题，现在就来实现吧。
//读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。
//可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30。
//输入：输入仅一行，格式为yyyy-mm-dd的日期。
//输出：输出也仅一行，格式为yyyy-mm-dd的日期

bool leapYear(int a){
    if (a % 4 != 0)
        return false;
    else {
        if (a % 100 == 0 && a % 400 != 0)
            return false ;
        else
            return true;
    }
}

int output(int year,int month,int day){
    if (month < 10 && day >= 10){
        cout << year << "-0" << month << '-' << day << endl;
    }
    else if (month >= 10 && day < 10){
        cout << year << '-' << month << "-0" << day << endl;
    }
    else if (month < 10 && day < 10){
        cout << year << "-0" << month << "-0" << day << endl;
    }
    else
        cout << year << '-' << month << '-' << day << endl;
    return 0;
}

int main() {
    int year,month,day;
    char c;
    cin >> year >> c >> month >> c >> day; //用一个字符吃掉连接符
    
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ){
        if (day == 31){
            day = 1;
            month++;
        }
        else
            day++;
    }
    else if (month == 12){
        if (day == 31){
            day = 1;
            month = 1;
            year++;
        }
        else
            day++;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11){
        if (day == 30){
            day = 1;
            month++;
        }
        else
            day++;
    }
    else if (month == 2){
        if(leapYear(year)){
            if(day == 29){
                day = 1;
                month++;
            }
            else
                day++;
        }
        else{
            if(day == 28){
                day = 1;
                month++;
            }
            else
                day++;
        }
    }
    
    return output(year,month,day);
}
