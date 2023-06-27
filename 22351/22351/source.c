#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char str[2890];
	scanf("%s", str);
	int len = strlen(str);
	int start = 0;

	if (str[1] - str[0] == 1) {
		if (str[2] - str[1] == 1) {
			//printf("1 1 1\n");
			start = str[0] - 48;
		}
		else if (((str[2] - 48) * 10 + (str[3] - 48)) - (str[1] - 48) == 1) {
			//printf("1 1 2\n");
			start = str[0] - 48;
		}
		else if (len == 2) {
			start = str[0] - 48;
		}
	}
	if (((str[1] - 48) * 10 + (str[2] - 48)) - (str[0] - 48) == 1) {
		if (((str[3] - 48) * 10 + (str[4] - 48)) - ((str[1] - 48) * 10 + (str[2] - 48)) == 1) {
			//printf("1 2 2\n");
			start = str[0] - 48;
		}
		else if (len == 3 && str[0] - 48 == 9) {
			start = str[0] - 48;
		}
	}
	if (((str[2] - 48) * 10 + (str[3] - 48)) - ((str[0] - 48) * 10 + (str[1] - 48)) == 1) {
		if (((str[4] - 48) * 10 + (str[5] - 48)) - ((str[2] - 48) * 10 + (str[3] - 48)) == 1) {
			//printf("2 2 2\n");
			start = ((str[0] - 48) * 10 + (str[1] - 48));
		}
		else if (((str[4] - 48) * 100 + (str[5] - 48) * 10 + (str[6] - 48)) - ((str[2] - 48) * 10 + (str[3] - 48)) == 1) {
			//printf("2 2 3\n");
			start = ((str[0] - 48) * 10 + (str[1] - 48));
		}
		else if (len == 4) {
			start = ((str[0] - 48) * 10 + (str[1] - 48));
		}
	}
	if (((str[2] - 48) * 100 + (str[3] - 48) * 10 + (str[4] - 48)) - ((str[0] - 48) * 10 + (str[1] - 48)) == 1) {
		if (((str[5] - 48) * 100 + (str[6] - 48) * 10 + (str[7] - 48)) - ((str[2] - 48) * 100 + (str[3] - 48) * 10 + (str[4] - 48)) == 1) {
			//printf("2 3 3\n");
			start = ((str[0] - 48) * 10 + (str[1] - 48));
		}
		else if (len == 5 && ((str[0] - 48) * 10 + (str[1] - 48)) == 99) {
			start = ((str[0] - 48) * 10 + (str[1] - 48));
		}
	}
	if (((str[3] - 48) * 100 + (str[4] - 48) * 10 + (str[5] - 48)) - ((str[0] - 48) * 100 + (str[1] - 48) * 10 + (str[2] - 48)) == 1) {
		//printf("3 3 3\n");
		start = ((str[0] - 48) * 100 + (str[1] - 48) * 10 + (str[2] - 48));
	}
	if (start == 0) {
		start = atoi(str);
	}

	char com[2890] = "";
	printf("%d ", start);
	int end = 0;
	for (int i = start; len != strlen(com); i++) {
		char tmp[4];
		sprintf(tmp, "%d", i);
		strcat(com, tmp);
		end = i;
	}

	printf("%d\n", end);
	return 0;
}