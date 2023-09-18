#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int arr[8001], ar[500001];
int N, sum = 0, min = 4001, max = -4001, count = 0, cb = 0, p = 0;

int static compare(const void* first, const void* second);

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &ar[i]);
        sum += ar[i];
        min = min > ar[i] ? ar[i] : min;
        max = max < ar[i] ? ar[i] : max;
        arr[ar[i] + 4000]++;
        if (arr[ar[i] + 4000] > count) {
            count = arr[ar[i] + 4000];
        }
    }
    qsort(ar, N, sizeof(int), compare);

    for (int i = 0; i <= 8000; i++) {
        if (arr[i] == count)p = i - 4000, cb++;
        if (cb == 2)break;
    }

    printf("%d\n%d\n%d\n%d\n", (int)round((float)sum / N), ar[N / 2], p, max - min);

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