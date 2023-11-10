#include<stdio.h>

int n, m;

int main() {
	scanf("%d:%d", &n, &m);

	int gcd = 0;

    for (int i = 1; i <= n && i <= m; ++i)
    {
        if (n % i == 0 && m % i == 0)
            gcd = i;
    }

    printf("%d:%d\n", n / gcd, m / gcd);

	return 0;
}