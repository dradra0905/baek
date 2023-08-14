#include<stdio.h>

int T;
long long int dp[101];

long long int p(int n) {
	if (n <= 3)return 1;

	if (!dp[n]) {
		dp[n] = p(n - 2) + p(n - 3);
	}

	return dp[n];
}

int main() {
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", p(n));
	}

	return 0;
}