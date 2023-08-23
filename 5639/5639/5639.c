#include<stdio.h>

int tree[10001];

void search(int start, int end) {
	if (start >= end)return;

	int i;
	for (i = start + 1; i < end; i++) {
		if (tree[start] < tree[i])break;
	}

	search(start + 1, i);
	search(i, end);
	printf("%d\n", tree[start]);
}

int main() {
	int n, index = 0;

	while (scanf("%d", &n) != EOF) {
		tree[index++] = n;
	}
	search(0, index);

	return 0;
}