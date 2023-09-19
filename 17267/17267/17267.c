#include<stdio.h>

int N, M, L, R, count = 0, dist = 0;

typedef struct pos {
	int x;
	int y;
	int left;
	int right;
	int dir;
}pos;
pos queue[10000000];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int map[1001][1001];
int visited[5][1001][1001];
int check[5][1001][1001];

int front = 0, back = 0;

void push(int x, int y, int left, int right, int dir) {
	queue[front].dir = dir;
	queue[front].left = left;
	queue[front].right = right;
	queue[front].x = x;
	queue[front++].y = y;
}
pos pop() {
	return queue[back++];
}


int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d", &L, &R);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 2)push(i, j, L, R, 0), visited[1][i][j] = check[1][i][j] = visited[2][i][j] = check[2][i][j] = visited[3][i][j] = check[3][i][j] = visited[4][i][j] = check[4][i][j] = 1;
		}
	}

	int direction = -1;
	while (front != back) {
		pos p = pop();
		int x = p.x, y = p.y;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			int left = p.left, right = p.right;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (map[nx][ny] == 1)continue;
			if ((i == 2 && left == 0) || (i == 3 && right == 0))continue;
			if (visited[p.dir][nx][ny])continue;

			if (i == 2)left--;
			else if (i == 3)right--;

			if (!p.dir)direction = i + 1;
			else direction = p.dir;

			push(nx, ny, left, right, direction);
			visited[direction][nx][ny] = check[direction][nx][ny] = direction;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[1][i][j] || check[2][i][j] || check[3][i][j] || check[4][i][j])count++;
		}
	}

	printf("%d\n", count);

	return 0;
}