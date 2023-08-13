#include<stdio.h>

int T;
int arr[12];

int dp(int n) {
	if (n < 0)return 0;
	if (n == 0)return 1;

	if (!arr[n]) {
		arr[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
	}

	return arr[n];
}


int main() {
	scanf("%d", &T);

	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", dp(n));
	}

	return 0;
}