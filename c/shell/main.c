/* Shell */

#include <stdio.h>
#define LSH_RL_BUFSIZE 1024

/* Steps: Initialize -> Interpret -> Terminate */

/* Basic loop of the shell*/
/* Read -> From stdin, Parse: Separate the command string into program and arguments; Execute: run the parsed command. */
char *lsh_read_line(void) {
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
}

void lsh_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = lsh_read_line();
        args = lsh_split_line();
        status = lsh_execute();

        free(line);
        free(args);
    } while (status);
};


int main() {

}