#include<stdio.h>
#include<math.h>

int main() {
	int n, k, w;
	double p;
	scanf("%d %d %lf %d", &n, &k, &p, &w);
	double result = p / (double)w;

	printf("%d\n", (int)ceil(result));

	return 0;
}