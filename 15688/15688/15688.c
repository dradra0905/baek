#include<stdio.h>

int N;
int arr[2000001];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		arr[n + 1000000]++;
	}

	for (int i = 0; i <= 2000000; i++) {
		while (arr[i]--)printf("%d\n", i-1000000);
	}

	return 0;
}