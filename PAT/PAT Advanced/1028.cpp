#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//PAT Advanced 1028 List Sorting

struct stu{
    int ID,grade;
    string name;
};

bool compare1(const stu & A,const stu & B){
    return A.ID < B.ID;
}

bool compare2(const stu & A,const stu & B){
    if(A.name != B.name)
        return A.name < B.name;
    else
        return A.ID < B.ID;
}

bool compare3(const stu & A,const stu & B){
    if(A.grade != B.grade)
        return A.grade < B.grade;
    else
        return A.ID < B.ID;
}

int main(){
    int N,C;
    scanf("%d%d",&N,&C);
    vector<stu> data(N);
    //std::ios::sync_with_stdio(false);
    for (int i = 0; i < N; ++i)
        cin >> data[i].ID >> data[i].name >> data[i].grade;
    //std::ios::sync_with_stdio(true);
    switch(C){
        case 1: sort(data.begin(),data.end(),compare1);break;
        case 2: sort(data.begin(),data.end(),compare2);break;
        case 3: sort(data.begin(),data.end(),compare3);break;
        default:;
    }
    for (int i = 0; i < N; ++i) {
        printf("%06d %s %d\n",data[i].ID,data[i].name.c_str(),data[i].grade);
    }
    return 0;
}
