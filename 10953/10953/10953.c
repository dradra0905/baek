#include<stdio.h>

int T;
char s[5];

int main() {
	scanf("%d", &T);
	while (T--) {
		getchar();
		scanf("%s", s);
		printf("%d\n", (s[0] - '0' + s[2] - '0'));
	}
	return 0;
}