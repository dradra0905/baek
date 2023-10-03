#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);

int arr[5000001];
int N, K;

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)scanf("%d", &arr[i]);
    qsort(arr, N, sizeof(int), compare);

    printf("%d\n", arr[K - 1]);


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