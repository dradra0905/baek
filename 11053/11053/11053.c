#include<stdio.h>

#define max(X,Y) (((X) > (Y)) ? (X) : (Y))

int arr[1001];
int dp[1001];
int N, mx = 0, ans = 0;


int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
				mx = max(mx, dp[i]);
			}
		}
	}

	printf("%d\n", mx + 1);

	return 0;
}