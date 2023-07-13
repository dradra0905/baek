#include<stdio.h>

int arr[101][101];
int visited[101][101];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int qx[10001];
int qy[10001];
int head = 0, tail = 0;

void push(int x, int y) {
	qx[head] = x;
	qy[head++] = y;
}

int popx() {
	return qx[tail];
}
int popy() {
	return qy[tail++];
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) scanf("%1d", &arr[i][j]);
	}

	int dist = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] != 0 || arr[i][j] == 0)continue;
			visited[i][j] += dist;
			push(i, j);
			while (tail != head) {
				int x = popx(), y = popy();
				dist = visited[x][y];
				dist++;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (arr[nx][ny] == 0 || visited[nx][ny] != 0)continue;

					visited[nx][ny] += dist;
					push(nx, ny);
				}
			}
		}
	}

	printf("%d\n", visited[n - 1][m - 1]);

	return 0;
}