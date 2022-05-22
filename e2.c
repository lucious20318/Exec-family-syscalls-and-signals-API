#include<stdio.h>
#include<signal.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
#include<pthread.h>
#include<linux/kernel.h>

int *rdt_()
{
    static int ret[2];
    unsigned lower,higher;
    asm volatile("rdtsc":"=a"(lower), "=d"(higher):);

    for(int i=0; i<2; i++)
    {
	if(i == 0)
	{
	     ret[i] = lower;
	}
	
	else
	{
	     ret[i] = higher;
	}
    }
      
    return ret;
}

void handler(int signo, siginfo_t *info,void *ctx)
{
  if(info->si_value.sival_int < 100000 && info->si_value.sival_int > 0)
  {
  	printf("Time elapsed - %d\n",info->si_value.sival_int);
  }
  else
  {
  	printf("Random Number- %d\n",info->si_value.sival_int);
  }
}

void sr_ef2(int signum)
{
   //int temp[2];
   int *arr_val = rdt_();
   
   struct sigaction sig_oac;
   sig_oac.sa_sigaction = handler;
   
   sigemptyset(&sig_oac.sa_mask);
   sig_oac.sa_flags = SA_SIGINFO;
   sigaction(SIGTERM ,&sig_oac,NULL);
    
   pid_t p3 = getpid();
   union sigval my_sigval;
   
   my_sigval.sival_int = arr_val[0];
   sigqueue(p3, SIGTERM, my_sigval);
  
   my_sigval.sival_int = arr_val[1];
   sigqueue(p3, SIGTERM, my_sigval);
}
