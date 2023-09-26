#include<stdio.h>

int arr[10001];
int start = 0;

void self(int n) {
	if (n > 10000)return;
	if (start)arr[n] = 1;
	start = 1;

	int sum = n, tmp = n;
	while (tmp) {
		sum += (tmp%10);
		tmp /= 10;
	}

	if (n == sum)return;
	self(sum);
}

int main() {
	for (int i = 1; i <= 10000; i++) {
		start = 0;
		if (!arr[i]) {
			printf("%d\n", i);
			self(i);
		}
	}

	return 0;
}