#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);

int n, x;
int arr[100010];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), compare);
    
    scanf("%d", &x);

    int count = 0;
    int front = 0, end = n-1;
    while (front < end) {
        if (arr[front] + arr[end] == x)count++, front++;
        else if (arr[front] + arr[end] > x)end--;
        else if (arr[front] + arr[end] < x)front++;
    }
    printf("%d\n", count);

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