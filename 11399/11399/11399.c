#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second) {
	if (*(int*)first > *(int*)second)return 1;
	else if (*(int*)first < *(int*)second)return -1;
	else return 0;
}

int N;
int line[1001];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &line[i]);

	qsort(line, N, sizeof(int), compare);
	
	int sum = 0, tmp = 0;

	for (int i = 0; i < N; i++) {
		tmp += line[i];
		sum += tmp;
	}

	printf("%d\n", sum);


	return 0;
}