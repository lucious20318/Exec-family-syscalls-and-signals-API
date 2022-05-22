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

int rd_()
{
    int xyx;
    asm ("RDRAND %0\n\t" "add $0, %0": "=r" (xyx): "r" (1));
    return xyx;
}

void handler(int signo, siginfo_t *info,void *ctx)
{
    printf("Random number- %d\n ",info->si_value.sival_int);
}

void sr_ef1(int signum)
{   
    struct sigaction sig_oac;
    sig_oac.sa_sigaction = handler;
    
    sigemptyset(&sig_oac.sa_mask);
    sig_oac.sa_flags = SA_SIGINFO;
    sigaction(SIGTERM ,&sig_oac,NULL);
  
    pid_t p2 = getpid();
    union sigval my_sigval;
    my_sigval.sival_int = rd_();
    
    sigqueue(p2, SIGTERM, my_sigval); 
}
