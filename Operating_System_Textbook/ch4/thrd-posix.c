/**
 * A pthread program illustrating how to
 * create a simple thread and some of the pthread API
 * This program implements the summation function where
 * the summation operation is run as a separate thread.
 *
 * Most Unix/Linux/OS X users
 * gcc thrd.c -lpthread
 *
 * Figure 4.11
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts  - Tenth Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; /* this data is shared by the thread(s) */

void *runner(void *param); /* the thread */

int main(int argc, char *argv[])
{
pthread_t tid1, tid2; /* the thread identifier */
pthread_attr_t attr; /* set of attributes for the thread */

if (argc != 2) {
	fprintf(stderr,"usage: a.out <integer value>\n");
	/*exit(1);*/
	return -1;
}

if (atoi(argv[1]) < 0) {
	fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));
	/*exit(1);*/
	return -1;
}
//sum = 0;
/* get the default attributesi 先做初始化 */
pthread_attr_init(&attr);

/* create the thread 創建thread*/
pthread_create(&tid1,&attr,runner,argv[1]);
pthread_create(&tid2,&attr,runner,argv[1] );

/* now wait for the thread to exit */
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);

printf("sum = %d\n",sum);
}

/**
 * The thread will begin control in this function
 */
void *runner(void *param) 
{
int i, upper = atoi(param); /*這裡的param 就是外面執行檔案代的參數*/
sum = 0;

	if (upper > 0) {
		for (i = 1; i <= upper; i++)
			sum += i;
	}
/*如果這邊在加一個迴圈或其他的, 目的是讓這個程式變慢, 而因為thread會因為ContextSwitch
而讓thread1 跟 thread2都有跑到, 如果太快的話就像是單獨跑*/
	pthread_exit(0);
}
