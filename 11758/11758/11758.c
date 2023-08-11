#include<stdio.h>

int main() {
	int x1, x2, x3, y1, y2, y3;
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);

	int temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp = temp - y1 * x2 - y2 * x3 - y3 * x1;

	if (temp > 0)printf("1\n");
	else if (temp < 0)printf("-1\n");
	else printf("0\n");

	return 0;
}