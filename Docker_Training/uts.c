#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sched.h> //全名是 Scheduler Control Functions 用來控制process調度
#include <signal.h> //include了此header才可以使用`SIGCHLD`
#include <unistd.h> //全名是 Unix Standard Header

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
//    //上面這行是"uts_before.c"之外添加的
//    //而這個sethostname是因為include了`<unistd.h>`才可使用的
        execv(child_args[0], child_args);
            return 1;
            }
//
int main(){
	 printf("程式開始: \n");
/*下面這行是有修改過的 添加了CLONE_NEWUTS
而這個`clone( )`是因為include了`<unistd.h>`、和#define GNU才可使用的*/
	 int child_pid = clone(child_main, child_stack + STACK_SIZE,CLONE_NEWUTS | SIGCHLD, NULL);
	waitpid(child_pid, NULL, 0);
	printf("已退出\n");
	return 0;
}
