For the first question I created 5 .c files namely e1 ,e2 ,quest2 ,SR ,ST.
The quest2 file is the main file, this is from where the code starts to run. In the main function I created a parent process p1 which is S1
according to the question, then I forked S1 so as to create 2 child processes, ST and SR. As per the question to execute to two processes 
the exec family system call was used. 
For SR and ST, e1 and e2 were created respectively which embodied the code for the creation of the random number and the time elapsed by 
kernel. 

In SR the sr_ef1 function was called which is situated in the file e1.c using SIGALRM signal. Now in that function an object sig_oac was 
created which was then used to store the handler.The random number is generated using the RDRAND instruction in the rd_ function and returned
to my_sigval. All this is added to the queue using sigqueue and from the handler function the random number is printed.
This goes on because of the while(1) instruction.

In ST the sr_ef2 function was called which is situated in the file e2.c using SIGALRM signal. Now in that function an array pointer arr_val
is created which is used to call the rdt_ function to store the random number and the time elapsed value. Similar to SR an object sig_oac 
is created to store handler. Another process p3 is created which is used to add the random value and time elapsed in the sigqueue and 
then using the handler the values are printed.

Now both these processes p2 and p3 go on simultaneously printing the random number and time elapsed until the user interrupts the execution.


       