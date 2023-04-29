#include <stdio.h>
#include <unistd.h>

#define STU_NUMBER "10903027A"

int main()
{
	static int count = 0;
	while(1){
		printf("%s: %d\n", STU_NUMBER, count++);
		sleep(1);
	}
}
