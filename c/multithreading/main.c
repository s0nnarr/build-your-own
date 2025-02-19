#include <pthread.h> /* UNIX utility. Try on UNIX machines / use WSL/gcc to compile */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* This explains the concept of multithreading step by step */
/* Part of the code from the OS Course */

int sum; /* This data is shared by the thread(s) */
int prod = 1;


void *runner1(void *param); /* The thread 1 */
void *runner2(void *param); /* The thread 2 */

/* POSIX threads must have the signature: void *function_name(void *arg);*/

int main(int argc, char *argv[]) {
    /* We don't explicitly call main(), but the OS does*/
    /* argc = argument count; argv = argument vector */

    pthread_t tid1, tid2; /* Thread identifier */
    pthread_attr_t attr1, attr2; /* Thread attributes */

    if (argc != 3) {
        fprintf(stderr, "usage: a.out <integer value 1 2>\n");
        return -1;
    };

    if (atoi(argv[1]) < 0) {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    };

    if (atoi(argv[2]) < 0) {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[2]));
        return -1;
    };

    /* Get the default attributes */

    ; pthread_attr_init (&attr1) ;
    ; pthread_attr_init (&attr2) ;
    
    /* Create the thread */

    pthread_create(&tid1, &attr1, runner1, argv[1]);
    pthread_create(&tid2, &attr2, runner2, argv[2]);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("sum = %d\n", sum);
    printf("prod = %d\n", prod);

};

    /* Thread will begin control in this function */
    void *runner1(void *param) {
        int i, upper = atoi(param);
        for (i = 1; i <= upper; i++) {
            sum += i;
        };
        
        pthread_exit(0); 
        /* Exiting thread with status code 0 */
    };

    void *runner2(void *param) {
        int i, n = atoi(param);
        for (i = 1; i <= n; i++) {
            prod *= i;
        };
        sleep(1);
        pthread_exit(0);
    };