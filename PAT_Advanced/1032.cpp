#include <iostream>
#include <map>
using namespace std;

//PAT Advanced 1032 Sharing

struct node{
    int next;
    char d;
    bool word1;
};

int main(){
    map<int,node> database;
    int pos1,pos2,N;
    scanf("%d%d%d",&pos1,&pos2,&N);
    for (int i = 0; i < N; ++i) {
        int myAddr,nextAddr;
        char data;
        scanf("%d %c %d",&myAddr,&data,&nextAddr);
        node s;s.next = nextAddr;s.d = data;s.word1 = false;
        database[myAddr] = s;
    }
    int p = pos1;
    while (p != -1){
        database[p].word1 = true;
        p = database[p].next;
    }
    p = pos2;
    while (p != -1){
        if(database[p].word1){
            printf("%05d",p);
            return 0;
        }
        p = database[p].next;
    }
    cout << -1;
    return 0;
}
