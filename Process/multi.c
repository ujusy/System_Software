//  file A, B, C, D의 내용을 읽고 파일들에 있는 숫자들의 총합계를 계산하려고 한다.
// (1) 프로세스 한 개가 이를 모두 수행하는 경우와 
// (2) 여러 개의 프로세스가 한 파일씩 담당하여 동시에 수행하고, 
// 나중에 한 프로세스가 이를 모으는 방법이 있다. 
// 어느 방법으로 수행하는 것이 빠른지 구현하고 실험적으로 비교하려고 한다. 

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/times.h>
#include <limits.h>


int main() {
    int N = 4;
    pid_t pid[N]; 
    int childStatus;
    int i;
    FILE * A, * B, * C, * D;
    int a = 0, b = 0;
    double duration;
    int sum = 0;
    clock_t start, finish;
    start = clock();
    for (i = 0; i < N; i++) {
        pid[i] = fork();
        if (pid[i] == 0) {
            if (i == 0) {
                if ((A = fopen("A.txt", "r")) == NULL) {
                    perror("fopen: 오류");
                    exit(1);
                }
                while ((a = fscanf(A, "%d", & b)) != EOF) {
                    sum += b;
                }
                fclose(A);
                return sum;
            }
            if (i == 1) {
                if ((B = fopen("B.txt", "r")) == NULL) {
                    perror("fopen: 오류");
                    exit(1);
                }
                while ((a = fscanf(B, "%d", & b)) != EOF) {
                    sum += b;
                }
                fclose(B);
                return sum;
            }
            if (i == 2) {
                if ((C = fopen("C.txt", "r")) == NULL) {
                    perror("fopen: 오류");
                    exit(1);
                }
                while ((a = fscanf(C, "%d", & b)) != EOF) {
                    sum += b;
                }
                fclose(C);
                return sum;
            }
            if (i == 3) {
                if ((D = fopen("D.txt", "r")) == NULL) {
                    perror("fopen: 오류");
                    exit(1);
                }
                while ((a = fscanf(D, "%d", & b)) != EOF) {
                    sum += b;
                }
                fclose(D);
                return sum;
            }
            exit(100 + i);
        }
        
    }

    for (i = 0; i < N; i++) {
        pid_t terminatedChild = wait( & childStatus);

        if (WIFEXITED(childStatus)) {
            sum += WEXITSTATUS(childStatus);
            
        } else
            printf("Child %d has terminated abnormally\n", terminatedChild);
    }
    finish = clock();
    printf("숫자들의 총합은 : %d 입니다!\n", sum);
    duration = ((double) (finish-start)/CLOCKS_PER_SEC);
    printf("%f 초입니다\n", duration);
    return 0;

}