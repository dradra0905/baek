#include<stdio.h>

int N, v;
int arr[201];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int s;
		scanf("%d", &s);
		arr[s + 100]++;
	}
	scanf("%d", &v);
	printf("%d\n", arr[v + 100]);

	return 0;
}