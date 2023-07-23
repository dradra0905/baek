#include<stdio.h>

int n, cnt = 0;
int y[31], xpy[31], xmy[31];

void queen(int m) {
	if (m == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (y[i] || xpy[m + i] || xmy[m - i + n - 1])continue;
		y[i] = xpy[m + i] = xmy[m - i + n - 1] = 1;
		queen(m + 1);
		y[i] = xpy[m + i] = xmy[m - i + n - 1] = 0;
	}
}

int main() {
	scanf("%d", &n);

	queen(0);

	printf("%d\n", cnt);

	return 0;
}