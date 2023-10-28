#include<stdio.h>

int N;
char map[101][101];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%s", map[i]);
	}

	int ctn = 0;
	int ga = 0, se = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '.')ctn++;
			else if (map[i][j] == 'X') {
				if (ctn >= 2)ga++;
				ctn = 0;
			}
		}
		if (ctn >= 2)ga++;
		ctn = 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == '.')ctn++;
			else if (map[j][i] == 'X') {
				if (ctn >= 2)se++;
				ctn = 0;
			}
		}
		if (ctn >= 2)se++;
		ctn = 0;
	}

	printf("%d %d\n", ga, se);

	return 0;
}