#include<stdio.h>

int N;

int main() {
	scanf("%d", &N);
	do {
		int tmp = N;
		while (tmp % 10 == 7 || tmp % 10 == 4) {
			tmp /= 10;
		}
		if (tmp == 0)break;
	} while (N--);
	printf("%d\n", N);
	return 0;
}