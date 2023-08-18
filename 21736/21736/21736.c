#include<stdio.h>

int N, M, count = 0;
char map[601][601];
int visited[601][601];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int front = 0, back = 0;
int xq[360000];
int yq[360000];

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
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < M; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'I') {
				push(i, j);
				visited[i][j] = 1;
			}
		}
	}

	while (front != back) {
		int x = popx(), y = popy();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (visited[nx][ny])continue;
			if (map[nx][ny] == 'X')continue;
			
			if (map[nx][ny] == 'P')count++;
			push(nx, ny);
			visited[nx][ny] = 1;
		}
	}

	if (count)printf("%d\n", count);
	else printf("TT\n");


	return 0;
}