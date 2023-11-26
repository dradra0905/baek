#include<stdio.h>

typedef struct pos {
	int x;
	int y;
}pos;

int dx[8] = { 1,0,-1,0,1,1,-1,-1 };
int dy[8] = { 0,1,0,-1,1,-1,1,-1 };

int map[51][51];
int visited[51][51];

int front = 0, back = 0;
pos p[2501];

void push(int x, int y) {
	p[front].x = x;
	p[front++].y = y;
}
pos pop() {
	return p[back++];
}
int w, h;

int main() {
	while (1) {
		int ans = 0;
		front = back = 0;
		scanf("%d %d", &h, &w);
		if (!w && !h)break;

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (!visited[i][j] && map[i][j]) {
					push(i, j);
					visited[i][j] = 1;
					ans++;
					while (back != front) {
						pos now = pop();

						for (int k = 0; k < 8; k++) {
							int nx = dx[k] + now.x, ny = dy[k] + now.y;

							if (nx < 0 || nx >= w || ny < 0 || ny >= h)continue;
							if (visited[nx][ny])continue;
							if (!map[nx][ny])continue;

							push(nx, ny);
							visited[nx][ny] = 1;
						}
					}
				}
			}
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				map[i][j] = visited[i][j] = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}