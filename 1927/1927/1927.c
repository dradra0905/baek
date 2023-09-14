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

	if (arr[tmp] > command) {
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

	if (arr[smaller] <= 0)smaller = bigger;

	if (arr[smaller] < arr[cur] && arr[smaller]) {
		int tmp = arr[cur];
		arr[cur] = arr[smaller];
		arr[smaller] = tmp;
		pop(smaller);
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