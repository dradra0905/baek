#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);

int K, N;
int arr[51];

int main() {
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d", &N);
		int max = 0, min = 101;
		for (int j = 0; j < N; j++)scanf("%d", &arr[j]);
		qsort(arr, N, sizeof(int), compare);
		int gap = 0;
		for (int j = 0; j < N - 1; j++) {
			if (gap < arr[j + 1] - arr[j])gap = arr[j + 1] - arr[j];
		}

		printf("Class %d\nMax %d, Min %d, Largest gap %d\n", i+1, arr[N - 1], arr[0], gap);
	}

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