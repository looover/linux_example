#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void * thread_test0(void* arg)
{
	unsigned int pid = getpid();
	printf("pid=%d:%s start!\n", pid, __func__);
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	//pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
	//pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	while(1)
	{
		printf("pid=%d:%s:\n", pid, __func__);
		sleep(1);

		//static int cnt = 0;
		//if(cnt++ == 3){
		//	exit(0);
		//}
	}
	printf("pid=%d:%s exit!\n", pid, __func__);
}

void main(int argc, char** argv)
{
	
	pthread_t thrd0;
	pthread_create(&thrd0, NULL, thread_test0, NULL);

	sleep(5);

	printf("cancel thrd0\n");
	pthread_cancel(thrd0);

	//sleep(5);
	//pthread_testcancel();

	sleep(3);
	pthread_join(thrd0, NULL);
	printf("exit!\n");
}
