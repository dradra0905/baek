#include<stdio.h>
#include<stdlib.h>

int N, P, score;
int scores[51];

int main() {
	scanf("%d %d %d", &N, &score, &P);

	int rank = 1, plus = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &scores[i]);
		if (scores[i] > score)rank++;
		else if (scores[i] == score)plus++;
	}

	if (rank <= P) {
		if (rank + plus <= P)printf("%d\n", rank);
		else printf("-1\n");
	}
	else printf("-1\n");

	return 0;
}