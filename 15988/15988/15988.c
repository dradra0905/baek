#include<stdio.h>

int n;
long long int dp[1000001];

int main() {
	scanf("%d", &n);
	dp[1] = 1, dp[2] = 2, dp[3] = 4;

	for (int i = 4; i <= 1000000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;

	while (n--) {
		int a;
		scanf("%d", &a);
		printf("%lld\n", dp[a]);
	}

	return 0;
}