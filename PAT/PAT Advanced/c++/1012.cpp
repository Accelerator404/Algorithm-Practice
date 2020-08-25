#include <iostream>
#include <algorithm>
using namespace std;

//PAT Advanced 1012 The Best Rank

struct Student {
    int id, best;
    int score[4], rank[4];
}studentData[2005];

int exist[1000000], flag = -1;

bool compare(Student a, Student b) {
    return a.score[flag] > b.score[flag];
}

int main() {
    int n, m, id;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &studentData[i].id, &studentData[i].score[1], &studentData[i].score[2], &studentData[i].score[3]);
        studentData[i].score[0] = (studentData[i].score[1] + studentData[i].score[2] + studentData[i].score[3]) / 3.0 + 0.5;
    }
    for(flag = 0; flag <= 3; flag++) {
        sort(studentData, studentData + n, compare);
        studentData[0].rank[flag] = 1;
        for(int i = 1; i < n; i++) {
            studentData[i].rank[flag] = i + 1;
            if(studentData[i].score[flag] == studentData[i-1].score[flag])
                studentData[i].rank[flag] = studentData[i-1].rank[flag];
        }
    }
    for(int i = 0; i < n; i++) {
        exist[studentData[i].id] = i + 1;
        studentData[i].best = 0;
        int minn = studentData[i].rank[0];
        for(int j = 1; j <= 3; j++) {
            if(studentData[i].rank[j] < minn) {
                minn = studentData[i].rank[j];
                studentData[i].best = j;
            }
        }
    }
    char c[5] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < m; i++) {
        scanf("%d", &id);
        int temp = exist[id];
        if(temp) {
            int best = studentData[temp-1].best;
            printf("%d %c\n", studentData[temp-1].rank[best], c[best]);
        } else {
            printf("N/A\n");
        }
    }
    return 0;
}
