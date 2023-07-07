#include <stdio.h>

int main() {
	int degree = 0;
	for (int i = 0; i < 10; i++) {
		int n;
		scanf("%d", &n);
		if (n == 1)degree += 90;
		else if (n == 2)degree += 180;
		else if (n == 3)degree += 270;
	}
	degree /= 90;
	degree %= 4;
	if (degree == 0)printf("N\n");
	else if (degree == 1)printf("E\n");
	else if (degree == 2)printf("S\n");
	else if (degree == 3)printf("W\n");

	return 0;
}