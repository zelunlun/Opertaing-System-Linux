#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if (pid==0) pid = fork();
	pid = fork();
	while(1);
	return 0;
}
