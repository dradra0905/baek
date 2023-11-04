#include<stdio.h>

int N;
int arr[9], p[9];

void bt(int n) {
	if (n == N) {
		for (int i = 0; i < N; i++)printf("%d ", p[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (arr[i])continue;
		arr[p[n] = i] = 1;
		bt(n + 1);
		p[n] = arr[i] = 0;
	}
}

int main() {
	scanf("%d", &N);
	bt(0);
	return 0;
}