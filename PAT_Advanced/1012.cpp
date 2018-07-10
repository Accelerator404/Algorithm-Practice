#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//PAT Advanced 1012 The Best Rank

struct Student{
    string ID;
    int C,M,E,A;
};

bool compareC(Student A,Student B){
    return A.C > B.C;
}

bool compareM(Student A,Student B){
    return A.M > B.M;
}

bool compareE(Student A,Student B){
    return A.E > B.E;
}

bool compareA(Student A,Student B){
    return A.A > B.A;
}

int main(){
    unsigned int N,M;
    vector<Student> studentData;
    map<string,int> rankC,rankM,rankE,rankA;
    cin >> N >> M;
    studentData.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> studentData[i].ID >> studentData[i].C >> studentData[i].M >> studentData[i].E;
        studentData[i].A = (studentData[i].C + studentData[i].M + studentData[i].E + 0.5)/3;
    }
    sort(studentData.begin(),studentData.end(),compareC);
    for (int j = 0; j < N; ++j){
        rankC[studentData[j].ID] = j+1;
        if(j > 0 && studentData[j].C == studentData[j-1].C)
            rankC[studentData[j].ID] = rankC[studentData[j-1].ID];
    }
    sort(studentData.begin(),studentData.end(),compareM);
    for (int j = 0; j < N; ++j){
        rankM[studentData[j].ID] = j+1;
        if(j > 0 && studentData[j].C == studentData[j-1].C)
            rankM[studentData[j].ID] = rankM[studentData[j-1].ID];
    }
    sort(studentData.begin(),studentData.end(),compareE);
    for (int j = 0; j < N; ++j){
        rankE[studentData[j].ID] = j+1;
        if(j > 0 && studentData[j].C == studentData[j-1].C)
            rankE[studentData[j].ID] = rankE[studentData[j-1].ID];
    }
    sort(studentData.begin(),studentData.end(),compareA);
    for (int j = 0; j < N; ++j){
        rankA[studentData[j].ID] = j+1;
        if(j > 0 && studentData[j].C == studentData[j-1].C)
            rankA[studentData[j].ID] = rankA[studentData[j-1].ID];
    }
    for (int k = 0; k < M; ++k) {
        string studentToCheck;
        cin >> studentToCheck;
        if(rankA.find(studentToCheck) == rankA.end()){
            cout << "N/A" << endl;
            continue;
        }
        else{
            int rC,rM,rE,rA;
            rC = rankC[studentToCheck],rM = rankM[studentToCheck];
            rE = rankE[studentToCheck],rA = rankA[studentToCheck];
            if(rA <= rC && rA <= rM && rA <= rE){
                cout << rA << " A" << endl;
            } else if (rC < rA && rC <= rE && rC <= rM) {
                cout << rC << " C" << endl;
            } else if (rM < rA && rM < rC && rM <= rE){
                cout << rM << " M" << endl;
            } else if (rE < rA && rE < rC && rE < rM){
                cout << rE << " E" << endl;
            }
        }
    }
    return 0;
}
