#include<stdio.h>
#include<stdlib.h>

int arr[10], sum = 0, flag = 0, ans[10], idx = -1;
int static compare(const void* first, const void* second);

void solve(int n) {
    if (sum > 100 || idx > 6)return;
    if (sum == 100 && idx==6) {
        flag = 1;
        for (int i = 0; i <= idx; i++)printf("%d\n", ans[i]);
    }

    for (int i = n; i < 9; i++) {
        sum += arr[i];
        ans[++idx] = arr[i];
        solve(i + 1);
        if (flag)break;
        ans[idx--] = 0;
        sum -= arr[i];
    }
}

int main() {
    for (int i = 0; i < 9; i++)scanf("%d", &arr[i]);
    qsort(arr, 9, sizeof(int), compare);
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