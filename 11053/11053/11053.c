#include<stdio.h>

#define max(X,Y) (((X) > (Y)) ? (X) : (Y))

int arr[1001];
int dp[1001][1001];
int check[1001];
int visited[1001];
int N, mx = 0, ans = 0;

int fn(int n) {
	if (n == N - 1)return 0;
	if (check[n])return visited[n];

	fn(n + 1);

	int mx = 0;

	for (int i = n + 1; i < N; i++) {
		if (arr[n] < arr[i]) {
			dp[n][i] = fn(i) + 1;
			mx = max(mx, dp[n][i]);
		}
		else dp[n][i] = 0;
	}

	visited[n] = mx;
	check[n] = 1;
	return mx;
}


int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}


	fn(0);

	for (int i = 0; i < N; i++) {
		ans = max(ans, visited[i]);
	}

	printf("%d\n", ans + 1);

	return 0;
}