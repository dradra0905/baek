#include<stdio.h>
#include<stdlib.h>

#define max(X,Y) (((X) > (Y)) ? (X) : (Y))

int N, ans = 0;
int arr[100001];

int static compare(const void* first, const void* second);

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), compare);

	for (int i = 0; i < N; i++) {
		ans = max(ans, (i + 1) * arr[i]);
	}

	printf("%d\n", ans);

	return 0;
}

int static compare(const void* first, const void* second)
{
	if (*(int*)first < *(int*)second)
		return 1;
	else if (*(int*)first > *(int*)second)
		return -1;
	else
		return 0;
}