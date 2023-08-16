#include<stdio.h>

char str[1001];
int n;

int main() {
	scanf("%s", str);
	scanf("%d", &n);
	printf("%c\n", str[n - 1]);

	return 0;
}