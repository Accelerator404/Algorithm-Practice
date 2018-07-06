#include <iostream>
using namespace std;

//PAT Advanced 1008 Elevator

int main(){
    int N,position,time;
    int requestList[101];
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> requestList[i];
    }
    position = 0,time = 0;
    for (int j = 0; j < N; ++j) {
        if(requestList[j] > position)
            time += 6 * (requestList[j] - position);
        else if(requestList[j] < position)
            time += 4 * (position - requestList[j]);
        position = requestList[j];
        time += 5;
    }
    cout << time;
    return 0;
}
