#include"utils.h"

void fcfs(Process p[],int n){
	int time = 0;
	for(int i = 0;i < n;i++){
		if(time < p[i].arrival) time = p[i].arrival;
		p[i].waiting = time - p[i].arrival;
		time += p[i].burst;
		p[i].completion = time;
		p[i].turnaround = p[i].completion - p[i].arrival;
	}
}

