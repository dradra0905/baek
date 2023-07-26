#include<stdio.h>

#define min(x,y) (((x) > (y)) ? (y) : (x))

int arr[1000001];

void dp(int n) {
	if (n == 1) {
		arr[n] == 0;
		return;
	}
	arr[n] = n;

	if (n % 2 == 0) {
		arr[n] = min(arr[n / 2] + 1, arr[n]);
	}
	if (n % 3 == 0) {
		arr[n] = min(arr[n / 3] + 1, arr[n]);
	}
	arr[n] = min(arr[n - 1] + 1, arr[n]);

}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		dp(i);
	}

	printf("%d\n", arr[n]);

	return 0;
}