#include<stdio.h>

typedef struct pos {
    int x;
    int y;
    int k;
}pos;
pos queue[1300000];
int front = 0, back = 0;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int kx[8] = { 2,1,2,1,-2,-1,-2,-1 };
int ky[8] = { 1,2,-1,-2,1,2,-1,-2 };

int K, W, H, dist = 0;
int map[201][201];
int visited[31][201][201];

void push(int k, int x, int y) {
    queue[front].k = k;
    queue[front].x = x;
    queue[front++].y = y;
}
pos pop() {
    return queue[back++];
}

int main() {
    scanf("%d", &K);
    scanf("%d %d", &W, &H);
    for (int i = 0; i < H; i++)for (int j = 0; j < W; j++)scanf("%d", &map[i][j]);
    push(K, H - 1, W - 1);
    visited[K][H - 1][W - 1] = 1;

    while (front != back) {
        pos cur = pop();
        dist = visited[cur.k][cur.x][cur.y] + 1;
        int k = cur.k;

        int count = 0;
        if (cur.k) {
            for (int i = 0; i < 8; i++) {
                int nx = cur.x + kx[i], ny = cur.y + ky[i];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
                if (map[nx][ny])continue;
                if (visited[k - 1][nx][ny])continue;

                push(k - 1, nx, ny);
                visited[k - 1][nx][ny] = dist;
                count++;
            }
            if (count)cur.k--;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
            if (map[nx][ny])continue;
            if (visited[k][nx][ny])continue;

            push(k, nx, ny);
            visited[k][nx][ny] = dist;
        }
    }

    int ans = 0;
    for (int i = 0; i <= K; i++) {
        if (!ans)ans = visited[i][0][0];
        else if (visited[i][0][0] && ans > visited[i][0][0])ans = visited[i][0][0];
    }

    printf("%d\n", ans - 1);

    return 0;
}