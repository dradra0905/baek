#include<stdio.h>

int arr[1000001];
int check[1000001];
int N;

void dp(int n) {
	if (n == 1) {
		arr[n] == 0;
		return;
	}
	arr[n] = n;

	if (n % 2 == 0) {
		if (arr[n / 2] + 1 > arr[n]) {
			arr[n] = arr[n];
		}
		else {
			arr[n] = arr[n / 2] + 1;
			check[n] = n / 2;
		}
	}
	if (n % 3 == 0) {
		if (arr[n / 3] + 1 > arr[n]) {
			arr[n] = arr[n];
		}
		else {
			arr[n] = arr[n / 3] + 1;
			check[n] = n / 3;
		}
	}

	if (arr[n - 1] + 1 > arr[n]) {
		arr[n] = arr[n];
	}
	else {
		arr[n] = arr[n - 1] + 1;
		check[n] = n - 1;
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		dp(i);
	}

	printf("%d\n%d ", arr[N], N);

	int ret = N;
	while (ret != 1) {
		ret = check[ret];
		printf("%d ", ret);
	}

	return 0;
}