#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);

int N;
int arr[3001];

int main() {
	scanf("%d", &N);

	int flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!flag)scanf("%d", &arr[j]);
			else scanf("%d", &arr[j + N]);
		}
		if (flag)
			qsort(arr, 2 * N, sizeof(int), compare);
		else {
			qsort(arr, N, sizeof(int), compare);
			flag = 1;
		}
	}

	printf("%d\n", arr[N - 1]);

	return 0;
}

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return -1;
	else if (*(int*)first < *(int*)second)
		return 1;
	else
		return 0;
}
