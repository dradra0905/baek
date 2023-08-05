#include<stdio.h>

#define min(x,y) (((x) > (y)) ? (y) : (x))

int N, M, dist = 0;
int order = '0';
char map[51][51];
int visited[51][51][1 << 6];
int distance[51][51];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int xq[500000], yq[500000], lq[500000];
int front = 0, back = 0;

void push(int x, int y,int log) {
	xq[front] = x;
	yq[front] = y;
	lq[front++] = log;
}

int popx() {
	return xq[back];
}
int popy() {
	return yq[back];
}
int popl() {
	return lq[back++];
}

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < M; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'S') {
				push(i, j, 0);
				visited[i][j][0] = dist;
			}
			if (map[i][j] == 'X') {
				map[i][j] = order++;
			}
		}
	}

	int ans = 1e9;

	while (back != front) {
		int x = popx(), y = popy(), log = popl();
		dist = visited[x][y][log] + 1;


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= N || nx < 0 || ny >= M || ny < 0)continue;
			if (map[nx][ny] == '#')continue;
			if (visited[nx][ny][log]) {
				continue;
			}

			if (map[nx][ny] == 'E' && log == (1 << (order - '0')) - 1) {
				ans = min(ans, dist);
				continue;
			}
			else if (map[nx][ny] == 'E')continue;

			int tmp = log;
			if (map[nx][ny] >= '0' && map[nx][ny] < '5') {
				tmp |= (1 << (map[nx][ny] - '0'));
			}

			push(nx, ny, tmp);
			visited[nx][ny][tmp] = dist;
		}
	}

	printf("%d\n", ans);

	return 0;
}