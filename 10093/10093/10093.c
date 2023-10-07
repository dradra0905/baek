#include<stdio.h>

int main() {
	long long int a, b;
	scanf("%lld %lld", &a, &b);

	long long int big, small;
	if (a > b)big = a, small = b;
	else big = b, small = a;

	if (big-small==1 || big == small) {
		printf("0\n");
		return 0;
	}
	printf("%lld\n", big - small - 1);
	for (long long int i = small + 1; i < big; i++)printf("%lld ", i);

	return 0;
}