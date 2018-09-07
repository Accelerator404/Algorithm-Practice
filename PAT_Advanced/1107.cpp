#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//PAT Advanced Level 1107 Social Clusters

bool isPositive(int a){
    return a>0;
}

int findFather(int x,vector<int> & father){
    int a = x;
    //找到根节点
    while(x != father[x])
        x = father[x];
    //将多层树中这一条枝干节点归并到根节点上
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

int main() {
    int N;
    cin >> N;
    vector<int> father(N+1);
    vector<int> root(N+1,0);
    //储存每门课的根结点
    int course[1001] = {0};
    father[0] = -1;
    for (int i = 1; i <= N; ++i) {
        father[i] = i;}
    for (int i = 1; i <= N; ++i) {
        int k;
        scanf("%d:",&k);
        for (int j = 0; j < k; ++j) {
            int h;
            scanf("%d",&h);
            if(course[h] == 0)
                course[h] = i;
            //归并，归并过程中课程根节点与该阶段的父子关系都被整理压缩
            int iFather = findFather(i,father);
            int courseRootFather = findFather(course[h],father);
            if(iFather != courseRootFather)
                father[iFather] = courseRootFather;
        }
    }
    //记录每一组cluster的人数
    for (int i = 1; i <= N; ++i) {
        root[findFather(i,father)]++;
    }
    sort(root.begin(),root.end(),greater<int>());
    //不用count_if也可以for循环统计一次非零数
    cout << count_if(root.begin(),root.end(),isPositive) << endl;
    for (int i = 0; i < root.size() && root[i] > 0; ++i) {
        if(i != 0)
            printf(" ");
        printf("%d",root[i]);
    }
    return 0;
}
