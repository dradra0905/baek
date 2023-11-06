#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);

int N, L;
int arr[1001];

int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)scanf("%d", &arr[i]);
    qsort(arr, N, sizeof(int), compare);

    int idx = 0;
    while (arr[idx] <= L && idx < N) {
        idx++, L++;
    }

    printf("%d\n", L);

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