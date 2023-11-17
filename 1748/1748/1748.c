#include<stdio.h>

int N, count = 1;
long long int sum = 0;

int main() {
	scanf("%d", &N);
	while (N) {
		if (N < 10)sum += (N), N = 0;
		else if (N < 100)sum += ((N - 9) * 2), N = 9;
		else if (N < 1000)sum += ((N - 99) * 3), N = 99;
		else if (N < 10000)sum += ((N - 999) * 4), N = 999;
		else if (N < 100000)sum += ((N - 9999) * 5), N = 9999;
		else if (N < 1000000)sum += ((N - 99999) * 6), N = 99999;
		else if (N < 10000000)sum += ((N - 999999) * 7), N = 999999;
		else if (N < 100000000)sum += ((N - 9999999) * 8), N = 9999999;
		else if (N == 100000000)sum += 9, N = 99999999;
	}

	printf("%lld\n", sum);

	return 0;
}