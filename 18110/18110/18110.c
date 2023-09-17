#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int static compare(const void* first, const void* second);

int n, sum = 0;
int arr[300001];

int main() {
    scanf("%d", &n);
    if (!n) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
    qsort(arr, (int)n, sizeof(int), compare);

    int up = (round((((float)n * 3) / 20)));

    for (int i = up; i < n - up; i++) {
        sum += arr[i];
    }

    printf("%d\n", (int)round(((float)sum / (n - 2 * up))));

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