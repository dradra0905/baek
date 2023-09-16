#include<stdio.h>

int N, command, idx = 0;
int arr[200010];

void insert(int cur) {
	int tmp;

	if (cur == 0) {
		if (!arr[cur])arr[cur] = command;
		return;
	}

	if (cur % 2 == 0)tmp = (cur - 2) / 2;
	else tmp = (cur - 1) / 2;

	if (arr[tmp] < command) {
		arr[cur] = arr[tmp];
		arr[tmp] = command;
		insert(tmp);
	}
	else {
		arr[cur] = command;
	}
}

void pop(int cur) {
	if (!arr[cur])return;
	int smaller = arr[cur * 2 + 1] > arr[cur * 2 + 2] ? (cur * 2 + 2) : (cur * 2 + 1);
	int bigger = arr[cur * 2 + 1] < arr[cur * 2 + 2] ? (cur * 2 + 2) : (cur * 2 + 1);

	if(bigger > idx)bigger = smaller;

	if (arr[bigger] > arr[cur] && arr[bigger]) {
		int tmp = arr[cur];
		arr[cur] = arr[bigger];
		arr[bigger] = tmp;
		pop(bigger);
	}

}

int main() {
	scanf("%d", &N);

	while (N--) {
		scanf("%d", &command);
		if (command) {
			insert(idx++);
		}
		else {
			printf("%d\n", arr[0]);
			if (idx) {
				arr[0] = arr[--idx];
				arr[idx] = 0;
			}
			pop(0);
		}
	}

	return 0;
}