#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);
int N, ar[5001];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        ar[i] = a * 10000 + b * 100 + c;
    }
    qsort(ar, N, sizeof(int), compare);

    for (int i = 0; i < N; i++) {
        int a = ar[i] / 10000;
        int b = (ar[i] - a * 10000) / 100;
        int c = (ar[i] - a * 10000 - b * 100);
        printf("%d %d %d\n",a,b,c);
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
