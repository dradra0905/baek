#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		char p[100001], x[300000];
		int arr[100001], ac = 0;

		getchar();
		
		scanf("%s", p);

		int n;
		scanf("%d", &n);

		getchar();
		scanf("%s", x);

		int len = strlen(x);

		char num[4]= "";
		int count = 0;
		for (int i = 0; i < len; i++) {

			if (x[i] >= '0' && x[i] <= '9') {
				num[count] = x[i];
				count++;
			}
			else if (count) {
				arr[ac++] = atoi(num);
				for (int j = 0; j < count; j++)num[j] = '\0';
				count = 0;
			}
		}

		int command_len = strlen(p);
		bool check = false;
		int top = 0, tmp = ac;
		for (int i = 0; i < command_len; i++) {
			if (p[i] == 'R') {
				check = !check;
			}
			else if (p[i] == 'D') {
				if (check) {
					arr[--ac] = 0;
				}
				else {
					arr[top++] = 0;
				}
			}
		}

		if (top > ac)printf("error\n");
		else if (top == ac)printf("[]\n");
		else {

			if (check) {
				printf("[%d", arr[--ac]);
				for (int i = ac - 1; i >= top; i--) {
					printf(",%d", arr[i]);
				}
				printf("]\n");
			}
			else {
				printf("[%d", arr[top]);
				for (int i = top + 1; i < ac; i++) {
					printf(",%d", arr[i]);
				}
				printf("]\n");
			}
		}


		for (int i = 0; i < tmp; i++) {
			arr[i] = 0;
		}
		ac = 0;

	}

	return 0;
}