#include<stdio.h>
#include<stdlib.h>

int N, M;
int arr[10];
int carr[10];
int check[10001];

int static compare(const void* first, const void* second);

void solve(int n, int cur) {
    carr[cur] = arr[n];
    if (cur == M - 1) {
        for (int j = 0; j < M; j++)printf("%d ", carr[j]);
        printf("\n");
        return;
    }

    check[arr[n]] = 1;
    for (int i = 0; i < N; i++) {
        if (!check[arr[i]])solve(i, cur + 1);
    }
    check[arr[n]] = 0;
}


int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)scanf("%d", &arr[i]);

	qsort(arr, N, sizeof(int), compare);

    for (int i = 0; i < N; i++) {
        solve(i, 0);
    }

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