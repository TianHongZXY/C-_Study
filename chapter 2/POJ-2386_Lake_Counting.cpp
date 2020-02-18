#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_N = 100, MAX_M = 100;
char field[MAX_N][MAX_M + 1];
int N, M;

void dfs(int x, int y, char field[][MAX_M+1]){
    field[x][y] = '.';

    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++){
            int nx = x + dx, ny = y + dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') dfs(nx, ny, field);
        }
    return;
}

void solve(char field[][MAX_M+1]){
    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++){
            if (field[i][j] == 'W'){
                dfs(i, j, field);
                res++;
            }
        }
    printf("%d\n", res);
}

int main(){
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++){
            // scanf("%c", &field[i][j]);
            cin >> field[i][j];
        }
    solve(field);
    
}