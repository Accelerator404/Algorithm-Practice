#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//PAT Advanced Level 1107 Social Clusters

int main() {
    int N;
    cin >> N;
    vector<int> father(N+1);
    set<int> hobby[1002];
    father[0] = -1;
    for (int i = 1; i <= N; ++i) {
        father[i] = i;
        int k;
        scanf("%d",&k);
        getchar();
        for (int j = 0; j < k; ++j) {
            int h;
            scanf("%d",&h);
            hobby[h].insert(i);
        }
    }
    //归并
    for (int i = 1; i < 1001; ++i) {
        if(hobby[i].size() > 1){
            int fatherRoot = father[*hobby[i].begin()];
            for (auto it = hobby[i].begin(); it != hobby[i].end(); ++it) {
                father[*it] = fatherRoot;
            }
        }
    }
    //找出集合根节点
    set<int> roots;
    for (int i = 1; i <= N; ++i) {
        if(father[i] == i)
            roots.insert(i);
    }
    //整理归并集父节点
    for (int i = 1; i <= N; ++i) {
        while(roots.find(father[i]) == roots.end()){
            father[i] = father[father[i]];
        }
    }
    vector<int> SIZE;
    for (auto it = roots.begin(); it != roots.end(); ++it) {
        long int s = count(father.begin(),father.end(),*it);
        SIZE.push_back(s);
    }
    sort(SIZE.begin(),SIZE.end(),greater<int>());
    cout << roots.size() << endl;
    for (int i = 0; i < SIZE.size(); ++i) {
        if(i != 0)
            printf(" ");
        printf("%d",SIZE[i]);
    }
    return 0;
}
