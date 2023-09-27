#include<stdio.h>

int R, C, dist;
char map[51][51];
int visited[51][51];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

typedef struct pos {
	int x;
	int y;
}pos;

pos queue[2501];
pos goal;
int front = 0, back = 0;

void push(int x, int y) {
	queue[front].x = x;
	queue[front++].y = y;
}
pos pop() {
	return queue[back++];
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		getchar();
		for (int j = 0; j < C; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'S') {
				push(i, j);
				visited[i][j] = 1;
			}
			else if (map[i][j] == '*') {
				push(i, j);
				visited[i][j] = 3001;
			}
			else if (map[i][j] == 'D') {
				goal.x = i;
				goal.y = j;
			}
		}
	}

	while (back != front) {
		pos cur = pop();
		dist = visited[cur.x][cur.y] + 1;

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + cur.x, ny = dy[i] + cur.y;

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)continue;
			if (visited[nx][ny]) {
				if (dist > 3000 && visited[nx][ny] <= 3000 && dist - 3000 <= visited[nx][ny]);
				else continue;
			}
			if (map[nx][ny] == 'X')continue;

			if (dist - 1 > 3000 && map[nx][ny] == 'D')continue;

			push(nx, ny);
			visited[nx][ny] = dist;
		}
	}

	if (visited[goal.x][goal.y])printf("%d\n", visited[goal.x][goal.y] - 1);
	else printf("KAKTUS\n");


	return 0;
}