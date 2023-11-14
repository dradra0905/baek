#include<stdio.h>

int N, f;

int main() {
	scanf("%d", &N);
	scanf("%d", &f);
	N--;

	while (N--) {
		int a;
		scanf("%d", &a);
		int tmp = f, tmp2 = a;
		while (tmp != tmp2)
		{
			if (tmp > tmp2)
				tmp -= tmp2;
			else
				tmp2 -= tmp;
		}

		printf("%d/%d\n", f / tmp, a / tmp);
	}


	return 0;
}