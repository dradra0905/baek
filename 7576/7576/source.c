#include<stdio.h>

int arr[1001][1001];
int visited[1001][1001];

int qx[1000001];
int qy[1000001];
int head = 0, tail = 0;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

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
	int dist = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				visited[i][j] = dist;
				push(i, j);
			}
			if (arr[i][j])cnt++;
		}
	}

	while (tail != head) {
		int x = popx(), y = popy();
		dist = visited[x][y] + 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n)continue;
			if (visited[nx][ny] != 0 || arr[nx][ny] != 0)continue;

			visited[nx][ny] = dist;
			push(nx, ny);
		}
	}

	int vcnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0)vcnt++;
		}
	}

	if (cnt == vcnt)printf("%d\n", dist - 1);
	else printf("-1\n");

	return 0;
}