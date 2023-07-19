#include<stdio.h>

long long int p(int a, int b, int c) {
	if (b == 1)return a % c;
	long long int v = p(a, b / 2, c);
	v = v * v % c;
	if (b % 2 == 1)v = v * a % c;
	return v;
}


int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	printf("%lld\n", p(a, b, c));



	return 0;
}