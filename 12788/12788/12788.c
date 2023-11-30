#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);

int N, M, K;
int a[1001];

int main() {
    scanf("%d", &N);
    scanf("%d %d", &M, &K);

    for (int i = 0; i < N; i++)scanf("%d", &a[i]);
    qsort(a, N, sizeof(int), compare);

    int sum = 0, ans = 0;
    while (sum < M * K) {
        sum += a[ans++];
        if (ans > N) {
            printf("STRESS\n");
            return 0;
        }
    }

    printf("%d\n", ans);

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