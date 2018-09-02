#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//PAT Advanced 1036 Boys vs Girls

int main(){
    int N,MMinGrade = 101,FMaxGrade = -1;
    string MMID,MMName,FMID,FMName;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string name,ID;
        char gender;
        int grade;
        cin >> name >> gender >> ID >> grade;
        if(gender == 'M' && grade < MMinGrade){
            MMID = ID;
            MMName = name;
            MMinGrade = grade;
        }
        else if(gender == 'F' && FMaxGrade < grade){
            FMID = ID;
            FMName = name;
            FMaxGrade = grade;
        }
    }
    if(FMaxGrade >= 0)
        cout << FMName << ' ' << FMID << endl;
    else
        cout << "Absent" << endl;
    if(MMinGrade <= 100)
        cout << MMName << ' ' << MMID << endl;
    else
        cout << "Absent" << endl;
    if(FMaxGrade >= 0 && MMinGrade <= 100)
        cout << FMaxGrade - MMinGrade << endl;
    else
        cout << "NA" << endl;
    return 0;
}
