#include<stdio.h>

#define min(X,Y) (((X) < (Y)) ? (X) : (Y))

int arr[100001];
int N, ans = 0;

int main() {
	scanf("%d", &N);
	arr[1] = arr[3] = -1, arr[2] = arr[5] = 1, arr[4] = arr[7] = arr[10] = 2, arr[6] = arr[9] = 3, arr[8] = 4;

	for (int i = 11; i <= N; i++) {
		arr[i] = min(arr[i - 2], arr[i - 5]) + 1;
	}

	printf("%d\n", arr[N]);

	return 0;
}