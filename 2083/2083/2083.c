#include<stdio.h>

int main() {
	while (1) {
		char s[11];
		int a, w;
		scanf("%s %d %d", s, &a, &w);
		getchar();
		if (s[0] == '#' && !a && !w)break;
		printf("%s ", s);
		if (a > 17 || w >= 80)printf("Senior\n");
		else printf("Junior\n");
	}

	return 0;
}