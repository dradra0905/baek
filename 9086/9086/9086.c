#include<stdio.h>
#include<string.h>

int T;
char s[1001];

int main() {
	scanf("%d", &T);
	while (T--) {
		getchar();
		scanf("%s", s);
		printf("%c%c\n", s[0], s[strlen(s) - 1]);
	}

	return 0;
}