#include<stdio.h>

int mtx[101][101];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			scanf("%d", &a);
			mtx[i][j] += a;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			scanf("%d", &a);
			mtx[i][j] += a;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", mtx[i][j]);
		}
		printf("\n");
	}


	return 0;
}