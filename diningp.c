#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int n;
pthread_mutex_t mutex;
sem_t *s;
pthread_t *p;
int *state;
int *phil_num;

void *philosopher(int *num);
void take_fork(int ph_num);
void test(int ph_num);
void put_fork(int ph_num);

int main()
{int i;
scanf("%d",&n);
s=(sem_t *)malloc(sizeof(sem_t)*n);
p=(pthread_t *)malloc(sizeof(pthread_t)*n);
state=(int *)malloc(sizeof(int)*n);
phil_num=(int *)malloc(sizeof(int)*n);
pthread_mutex_init(&mutex,NULL);
for(i=0;i<n;i++)
{phil_num[i]=i;
sem_init(&s[i],0,0);
pthread_create(&p[i],NULL,philosopher,&phil_num[i]);
printf("\nPhilosopher %d is thinking",phil_num[i]);
}
for(i=0;i<n;i++)
{pthread_join(p[i],NULL);}
}

void *philosopher(int *num)
{int *j=num;
sleep(1);
take_fork(*j);
sleep(0);
put_fork(*j);
return NULL;}

void take_fork(int ph_num)
{pthread_mutex_lock(&mutex);
state[ph_num]=1;
test(ph_num);
pthread_mutex_unlock(&mutex);
sem_wait(&s[ph_num]);sleep(1);
}

void put_fork(int ph_num)
{pthread_mutex_lock(&mutex);
state[ph_num]=0;
test((ph_num+n-1)%n);
test((ph_num+1)%n);
pthread_mutex_unlock(&mutex);
}

void test(int ph_num)
{
if(state[ph_num]==1 && state[(ph_num+n-1)%n]!=2 && state[(ph_num+1)%n]!=2)
{state[ph_num]=0;sleep(2);
printf("Philosopher %d is eating",ph_num+1);
sem_post(&s[ph_num]);
}
}


