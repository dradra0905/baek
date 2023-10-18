#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);

int N, M, max = 0, count = 0;
int arr[1001];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)scanf("%d", &arr[i]);
    qsort(arr, M, sizeof(int), compare);

    for (int i = 0; i < N && i<M; i++) {
        if (max < (i + 1) * arr[i]) {
            count = arr[i];
            max = (i + 1) * arr[i];
        }
    }

    printf("%d %d\n", count, max);

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