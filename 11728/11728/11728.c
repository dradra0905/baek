#include<stdio.h>

int N, M;
int a[1000001];
int b[1000001];

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)scanf("%d", &a[i]);
	for (int i = 0; i < M; i++)scanf("%d", &b[i]);

	int index1 = 0, index2 = 0;

	while (index1 + index2 < N + M) {
		if (index1 == N) {
			printf("%d ", b[index2++]);
		}
		else if (index2 == M) {
			printf("%d ", a[index1++]);
		}
		else if (a[index1] >= b[index2]) {
			printf("%d ", b[index2++]);
		}
		else {
			printf("%d ", a[index1++]);
		}
	}

	return 0;
}