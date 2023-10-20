#include<stdio.h>

int N, M;
char map[51][51];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < M; j++) {
			scanf("%c", &map[i][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		char before = 0;
		for (int j = 0; j < M; j++) {
			if (before != map[i][j] && map[i][j] == '-') {
				ans++;
			}
			before = map[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		char before = 0;
		for (int j = 0; j < N; j++) {
			if (before != map[j][i] && map[j][i] == '|') {
				ans++;
			}
			before = map[j][i];
		}
	}

	printf("%d\n", ans);

	return 0;
}