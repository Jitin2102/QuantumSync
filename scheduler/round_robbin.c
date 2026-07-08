#include"utils.h"

void  round_robbin(Process p[],int n,int quantum){
	int time = 0,completed = 0;
	int rem[n];
	for(int i = 0; i < n;i++){
		rem[i] = p[i].burst;
		p[i].completion  = 0;
	}
	while(completed < n){
		int idle = 1;
		for(int i = 0;i < n;i++){
			if(p[i].arrival <= time && rem[i] > 0){
				idle = 0;
				if(rem[i]> quantum) {
					time+= quantum;
					rem[i] -= quantum;
				}
				else{
				     time+= rem[i];
				     rem[i] = 0;
                		     p[i].completion = time;
                		     p[i].turnaround = p[i].completion - p[i].arrival;
			             p[i].waiting = p[i].turnaround - p[i].burst;
                		     completed++;
				}
			}
		}
		if(idle) time++;
	}
}
