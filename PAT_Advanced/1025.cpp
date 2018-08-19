#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//PAT Advanced 1025 PAT Ranking

struct unit{
    long long int ID;//用string也可，个人将string改为long long int后耗时减半
    int score,location,localRank,finalRank;
};

bool compare(unit a,unit b){
    if(a.score != b.score)
        return a.score > b.score;
    else
        return a.ID < b.ID; //学号排序
}

int main(){
    vector<unit> database,db;
    int N;
    cin >> N;
    unit dumb;dumb.score=9999;
    database.push_back(dumb);
    for (int i = 1; i <= N; ++i) {
        int K;
        cin >> K;
        db.clear();
        db.resize(K+1);
        db[0] = dumb;
        for (int j = 1; j <= K; ++j) {
            unit tmp;
            scanf("%lld%d",&tmp.ID,&tmp.score);
            tmp.location = i;
            db[j] = tmp;
        }
        sort(db.begin(),db.end(),compare);
        for (int j = 1; j <= K; ++j) {
            if(j==1)
                db[j].localRank=1;
            else if(db[j-1].score > db[j].score)
                db[j].localRank = j;
            else
                db[j].localRank = db[j-1].localRank;
            database.push_back(db[j]);
        }
    }
    sort(database.begin(),database.end(),compare);
    cout << database.size()-1 << endl;
    for (int j = 1; j < database.size(); ++j) {
        if(j==1)
            database[j].finalRank=1;
        else if(database[j-1].score > database[j].score)
            database[j].finalRank = j;
        else
            database[j].finalRank = database[j-1].finalRank;
        //注意13位ID输出格式，部分ID输入数据时前方带0，int格式存储ID则输出时前方补零至宽度=13。
        printf("%013lld %d %d %d\n",database[j].ID,database[j].finalRank,database[j].location,database[j].localRank);
    }
    return 0;
}
