#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<linux/kernel.h>
#include<signal.h>
#include<pthread.h>

int main()
{
    char *x[]={"./first",NULL};
    char *y[]={"./sec",NULL};
    
    pid_t p1 = fork();
    
    if (p1 == 0)
        execv(x[0],x);
    else
        execv(y[0],y);
        
    return 0;
}

