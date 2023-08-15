#include<stdio.h>

int M, N, H;
int dist = 0;
int tom[101][101][101];
int visited[101][101][101];

int dx[4] = { 0,1,0,-1};
int dy[4] = { 1,0,-1,0};
int dz[2] = { 1,-1 };

int xq[1000000];
int yq[1000000];
int zq[1000000];

int front = 0, back = 0;

void push(int z, int x, int y) {
	xq[front] = x;
	yq[front] = y;
	zq[front++] = z;
}
int popx() {
	return xq[back];
}
int popy() {
	return yq[back];
}
int popz() {
	return zq[back++];
}


int main() {
	scanf("%d %d %d", &M, &N, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &tom[i][j][k]);
				if (tom[i][j][k] == 1) {
					push(i, j, k);
					visited[i][j][k] = dist;
				}
			}
		}
	}

	while (back != front) {
		int x = popx(), y = popy(), z = popz();
		dist = visited[z][x][y] + 1;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (visited[z][nx][ny])continue;
			if (tom[z][nx][ny] != 0)continue;

			push(z, nx, ny);
			visited[z][nx][ny] = dist;
		}

		for (int j = 0; j < 2; j++) {
			int nz = z + dz[j];
			if (nz < 0 || nz >= H)continue;
			if (visited[nz][x][y])continue;
			if (tom[nz][x][y] != 0)continue;

			push(nz, x, y);
			visited[nz][x][y] = dist;

		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (tom[i][j][k] == 0 && visited[i][j][k] == 0) {
					printf("-1\n");
					return 0;
				}
			}
		}
	}

	printf("%d\n", dist - 1);

	return 0;
}