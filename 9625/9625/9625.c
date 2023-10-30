#include<stdio.h>

int K;
int ac[51], bc[51];

int main() {
	scanf("%d", &K);
	ac[0] = ac[2] = bc[1] = bc[2] = 1;
	ac[1] = bc[0] = 0;

	for (int i = 3; i <= K; i++) {
		ac[i] = ac[i - 1] + ac[i - 2];
		bc[i] = bc[i - 1] + bc[i - 2];
	}

	printf("%d %d\n", ac[K], bc[K]);

	return 0;
}