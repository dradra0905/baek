#include<stdio.h>

char arr[501][501];
int cp[501][501][30];

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++)scanf("%c", &arr[i][j]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)cp[i % k][j % k][arr[i][j] - 64]++;
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			int max = 0;
			for (int l = 1; l <= 26; l++) {
				if (max < cp[i][j][l]) {
					max = cp[i][j][l];
					cp[i][j][0] = l;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != cp[i % k][j % k][0] + 64) {
				cnt++;
				arr[i][j] = cp[i % k][j % k][0] + 64;
			}
		}
	}
	printf("%d \n",cnt);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}