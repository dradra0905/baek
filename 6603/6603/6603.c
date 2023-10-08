#include<stdio.h>

int arr[50], check[50];
int ans[50];
int K;

void solve(int n) {
	if (n == 6) {
		for (int i = 0; i < 6; i++)printf("%d ", ans[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < K; i++) {
		if (check[arr[i]])continue;
		if (n && arr[i] < ans[n - 1])continue;
		check[arr[i]] = 1;
		ans[n] = arr[i];
		solve(n + 1);
		ans[n] = check[arr[i]] = 0;
	}
}

int main() {
	int flag = 0;
	while (1) {
		for (int i = 0; i < 50; i++)arr[i] = 0, ans[i] = 0, check[i] = 0;

		scanf("%d", &K);
		if (!K)break;
		if (flag)printf("\n");
		flag = 1;

		for (int i = 0; i < K; i++)scanf("%d", &arr[i]);

		solve(0);
	}
	return 0;
}