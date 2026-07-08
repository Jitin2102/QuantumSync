// Safe Concurrent access to shared memory using semaphores
// Four parts in this pipeline 1. shared memory creation 2. semaphore initialization 3. write_safe() 4. read_safe()

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<semaphore.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(){
	key_t key = ftok("combofile",65);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	char *shm = (char *) shmat(shmid,(void *)0,0);

	sem_t *sem = sem_open("/shmsem",O_CREAT,0644,1);
	sem_wait(sem); strcpy(shm,"Safe write with semaphore");
	sem_post(sem);

	sem_wait(sem); printf("Read: %s\n",shm);
	sem_post(sem);

	shmdt(shm);
 	shmctl(shmid,IPC_RMID,NULL);
	sem_close(sem);
	sem_unlink(" /shmsem");
	return 0;
}

