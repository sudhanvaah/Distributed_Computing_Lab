#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
void *thread_func(void *arg);
thread_mutex_t_work_mutex;
#define work_size 1024
char work_area(work_size);
int time_to_exit();
int main()
{
int res;
pthread=t;
a=thread;
void *thread_result;
res=pthread_mutex_unit(&work_mutex,null);
if(res!=0)
MKS | IS722L Distributed Computing Lab (0:0:1) 10‐10‐2016 32
{
perror("mutex initialization failed");
exit(exit_failure);
} res=pthread_create(&a_thread,null,thread function,null);
if(res!=0)
{
perror("thread creation failure");
exit(exit_failure);
}
pthrad_mutex_lock(&work_mutex);
printf("input some text,end to finish \n");
while(!time_to_exit)
{
fgets(work_area,work_size,stdin);
pthread_mutex_unlock(&work_mutex);
while(1)
}{
pthread_mutex-lock(&work_mutex);
if(work_area[0]!='\0')
{
pthread_mutex_unlock(&work_mutex);
sleep(1);
}
else
{
break;
}
}
pthread_mutex_unlock(&work_mutex);
printf("\n waiting for thread to finish...");
res=pthread_join(a_thread.thread_result);
if(res!=0)
{
perror("thread join failed");
exit(exit failure);
}
printf("thread joined");
pthread_mutex_destroy(&work_mutex);
exit(exit success);
}
void *thread_function(void *arg)
{
sleep(1);
pthread_mutex_lock(&work_mutex);
while stramp("end",work_aarea,39!=0)
{
printf("you input %d char \n",strlen(work_area,-1);
work_area[0]='\0';
pthread_mutex_unlock(&work_mutex);
sleep(1);
thread_mutex_lock(&work_mutex);
}
while(work-area[0]=='\0')
MKS | IS722L Distributed Computing Lab (0:0:1) 10‐10‐2016 33
{
pthread_mutex_unlock(&work_mutex);
sleep(1);
pthread_mutex_lock(&work_mutex);
}
}
