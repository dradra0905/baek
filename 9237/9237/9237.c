#include<stdio.h>
#include<stdlib.h>
int static compare(const void* first, const void* second);

int N;
int arr[100010];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)scanf("%d", &arr[i]);
    qsort(arr, N, sizeof(int), compare);

    int date = 0;
    for (int i = 0; i < N; i++) {
        if (date < arr[i] + i + 1) {
            date = arr[i] + i + 1;
        }
    }

    printf("%d\n", date + 1);

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