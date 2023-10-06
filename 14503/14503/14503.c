#include<stdio.h>

int N, M, r, c, d;
int map[51][51];
int clean[51][51];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);

	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)scanf("%d", &map[i][j]);

	int ans = 0;
	while (1) {
		if (!clean[r][c])ans++;
		clean[r][c] = 1;

		int tmp = d, flag = 0;
		for (int i = 0; i < 4; i++) {
			tmp--;
			if (tmp < 0)tmp += 4;

			int nx = r + dx[tmp], ny = c + dy[tmp];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (clean[nx][ny] || map[nx][ny])continue;

			r = nx, c = ny;
			flag = 1;
			break;
		}

		if (!flag) {
			tmp -= 2;
			if (tmp < 0)tmp += 4;

			int nx = r + dx[tmp], ny = c + dy[tmp];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)break;
			if (map[nx][ny])break;

			r = nx, c = ny;
			continue;
		}

		d = tmp;
	}

	printf("%d\n", ans);
	return 0;
}