#include<stdio.h>
#include<string.h>

int N, idx = 0;
char num[1000];

int main() {
	scanf("%d", &N);

	while (N) {
		sprintf(num, "%d", idx++);
		if (strstr(num, "666"))N--;
	}

	printf("%d\n", idx - 1);

	return 0;
}