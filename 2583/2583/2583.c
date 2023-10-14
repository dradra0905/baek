#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);

typedef struct pos {
	int x;
	int y;
}pos;
pos p[10001];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int M, N, K;
int map[101][101];
int visited[101][101];

int area[101];

int front = 0, back = 0;
void push(int x, int y) {
	p[front].x = x;
	p[front++].y = y;
}
pos pop() {
	return p[back++];
}

int main() {
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < K; i++) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				map[k][j] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!map[i][j] && !visited[i][j]) {
				push(i, j);
				visited[i][j] = 1;
				ans++;
			}

			while (front != back) {
				pos cur = pop();
				area[ans - 1]++;

				for (int k = 0; k < 4; k++) {
					int nx = cur.x + dx[k], ny = cur.y + dy[k];

					if (nx < 0 || nx >= M || ny < 0 || ny >= N)continue;
					if (map[nx][ny])continue;
					if (visited[nx][ny])continue;

					push(nx, ny);
					visited[nx][ny] = 1;
				}
			}
		}
	}

	printf("%d\n", ans);
	qsort(area, ans, sizeof(int), compare);
	for (int i = 0; i < ans; i++)printf("%d ", area[i]);

	return 0;
}

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}