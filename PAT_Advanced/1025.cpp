#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//PAT Advanced 1025 PAT Ranking

struct unit{
    string ID;
    int score,location,localRank,finalRank;
};

bool compare(unit a,unit b){
    return a.score > b.score;
}

int main(){
    vector<unit> database,db;
    int N;
    cin >> N;
    unit dumb;dumb.ID="dumb";dumb.score=9999;
    database.push_back(dumb);
    for (int i = 1; i <= N; ++i) {
        int K;
        cin >> K;
        db.clear();
        db.resize(K+1);
        db[0] = dumb;
        for (int j = 1; j <= K; ++j) {
            unit tmp;
            cin >> tmp.ID >>tmp.score;
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
        printf("%s %d %d %d\n",database[j].ID.c_str(),database[j].finalRank,database[j].location,database[j].localRank);
    }

    return 0;
}
