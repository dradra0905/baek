#include<stdio.h>

long long int A, B;
long long int gcd, lcm;

long long int fgcd(int a, int b) {
    long long int tmp, n;

    if (a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main() {
	scanf("%lld %lld", &A, &B);
    printf("%lld\n", (A * B) / fgcd(A, B));
	return 0;
}