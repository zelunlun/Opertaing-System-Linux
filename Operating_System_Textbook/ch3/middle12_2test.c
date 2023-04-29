#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define STU_NUMBER  "10903027A" //改成你的學號

int main()
{
    pid_t pid;

    

    /* fork a child process */
    pid = fork();

    if (pid == 0) { /* child process */
	pid = fork();
	if (pid == 0) {
		wait(NULL);
		printf("A");
	}
        else {
		printf("B");
	}
        
    }
    else { /* parent process */
	wait(NULL);
	printf("C");
    }

    return 0;
}
