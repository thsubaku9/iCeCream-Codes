#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
sem_t mike;											int data=0,rcount=0;
char qset[3][40]={"Generic Question?","How great are you ?","Can i have your autograph ?"};
void *aud()
	{int b= rand()%10;
	int c=rand()%3;
	c+= rand();
	c=	c%3;
	sem_wait(&mike);
	printf("Audience number %d asked question: %s",b,qset[c]);
	printf("\nAny more questions ?\n");
	sleep(2);
	sem_post(&mike);}

void main(){
	int naudi,i;
	sem_init(&mike,0,1);
    printf("\nEnter Audience number : ");
    scanf("%d", &naudi);
	pthread_t *audi=(pthread_t *)(malloc(sizeof(pthread_t)*naudi));
	for(i=0; i<naudi; i++)		pthread_create(&audi[i],NULL,aud, NULL);
	
	for(i=0; i<naudi; i++)
	{		pthread_join(audi[i],NULL);
}
	printf("Completed");
}


