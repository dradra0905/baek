#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);

int N, M;
int arr[15001];

int ans = 0;

int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < N; i++)scanf("%d", &arr[i]);
    qsort(arr, N, sizeof(int), compare);

    int tmp = N - 1;
    int front = 0, back = tmp;
    while (front < back) {
        if (arr[front] + arr[back] == M) {
            ans++;
            front++;
            back--;
            tmp = back;
        }
        else if (arr[front] + arr[back] < M) {
            front++;
            back = tmp;
        }
        else back--;
    }

    printf("%d\n", ans);

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
