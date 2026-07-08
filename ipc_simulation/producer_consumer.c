//Producer Consumer Problem 
// Synchronize buffer access using semaphores
// It is a classical synchronizzation problem 
// we have three semaphores here 1. mutex -> ensures mutual exclusion
//2. full -> how many instances of resources are available currently for consumer
//3. empty-> how many instances of resources are available  for producer

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define SIZE 5
int buffer[SIZE],in = 0,out = 0;
sem_t empty,full,mutex;

void *producer(void *arg){
	for(int i = 0;i < 10;i++){
		sem_wait(&empty);
		sem_wait(&mutex);
		buffer[in] = i;
		printf("Produced %d\n",i);
		in  = (in + 1) % SIZE;
		sem_post(&mutex);
		sem_post(&full);
	}
	return NULL;
}

void *consumer(void * arg){
	for(int i = 0;i < 10;i++){
		sem_wait(&full);
		sem_wait(&mutex);
		int item = buffer[out];
		printf("Consumed %d\n",item);
		out = (out + 1)% SIZE;
		sem_post(&mutex);
		sem_post(&empty);
	}
	return NULL;
}

int main(){
	pthread_t p,c;
	sem_init(&empty,0,SIZE);
	sem_init(&full,0,0);
	sem_init(&mutex,0,1);
	
	pthread_create(&p,NULL,producer,NULL);
	pthread_create(&c,NULL,consumer,NULL);
	
	pthread_join(p,NULL);
	pthread_join(c,NULL);
	
	return 0;
}
