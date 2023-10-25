#include<stdio.h>

int N;
long long int arr[91];

int main() {
	scanf("%d", &N);
	arr[0] = arr[1] = 1;
	for (int i = 2; i < N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	printf("%lld\n", arr[N - 1]);

	return 0;
}