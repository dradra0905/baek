#include<stdio.h>

#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define min(a,b)  (((a) < (b)) ? (a) : (b))

int a[500001];
int sum[500001] = { 0 };
int sum2[500001] = { 0 };

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum[i + 1] = a[i] - k * (i + 1);
		sum2[i + 1] = a[i] + k * (i + 1);
	}

	int mi = sum[1], ans = -1e9;
	for (int i = 1; i < n; i++) {
		mi = min(mi, sum[i]);
		ans = max(sum[i + 1] - mi, ans);
	}

	mi = sum2[n];
	for (int i = n; i >= 1; i--) {
		mi = min(mi, sum2[i]);
		ans = max(sum2[i - 1] - mi, ans);
	}

	printf("%d\n", ans);


	return 0;
}