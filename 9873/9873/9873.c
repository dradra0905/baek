#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int arr[1001];
int n;
int count = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 2; j < n; j++) {
            for (int k = i + 1; k < j; k++) {
                if (arr[k] - arr[i] <= arr[j] - arr[k] && 2 * (arr[k] - arr[i]) >= arr[j] - arr[k]) {
                    count++;
                }
            }
        }
    }

    printf("%d\n", count);

	return 0;
}