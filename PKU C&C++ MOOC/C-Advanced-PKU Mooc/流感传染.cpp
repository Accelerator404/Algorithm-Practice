#include <iostream>
using namespace std;

//流感传染
//有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，
//房间里可能住人，也可能空着。
//在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变）,
//空房间不会传染。请输出第m天得流感的人数。
//输入：第一行一个数字n，n不超过100，表示有n*n的宿舍房间。
//接下来的n行，每行n个字符，
// ’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。
//接下来的一行是一个整数m，m不超过100.
//输出：输出第m天，得流感的人数

void infect(int n,char room[100][100]){
    int x,y,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
    char room2[102][102] = {'\0'};
    for (int i = 0;i < n;i++){
        for (int j = 0; j < n; j++){
            if(room[i][j] == '!')
                room[i][j] = '@'; //将昨日感染人群重标记
        }
    }
    //在被虐了2小时后，我确认coursera判断这题的时候吃数组边界判断，所以所有元素临时向右下方移动一位
    for (int i = 0;i < n;i++){   
        for (int j = 0; j < n; j++){
                room2[i+1][j+1] = room[i][j];
        }
    }
    for (int i = 1;i < n+1;i++){
        for (int j = 1; j < n+1; j++){
            if (room2[i][j] == '.' ){
                for(int k = 0; k<4;k++){
                    x = i + dx[k],y = j + dy[k];
                    if(room2[x][y] == '@')
                        room2[i][j] = '!'; //将本日新感染人群标记为'!'
                }
            }
        }
    }
    for (int i = 0;i < n;i++){
        for (int j = 0; j < n; j++){
            room[i][j] = room2[i+1][j+1];
        }
    }
}


int summary(int n,char room[100][100]){
    int sum = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(room[i][j] == '@' || room[i][j] == '!')
                sum++;
        }
    }
    return sum;
}

int main() {
    int n,m;
    cin >> n;
    char room[100][100] = {'\0'};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> room[i][j];
        }
    }
    cin >> m;
    if(m > 1) {
        for (int i = 1; i < m; i++) {
            infect(n, room);
        }
    }
    else if (m <= 0){
        cout << "Error date!" << endl;
        return 0;
    }
    cout << summary(n,room) << endl;
    return 0;
}
