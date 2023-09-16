#include<stdio.h>
#include<stdlib.h>

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

	if (abs(arr[tmp]) > abs(command)) {
		arr[cur] = arr[tmp];
		arr[tmp] = command;
		insert(tmp);
	}
	else if (abs(arr[tmp]) == abs(command) && arr[tmp] > command) {
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
	int bigger = abs(arr[cur * 2 + 1]) < abs(arr[cur * 2 + 2]) ? (cur * 2 + 2) : (cur * 2 + 1);
	int smaller;
	if (abs(arr[cur * 2 + 1]) > abs(arr[cur * 2 + 2])) {
		smaller = cur * 2 + 2;
	}
	else if (abs(arr[cur * 2 + 1]) < abs(arr[cur * 2 + 2])) {
		smaller = cur * 2 + 1;
	}
	else if (abs(arr[cur * 2 + 1]) == abs(arr[cur * 2 + 2])) {
		smaller = arr[cur * 2 + 1] > arr[cur * 2 + 2] ? (cur * 2 + 2) : (cur * 2 + 1);
	}

	if (smaller >= idx)smaller = bigger;

	if (abs(arr[smaller]) < abs(arr[cur]) && arr[smaller]) {
		int tmp = arr[cur];
		arr[cur] = arr[smaller];
		arr[smaller] = tmp;
		pop(smaller);
	}
	else if (abs(arr[smaller]) == abs(arr[cur]) && arr[smaller] && arr[smaller] < arr[cur]) {
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