#include<stdio.h>

int t, k, n;
int arr[15][15] = { {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14} };

int dp(int a, int b) {
	if (arr[a][b])return arr[a][b];
	if (b == 1) {
		arr[a][b] = 1;
		return 1;
	}

	arr[a][b] = dp(a - 1, b) + dp(a, b - 1);
	return arr[a][b];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &k, &n);
		dp(k, n);
		printf("%d\n", arr[k][n]);
	}

	return 0;
}