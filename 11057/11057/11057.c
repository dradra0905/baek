#include <stdio.h>

int arr[1001][11];
int N;

int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < 10; i++) {
        arr[1][i] = i + 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0)arr[i][j] = 1;
            else {
                arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 10007;
            }
        }
    }
    printf("%d\n", arr[N][9]);

    return 0;
}
