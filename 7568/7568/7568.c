#include<stdio.h>

typedef struct person {
	int height;
	int weight;
	int check;
}person;
person p[51];
int N;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d %d", &p[i].weight, &p[i].height), p[i].check = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (p[i].height < p[j].height && p[i].weight < p[j].weight) {
				p[i].check++;
			}
		}

	}

	for (int i = 0; i < N; i++)printf("%d ", p[i].check);
	return 0;
}