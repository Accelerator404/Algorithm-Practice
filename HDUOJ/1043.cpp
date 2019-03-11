#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/* 未完成，有未知bug
 * 思路为：读入一个矩阵，入队列，然后每从队列中取一个布局，就判断它是否调整完毕，否则将x格四向移动后入队，直到找到路线或空队；
 * 每一次移动不能超出边界，不能将x移回上一步的位置
 */

struct node{
    int maps[3][3];
    int xCol,xRow;
    node *upPtr,*downPtr,*leftPtr,*rightPtr;
    node *prevStep;
    string mySeries;
};

node* moveU(node* targetConf){
    if(targetConf->xRow == 0 || (targetConf->xCol == 2 && targetConf->xRow == 2)){
        targetConf->upPtr = nullptr;
        return nullptr;
    }
    if(targetConf->mySeries.at(targetConf->mySeries.length()-1)=='u')
        return nullptr;
    targetConf->upPtr = new node;
    node* S = targetConf->upPtr;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            S->maps[i][j] = targetConf->maps[i][j];
        }
    }
    S->xCol = targetConf->xCol;
    S->xRow = targetConf->xRow - 1;
    S->maps[targetConf->xRow][targetConf->xCol] = S->maps[S->xRow][S->xCol];
    S->maps[S->xRow][S->xCol] = 'x';
    S->prevStep = targetConf;
    S->mySeries = targetConf->mySeries + "u";
    return S;
}

node* moveD(node* targetConf){
    if(targetConf->xRow == 2 || (targetConf->xCol == 2 && targetConf->xRow == 2)){
        targetConf->downPtr = nullptr;
        return nullptr;
    }
    if(targetConf->mySeries.at(targetConf->mySeries.length()-1)=='d')
        return nullptr;
    targetConf->downPtr = new node;
    node* S = targetConf->downPtr;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            S->maps[i][j] = targetConf->maps[i][j];
        }
    }
    S->xCol = targetConf->xCol;
    S->xRow = targetConf->xRow + 1;
    S->maps[targetConf->xRow][targetConf->xCol] = S->maps[S->xRow][S->xCol];
    S->maps[S->xRow][S->xCol] = 'x';
    S->prevStep = targetConf;
    S->mySeries = targetConf->mySeries + "d";
    return S;
}

node* moveL(node* targetConf){
    if(targetConf->xCol == 0 || (targetConf->xCol == 2 && targetConf->xRow == 2)){
        targetConf->leftPtr = nullptr;
        return nullptr;
    }
    if(targetConf->mySeries.at(targetConf->mySeries.length()-1)=='l')
        return nullptr;
    targetConf->leftPtr = new node;
    node* S = targetConf->leftPtr;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            S->maps[i][j] = targetConf->maps[i][j];
        }
    }
    S->xCol = targetConf->xCol - 1;
    S->xRow = targetConf->xRow;
    S->maps[targetConf->xRow][targetConf->xCol] = S->maps[S->xRow][S->xCol];
    S->maps[S->xRow][S->xCol] = 'x';
    S->prevStep = targetConf;
    S->mySeries = targetConf->mySeries + "l";
    return S;
}

node* moveR(node* targetConf){
    if(targetConf->xCol == 2 || (targetConf->xCol == 2 && targetConf->xRow == 2)){
        targetConf->rightPtr = nullptr;
        return nullptr;
    }
    if(targetConf->mySeries.at(targetConf->mySeries.length()-1)=='r')
        return nullptr;
    targetConf->rightPtr = new node;
    node* S = targetConf->rightPtr;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            S->maps[i][j] = targetConf->maps[i][j];
        }
    }
    S->xCol = targetConf->xCol + 1;
    S->xRow = targetConf->xRow;
    S->maps[targetConf->xRow][targetConf->xCol] = S->maps[S->xRow][S->xCol];
    S->maps[S->xRow][S->xCol] = 'x';
    S->prevStep = targetConf;
    S->mySeries = targetConf->mySeries + "r";
    return S;
}

int main()
{
    while(true){
        node first;
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                cin >> first.maps[i][j];
                if(first.maps[i][j] == 'x'){
                    first.xRow = i;
                    first.xCol = j;
                }
            }
        }
        queue<node*> q;
        q.push(&first);
        bool solvable = false;
        while(!q.empty()){
            node *nodeAdd = q.front();
            q.pop();
            if(nodeAdd == nullptr)continue;
            //以下检查代码应考虑数字顺序
            if(nodeAdd->xCol == 2 && nodeAdd->xRow == 2){
                cout << nodeAdd->mySeries << endl;
                solvable = true;
                break;
            }
            if(moveU(nodeAdd))q.push(nodeAdd->upPtr);
            if(moveD(nodeAdd))q.push(nodeAdd->downPtr);
            if(moveL(nodeAdd))q.push(nodeAdd->leftPtr);
            if(moveR(nodeAdd))q.push(nodeAdd->rightPtr);
        }
        if(!solvable)
            cout << "unsolvable" << endl;
    }
    return 0;
}

