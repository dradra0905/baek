#include<stdio.h>

int N;
int arr[11];

int main() {
	scanf("%d", &N);
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= N; i++) {
		arr[i] = (i / 2) * (i - (i / 2)) + arr[i / 2] + arr[i - (i / 2)];
	}
	printf("%d\n", arr[N]);
	return 0;
}