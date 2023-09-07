#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);
int N, index = 0;
int arr[10001];
int check[10001];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int d;
		scanf("%d", &d);
		if (!arr[d])check[index++] = d;
		arr[d]++;
	}
	qsort(check, index, sizeof(int), compare);

	while (1) {
		if (!arr[check[index]])index--;
		if (index < 0)break;
		arr[check[index]]--;
		printf("%d\n", check[index]);
	}
	
	return 0;
}

int static compare(const void* first, const void* second) {
	return (*(int*)second) - (*(int*)first);
}