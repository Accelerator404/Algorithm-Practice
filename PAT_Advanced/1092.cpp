#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//PAT Advanced 1092 To Buy or Not to Buy

int main(){
    int color[128],lack = 0,extra = 0;
    string ideal,target;
    cin >> target >> ideal;
    fill(color,color+128,0);
    for (int i = 0; i < target.size(); ++i) {
        color[target[i]]++;
    }
    for (int i = 0; i < ideal.size(); ++i) {
        color[ideal[i]]--;
    }
    for (int i = 0; i < 128; ++i) {
        if(color[i] > 0)
            extra += color[i];
        else if(color[i] < 0)
            lack -= color[i];
    }
    if(lack > 0)
        printf("No %d\n",lack);
    else
        printf("Yes %d\n",extra);
    return 0;
}
