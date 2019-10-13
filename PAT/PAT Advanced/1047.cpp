#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//PAT Advanced 1047 Student List for Course

struct course{
    vector<string> student;
};

int main(){
    vector<course> database;
    int N,K;
    cin >> N >> K;
    database.resize(K+1);
    for (int i = 0; i < N; ++i) {
        char name[5];
        int C;
        scanf("%s %d",name,&C);
        for (int j = 0; j < C; ++j) {
            int u;
            scanf("%d",&u);
            database[u].student.push_back((string)name);
        }
    }
    for (int i = 1; i <= K; ++i) {
        printf("%d %lu\n",i,database[i].student.size());
        sort(database[i].student.begin(),database[i].student.end(),less<string>());
        for (int j = 0; j < database[i].student.size(); ++j) {
            printf("%s\n",database[i].student[j].c_str());
        }
    }
    return 0;
}
