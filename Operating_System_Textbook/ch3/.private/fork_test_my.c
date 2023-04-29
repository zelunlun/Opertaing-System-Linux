#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define STU_NUMBER  "10903027A" //改成你的學號

int main()
{
pid_t pid, pid2;

    printf("Student number: %s\n", STU_NUMBER);

    /* fork a child process */
    pid = fork();

    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0) { /* child process */
        pid2 = fork();
	wait(NULL);
	if (pid2 < 0){
			return 1;
		}
	else if (pid2 == 0){
			printf("Child2: I am the child, my pid = %d\n", getpid());
			printf("Child2: my parent pid = %d\n", getpid());
			execlp("/bin/date", "date", NULL);
		}
	printf("Child: I am the child, my pid = %d\n",getpid());
        printf("Child: my parent pid = %d\n", getppid());
        execlp("/bin/ls","ls",NULL);
    }
    else { /* parent process */
        /* parent will wait for the child to complete */
        sleep(1);
	printf("Main: My pid = %d\n",getpid());
        printf("Main: I have a new child whose pid = %d\n",pid);
        wait(NULL);
        
       // printf("Child Complete\n");
    }

    printf("Child Complete\n");
    // while (1);
    return 0;
}

