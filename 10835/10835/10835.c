#include<stdio.h>

#define max(x,y) (((x) > (y)) ? (x) : (y))

int N;
int A[2001];
int B[2001];
int ans[2001][2001];

int dp(int x, int y) {
    if (x == N || y == N)return 0;
    if (ans[x][y] > -1)return ans[x][y];

    if (A[x] <= B[y]) {
        int le = dp(x + 1, y);
        int bo = dp(x + 1, y + 1);
        ans[x][y] = max(le, bo);
    }
    else {
        ans[x][y] = dp(x, y + 1) + B[y];
    }

    return ans[x][y];
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)scanf("%d", &A[i]);
    for (int i = 0; i < N; i++)scanf("%d", &B[i]);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans[i][j] = -1;
        }
    }
    int answer = dp(0, 0);
    printf("%d\n", ans[0][0]);

    return 0;
}