#include<stdio.h>

char map[1001][1001];
int jv[1001][1001];
int fv[1001][1001];
char visited[1001][1001];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int jqx[1000001];
int jqy[1000001];
int jh = 0, jt = 0;

void pushj(int x, int y) {
	jqx[jh] = x;
	jqy[jh++] = y;
}
int popjx() {
	return jqx[jt];
}
int popjy() {
	return jqy[jt++];
}

int fqx[1000001];
int fqy[1000001];
int fh = 0, ft = 0;

void pushf(int x, int y) {
	fqx[fh] = x;
	fqy[fh++] = y;
}
int popfx() {
	return fqx[ft];
}
int popfy() {
	return fqy[ft++];
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int dist = 0;
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
			fv[i][j] = -1;
			if (map[i][j] == 'J') {
				visited[i][j] = 'J';
				jv[i][j] = dist;
				pushj(i, j);
			}
			else if (map[i][j] == 'F') {
				visited[i][j] = 'F';
				fv[i][j] = dist;
				pushf(i, j);
			}
			else visited[i][j] = '0';
		}
	}

	while (fh != ft) {
		int	fx = popfx(), fy = popfy();
		dist = fv[fx][fy] + 1;
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i], ny = fy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (map[nx][ny] == '#' || visited[nx][ny] == 'F')continue;

			visited[nx][ny] = 'F';
			fv[nx][ny] = dist;
			pushf(nx, ny);

		}
	}
	while (jh != jt) {
		int jx = popjx(), jy = popjy();
		dist = jv[jx][jy] + 1;
		for (int i = 0; i < 4; i++) {
			int nx = jx + dx[i], ny = jy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				printf("%d\n", dist);
				return 0;
			}
			if (map[nx][ny] != '.' || visited[nx][ny] == 'J')continue;
			if (fv[nx][ny] != -1 && fv[nx][ny] <= dist)continue;

			visited[nx][ny] = 'J';
			jv[nx][ny] = dist;
			pushj(nx, ny);

		}
	}
	printf("IMPOSSIBLE\n");

	return 0;
}