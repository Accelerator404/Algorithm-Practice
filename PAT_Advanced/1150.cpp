#include <iostream>
#include <vector>
#include <set>

using namespace std;

// PAT Advanced Level 201809 7-3 &
// PAT Advanced Level 1150 Travelling Salesman Problem

const int INF = 99999999;
int e[205][205];

int main() {
    int N, M;
    cin >> N >> M;
    fill(e[0], e[0] + 205 * 205, INF);
    for (int i = 0; i < M; i++) {
        int city1, city2, dist;
        scanf("%d%d%d", &city1, &city2, &dist);
        e[city1][city2] = e[city2][city1] = dist;
    }
    int K;
    cin >> K;
    int minSolution = INF, path = 0;
    for (int i = 1; i <= K; i++) {
        bool visited[205], notSimple = false, wrongWay = false, notCycle = false, notAllTraveled = false;
        fill(visited, visited + 205, false);
        int start, totalDist = 0;
        int n;
        cin >> n;
        vector<int> seq(n);
        for (int j = 0; j < n; j++) {
            int u;
            scanf("%d", &u);
            seq[j] = u;
        }
        start = seq[0];
        if (start != seq[n - 1]) {
            notCycle = true;
        }
        for (int j = 0; j < n - 1; j++) {
            int thisDist = e[seq[j]][seq[j + 1]];
            if (thisDist == INF) {
                wrongWay = true;
                break;
            }
            totalDist += thisDist;
            if (visited[seq[j]])
                notSimple = true;
            visited[seq[j]] = true;
        }
        for (int j = 1; j <= N; j++) {
            if (!visited[j])
                notAllTraveled = true;
        }
        printf("Path %d: ", i);
        if (wrongWay)
            printf("NA (Not a TS cycle)\n");
        else if (notCycle)
            printf("%d (Not a TS cycle)\n", totalDist);
        else if (notAllTraveled)
            printf("%d (Not a TS cycle)\n", totalDist);
        else if (notSimple) {
            printf("%d (TS cycle)\n", totalDist);
            if (totalDist < minSolution) {
                minSolution = totalDist;
                path = i;
            }
        }
        else {
            printf("%d (TS simple cycle)\n", totalDist);
            if (totalDist < minSolution) {
                minSolution = totalDist;
                path = i;
            }
        }
    }
    printf("Shortest Dist(%d) = %d", path, minSolution);
    return 0;
}
