#include<stdio.h>

#define max(X,Y) (((X) > (Y)) ? (X) : (Y))

int N, M;
int arr[1500];

int main() {
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		int d, d1, d2;
		scanf("%d %d %d", &d, &d1, &d2);

		for (int j = d; j < d + d1; j++)arr[j] += 1;
		for (int j = d + d1; j < d + d1 + d2; j++)arr[j] += 2;
	}

	for (int i = 0; i < M; i++) {
		printf("%d ", arr[M - i - 1] + 1);
		for (int j = 1; j < M; j++) {
			printf("%d ", arr[M + j - 1] + 1);
		}
		printf("\n");
	}


	return 0;
}