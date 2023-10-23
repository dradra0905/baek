#include<stdio.h>

int N;

int main() {
	scanf("%d", &N);
	int tmp = N;
	int seven = 0;

	while (tmp) {
		if (tmp % 10 == 7)seven = 1;
		tmp /= 10;
	}

	if (!seven && N % 7 != 0)printf("0\n");
	else if (!seven && N % 7 == 0)printf("1\n");
	else if (seven && N % 7 != 0)printf("2\n");
	else if (seven && N % 7 == 0)printf("3\n");

	return 0;
}