#include<stdio.h>

int n, d, cnt = 0;

int main() {
	scanf("%d %d", &n, &d);

	for (int i = 1; i <= n; i++) {
		int tmp = i;
		while (tmp > 0) {
			if (tmp % 10 == d)cnt++;
			tmp /= 10;
		}
	}

	printf("%d\n", cnt);
	return 0;
}