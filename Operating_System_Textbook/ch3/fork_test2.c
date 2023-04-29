#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define STU_NUMBER  "10903027A" //改成你的學號

int main()
{
    pid_t pid;

    printf("Student number: %s\n", STU_NUMBER);

    /* fork a child process */
    pid = fork();

    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0) { /* child process */
	for(int i=0;i<1000;i++) {
            printf("Child: %d\n", i);
        }
    }
    else { /* parent process */
        for(int i=0;i<1000;i++) {
            printf("Main: %d\n", i);
        }
        wait(NULL);
    }
    
    return 0;
}

