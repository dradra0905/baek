#include <stdio.h>

#define max(x,y) (((x) > (y)) ? (x) : (y))
#define min(x,y) (((x) < (y)) ? (x) : (y))

int Answer;

int N, a, b;
int cnt = 0;

void dp(int n) {
    int small = min(a, b);
    int big = max(a, b);
    if (n % small == 0) {
        cnt += n / small;
        return;
    }
    else {
        cnt++;
        dp(n - big);
    }
}

int main(void)
{
    int T, test_case;
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using scanf function.
       You may remove the comment symbols(//) in the below statement and use it.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */
     // freopen("input.txt", "r", stdin);

     /*
       If you remove the statement below, your program's output may not be recorded
       when your program is terminated after the time limit.
       For safety, please use setbuf(stdout, NULL); statement.
      */
    setbuf(stdout, NULL);

    scanf("%d", &T);
    for (test_case = 0; test_case < T; test_case++)
    {

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
           Implement your algorithm here.
           The answer to the case will be stored in variable Answer.
         */

        scanf("%d %d %d", &N, &a, &b);
        int s = min(a, b);
        cnt = 0;
        dp(N);

        Answer = cnt;


        /////////////////////////////////////////////////////////////////////////////////////////////

              // Print the answer to standard output(screen).

        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);

    }

    return 0;//Your program should return 0 on normal termination.
}