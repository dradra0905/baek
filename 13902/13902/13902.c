#include<stdio.h>

#define min(x,y) (((x) > (y)) ? (y) : (x))

int s[1001];
int dd[10001];
int dp[10001] = { 0 };
int dp2[10001] = { 1 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &s[i]);
		dp[s[i]] = 1;
	}

	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			int w = s[j] + s[i];
			if (w > 0)dp[w] = 1;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i]) {
			dd[cnt] = i;
			cnt++;
		}
	}

	for (int i = 1; i <= n; i++) {
		int mn = 1e9;
		for (int j = 0; j < cnt; j++) {
			int w = i - dd[j];
			if (w < 0)break;
			mn = min(mn, dp[w]);
		}
		if (!dp[i])dp[i] = mn + 1;
	}

	if (dp[n] == 1000000001)printf("-1\n");
	else printf("%d\n", dp[n]);

	return 0;
}