#include<stdio.h>
#include<stdlib.h>
#include"utils.h"

extern void fcfs(Process p[],int n);
extern void sjf(Process p[],int n);
extern void priority(Process p[],int n);
extern void round_robbin(Process p[],int n,int quantum);

int main(){
	int n ,choice,quantum;
	printf("Enter no. of processes: ");
	scanf("%d",&n);
	Process p[n];
	for(int  i = 0; i < n;i++){
		p[i].pid = i + 1;
		printf("Arrival & Burst Times for P%d : ",i+1);
		scanf("%d %d",&p[i].arrival,&p[i].burst);
		printf("Priority for P%d: ",i+1);
		scanf("%d",&p[i].priority);


		p[i].waiting = 0;
		p[i].turnaround = 0;
		p[i].completion = 0;
	}

	printf("\nChoose Algorithm:\n1.FCFS\n2.SJF\n3.Priority\n4.Round Robbin\n");
	scanf("%d",&choice);
	switch(choice){
		case 1: fcfs(p,n);break;
		case 2: sjf(p,n);break;
		case 3: priority(p,n);break;
		case 4:
		  printf("Enter time quantum: ");
		  scanf("%d",&quantum);
		  round_robbin(p,n,quantum);
		  break;
		default: printf("Invalid Choice\n");
	}
	print_table(p,n);
	print_avg(p,n);
	return 0;
}
