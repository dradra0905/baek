#include<stdio.h>

int N, M;
int arr[101];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)arr[i] = i + 1;
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		int tmp = arr[a - 1];
		arr[a - 1] = arr[b - 1];
		arr[b - 1] = tmp;
	}

	for (int i = 0; i < N; i++)printf("%d ", arr[i]);
	
	return 0;
}