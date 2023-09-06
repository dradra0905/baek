#include<stdio.h>

int N, K, count = 0, idx = 1, tmp;
int arr[1001];

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)arr[i] = i;
	printf("<");
	tmp = N;
	while (tmp > 0) {
		if (arr[idx])count++;
		if (count == K) {
			count = arr[idx] = 0;
			printf("%d", idx);
			if (tmp > 1)printf(", ");
			tmp--;
		}
		idx++;
		if (idx > N)idx = 1;
	}
	printf(">");

	return 0;
}