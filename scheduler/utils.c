#include<stdio.h>
#include"utils.h"

void print_table(Process p[],int n){
	printf("\nPID\tAT\tBT\tPR\tWT\tTAT\tCT\n");
	for(int i = 0;i < n; i++){
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrival,p[i].burst,p[i].priority,
			p[i].waiting,p[i].turnaround,p[i].completion);
	}
}

void print_avg(Process p[],int n){
	float avg_wt = 0,avg_tat = 0;
	for(int i = 0 ;i < n;i++){
		avg_wt += p[i].waiting;
		avg_tat += p[i].turnaround;
	}
	printf("\nAverage Waiting Time: %.2f",avg_wt/n);
	printf("\nAverage Turnaround Time: %.2f\n",avg_tat/n);
}
