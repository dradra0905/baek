#include<stdio.h>

int N, dist = 0;
int map[21][21];
int visited[21][21];

int shark = 2;
int sx = 0, sy = 0;
int sizeCheck[500];

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

int xq[500], yq[500];
int front = 0, back = 0;

void push(int x, int y) {
	xq[front] = x;
	yq[front++] = y;
}
int popx() {
	return xq[back];
}
int popy() {
	return yq[back++];
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 9) {
				sx = i, sy = j;
				push(i, j);
				visited[i][j] = dist;
			}
		}
	}

	int ans = dist;
	while (front != back) {
		int x = popx(), y = popy();
		dist = visited[x][y] + 1;

		if (map[x][y] < shark && map[x][y]) {
			ans = dist - 1;

			map[sx][sy] = 0;

			int stop = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (visited[i][j] == ans && map[i][j] && map[i][j] < shark) {
						x = i, y = j;
						stop++;
						break;
					}
				}
				if (stop)break;
			}

			sx = x, sy = y;
			map[sx][sy] = 9;

			sizeCheck[shark]++;
			if (sizeCheck[shark] == shark)shark++;

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++)visited[i][j] = 0;
			}

			front = back = 0;
			visited[x][y] = ans;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
			if (visited[nx][ny] || map[nx][ny] == 9)continue;
			if (map[nx][ny] > shark)continue;

			push(nx, ny);
			visited[nx][ny] = dist;
		}
	}

	printf("%d\n", ans);


	return 0;
}