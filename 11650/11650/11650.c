#include<stdio.h>
#include<stdlib.h>

typedef struct coordinate {
	int x;
	int y;
}coordinate;

int N;
coordinate co[100001];

int static compare(const void* first, const void* second);

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d %d", &co[i].x, &co[i].y);

	qsort(co, N, sizeof(coordinate), compare);

	for (int i = 0; i < N; i++)printf("%d %d\n", co[i].x, co[i].y);

	return 0;
}

int static compare(const void* first, const void* second) {
	if (((coordinate*)first)->x == ((coordinate*)second)->x)return ((coordinate*)first)->y - ((coordinate*)second)->y;
	return ((coordinate*)first)->x - ((coordinate*)second)->x;
}