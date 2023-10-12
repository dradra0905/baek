#include<stdio.h>

int N, count = 0, sum = 0;
int arr[4] = { 1,5,10,50 };
int ans[1001];

void solve(int n, int now) {
	if (n == N) {
		if (!ans[sum])count++;
		ans[sum] = 1;
		return;
	}
	for (int i = now; i < 4; i++) {
		sum += arr[i];
		solve(n + 1, i);
		sum -= arr[i];
	}
}

int main() {
	scanf("%d", &N);
	solve(0, 0);

	printf("%d\n", count);
	return 0;
}