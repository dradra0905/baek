#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);
int N, M;
int arr[10];
int ans[10];

void solve(int n) {
    if (n == M) {
        for (int i = 0; i < M; i++)printf("%d ", ans[i]);
        printf("\n");
        return;
    }

    int before = -1;
    for (int i = 0; i < N; i++) {
        if (n && ans[n - 1] > arr[i])continue;
        ans[n] = arr[i];
        if (before != arr[i])solve(n + 1);
        ans[n] = 0;
        before = arr[i];
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)scanf("%d", &arr[i]);
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