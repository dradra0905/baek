#include<stdio.h>
#include<math.h>

void hanoi(int start, int end, int n) {
	if (n == 1) {
		printf("%d %d\n", start, end);
		return;
	}
	hanoi(start, 6 - start - end, n - 1);
	printf("%d %d\n", start, end);
	hanoi(6 - start - end, end, n - 1);
}


int main() {
	int n;
	scanf("%d", &n);

	printf("%d\n", (int)pow(2, n) - 1);
	hanoi(1, 3, n);

	return 0;
}