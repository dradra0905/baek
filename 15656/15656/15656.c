#include<stdio.h>
#include<stdlib.h>

int N, M;
int arr[10], ans[10];
int static compare(const void* first, const void* second);

void solve(int n) {
	if (n == M) {
		for (int i = 0; i < M; i++)printf("%d ", ans[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		ans[n] = arr[i];
		solve(n + 1);
		ans[n] = 0;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), compare);
	solve(0);


	return 0;
}

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}