//Two processes exchange messages via shared memory.
//create_shared_memory() ->  done by shmget
//write_messages() -> writes to shared memory
//read_messages() -> reads from shared memory 

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

int create_shared_memory(key_t key,int size){
	return shmget(key,size,0666 | IPC_CREAT);
}

void write_message(char *shm,const char*msg){
	strcpy(shm, msg);
}

void read_message(char *shm){
	printf("Message: %s\n",shm);
}


int main(){
	key_t key =  ftok("chatfile",65);
	int shmid = create_shared_memory(key,1024);
	char *shm = (char*) shmat(shmid,(void*)0,0);
	write_message(shm,"Hello from Process 1");
	read_message(shm);

	shmdt(shm);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}

