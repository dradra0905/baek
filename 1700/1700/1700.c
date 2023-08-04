#include <stdio.h>

int arr[101];
int ar[101];
int real[101];
int plug[101];
int check[101];
int change[101];

int main() {
    int N, K;
    int cnt = 0;
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= 100; i++) check[i] = 0, plug[i] = 0, change[i] = 0;
    int rp = 0;
    for (int i = 0; i < K; i++) {
        scanf("%d", &arr[i]);
        if ((i && arr[i] != arr[i - 1]) || !i) {
            real[rp++] = arr[i];
            check[arr[i]]++;
            cnt++;
        }
    }
    K = rp;

    int pcnt = 0, ans = 0;

    while (1) {
        if (pcnt >= cnt)break;
        int e = 0;
        for (int i = 0; i < N; i++) {
            if (real[pcnt] == plug[i]) {
                check[real[pcnt++]]--;
                if (!check[plug[i]]) {
                    plug[i] = 0;
                    change[i] = 1;
                }
                e = 1;
            }
        }
        if (e) continue;

        for (int i = 0; i < N; i++) {
            if (!plug[i] && !change[i]) {
                plug[i] = real[pcnt++];
                check[plug[i]]--;
                if (!check[plug[i]]) {
                    plug[i] = 0;
                    change[i] = 1;
                }
                e = 1;
                break;
            }
        }
        if (e) continue;
        ans++;

        for (int i = 0; i < N; i++)ar[i] = -1;

        int idx = -1, max = -1;
        for (int i = 0; i < N; i++) {
            if (!plug[i]) {
                idx = i;
                break;
            }
            for (int j = pcnt; j < K; j++) {
                if (plug[i] == real[j]) {
                    ar[i] = j;
                    break;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (ar[i] == -1){
                idx = i;
                break;
            }
            else {
                if (max <= ar[i]) {
                    max = ar[i];
                    idx = i;
                }
            }
        }

        plug[idx] = real[pcnt++];
        check[plug[idx]]--;
        if (!check[plug[idx]]) {
            plug[idx] = 0;
            change[idx] = 1;
        }

    }

    printf("%d\n", ans);

    return 0;
}