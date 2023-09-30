#include<stdio.h>

int N, M;
char map[51][51];
int row[51], column[51];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < M; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'X')row[i] = 1, column[j] = 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!row[i] && !column[j]) {
				row[i] = column[j] = 1;
				ans++;
				break;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!column[j]) {
				row[i] = column[j] = 1;
				ans++;
				continue;
			}
		}
		if (!row[i]) {
			row[i] = 1;
			ans++;
			continue;
		}
	}

	printf("%d\n", ans);

	return 0;
}