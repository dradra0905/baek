#include<stdio.h>
#include<stdlib.h>

int N, M;
int arr[10];
int carr[10];
int check[10];

int static compare(const void* first, const void* second);

void solve(int cur) {
    if (cur == M) {
        for (int j = 0; j < M; j++)printf("%d ", carr[j]);
        printf("\n");
        return;
    }

    int last = 0;
    for (int i = 0; i < N; i++) {
        if (!check[i] && last != arr[i]) {
            last = carr[cur] = arr[i];
            check[i] = 1;
            solve(cur + 1);
            check[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    solve(0);

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