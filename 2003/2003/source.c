#include<stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[10001], sum[10001] = { 0 }, sum2[10001] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum[i + 1] = sum[i] + arr[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (sum[j + 1] - sum[i] == m)cnt++;
		}
	}
	printf("%d\n", cnt);

	return 0;
}