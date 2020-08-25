#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//PAT Advanced 1039 Course List for Student

int main(){
    map<string,vector<int>> transcript;
    int N,K,count = 0;
    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        int t,Nt;
        scanf("%d%d",&t,&Nt);
        for (int j = 0; j < Nt; ++j) {
            char tmp[5];
            scanf("%s",tmp);
            transcript[tmp].push_back(t);
        }
    }
    for (int i = 0; i < N; ++i) {
        char student[5];
        scanf("%s",student);
        printf("%s ",student);
        if(transcript.find(student) == transcript.end()){
            printf("0\n");
            continue;
        }
        vector<int> & course = transcript[student];
        sort(course.begin(),course.end(),less<int>());
        printf("%lu",course.size());
        for (int j = 0; j < course.size(); ++j) {
            printf(" %d",course[j]);
        }
        printf("\n");
    }
    return 0;
}
