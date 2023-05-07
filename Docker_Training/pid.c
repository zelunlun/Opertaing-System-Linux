


#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sched.h>
#include <signal.h>
#include <unistd.h>

#define STACK_SIZE (1024 * 1024)


static char child_stack[STACK_SIZE];
char* const child_args[]={
	"/bin/bash",
	NULL
};

int child_main(void* args){
	printf("在child process中!\n");
//
	sethostname("NewNamespace", 12);
//上面這行是"uts_before.c"之外添加的
	execv(child_args[0], child_args);
	return 1;
}

int main(){
	printf("程式開始: \n");
//下面這行是有修改過的 添加了CLONE_NEWUTS
	int child_pid = clone(child_main, child_stack + STACK_SIZE, CLONE_NEWPID | CLONE_NEWIPC | CLONE_NEWUTS | SIGCHLD, NULL);
//
	waitpid(child_pid, NULL, 0);
	printf("已退出\n");
	return 0;
}
