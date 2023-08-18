#include<stdio.h>

int dp[1001];

int p(int n) {
	if (n <= 0)return 0;
	if (n == 1)return 1;
	if (n == 2)return 2;

	if (!dp[n]) {
		dp[n] = (p(n - 1) + p(n - 2)) % 10007;
	}

	return dp[n];
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%d", p(n));

	return 0;
}