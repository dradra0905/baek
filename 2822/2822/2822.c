#include<stdio.h>
#include<stdlib.h>

int static compare(const void* first, const void* second);
int static compare2(const void* first, const void* second);

typedef struct problem {
	int idx;
	int score;
}pr;

pr p[10];
int rank[5];

int main() {
	for (int i = 0; i < 8; i++) {
		int a;
		scanf("%d", &a);
		p[i].idx = i + 1;
		p[i].score = a;
	}

	int ans = 0;
	qsort(p, 8, sizeof(pr), compare);
	for (int i = 3; i < 8; i++) {
		ans += p[i].score;
		rank[i - 3] = p[i].idx;
	}
	printf("%d\n", ans);

	qsort(rank, 5, sizeof(int), compare2);
	for (int i = 0; i < 5; i++) {
		printf("%d ", rank[i]);
	}
	printf("\n");

	return 0;
}

int static compare(const void* first, const void* second)
{
	return ((pr*)first)->score - ((pr*)second)->score;
}
int static compare2(const void* first, const void* second)
{
	return ((pr*)first)->idx - ((pr*)second)->idx;
}