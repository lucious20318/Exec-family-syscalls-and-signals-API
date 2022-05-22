#include<stdio.h>
#include<signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <pthread.h>
#include "e2.c"
	
int main()
{
     struct sigaction sa;
     struct itimerval t;
     sleep(0);
     signal(SIGALRM, sr_ef2);
     
     t.it_value.tv_sec = 0;
     t.it_interval.tv_sec = 0;
     sleep(0);
     t.it_value.tv_usec = 450000;
     t.it_interval.tv_usec = 450000;
     sleep(0);
     t.it_value.tv_usec = 900000;
     t.it_interval.tv_usec = 900000;
     
     setitimer (ITIMER_REAL, &t, NULL);
     while (1);	
}
