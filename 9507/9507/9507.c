#include<stdio.h>

int t, n;
long long int a[70];

int main() {
	scanf("%d", &t);
	a[0] = a[1] = 1;
	a[2] = 2, a[3] = 4;

	for (int i = 4; i < 68; i++) {
		a[i] = a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4];
	}

	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", a[n]);
	}

	return 0;
}