#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//PAT Advanced 1055 The World's Richest

struct node{
    string name;
    int age,worth;
};

bool compare(node A,node B){
    if(A.worth != B.worth)
        return A.worth > B.worth;
    else if(A.age != B.age)
        return A.age < B.age;
    else
        return A.name < B.name;
}

int main(){
    int N,K;
    cin >> N >> K;
    vector<node> personList(N);
    //慎用该命令，使用后不能混用scanf和cin
    std::ios::sync_with_stdio(false);
    //如果使用char存储name，因为name是指针所以scanf后就不需要加&，即
    // char name[9]; scanf("%s%d",name,&age);
    for (int i = 0; i < N; ++i) {
        cin >> personList[i].name >> personList[i].age >> personList[i].worth;
    }
    sort(personList.begin(),personList.end(),compare);
    for (int i = 1; i <= K; ++i) {
        printf("Case #%d:\n",i);
        int M,Amin,Amax,count = 0,j = 0;
        vector<int> inQuery;
        cin >> M >> Amin >> Amax;
        while (count < M && j < N){
            const node & si = personList[j];
            if(si.age >= Amin && si.age <= Amax){
                count++;
                inQuery.push_back(j);
            }
            j++;
        }
        if(count == 0)
            printf("None\n");
        else
            for (int j = 0; j < count; ++j) {
                const node & si = personList[inQuery[j]];
                printf("%s %d %d\n",si.name.c_str(),si.age,si.worth);
            }
    }
    return 0;
}
