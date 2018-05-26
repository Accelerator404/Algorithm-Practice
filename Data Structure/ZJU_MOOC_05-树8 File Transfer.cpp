#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;


/*
 *05-树8 File Transfer
 */

/*
 * 这道题很简单,但必须使用union操作与压缩路径来节约时间。
 */

int findroot(vector<int> S,int X){
    while(S[X] >= 0){
        X = S[X];
    }
    return X;
}

bool chkConnection(vector<int> S,int X1,int X2){
    int root1 = findroot(S,X1);
    int root2 = findroot(S,X2);
    if(root1 == root2)
        return true;
    else
        return false;
}

void networkSituation(vector<int> S,int N){
    int thisRoot;
    map<int,int> rootList;
    int count = 0;
    for (int i = 1; i < N+1; ++i) {
        thisRoot = findroot(S,i);
        if(rootList[thisRoot] > 0)
            rootList[thisRoot]++;
        else{
            rootList[thisRoot] = 1;
            count++;
        }
    }
    if(count == 1)
        cout << "The network is connected." << endl;
    else
        cout << "There are " << count <<" components." << endl;
}

int main(){
    int N;
    cin >> N;
    vector<int> Data;
    Data.resize(N+10);
    for (int i = 0; i < N+1; ++i) {
        Data[i] = -1;
    }
    while(true){
        char Input;
        int c1,c2;
        scanf("%c",&Input);
        if(Input == 'S'){
            networkSituation(Data,N);
            break;
        }
        scanf("%d%d",&c1,&c2);
        if(Input == 'C'){
            if(chkConnection(Data,c1,c2))
                printf("yes\n");
            else
                printf("no\n");
        }
        else if(Input == 'I'){
            int root1 = findroot(Data,c1);
            int root2 = findroot(Data,c2);
            if(root1 != root2){
                if(Data[root2] < Data[root1]){
                    Data[root1] = root2;
                }
                else{
                    if(Data[root1] == Data[root2])
                        Data[root1]--;
                    Data[root2] = root1;
                }

            }
        }
    }
    return 0;
}
