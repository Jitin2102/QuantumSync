#include"utils.h"

void priority(Process p[],int n){
	int completed = 0,time = 0;
	int rem[n];
	for(int i = 0 ;i < n;i++){
		rem[i] = p[i].burst ;
		p[i].completion = 0;
		p[i].waiting = 0;
		p[i].turnaround = 0;
	}
	while(completed < n){
		int idx = -1,max = -1;
		for(int  i = 0 ; i < n;i++){
			if(p[i].arrival <= time && rem[i]> 0 && p[i].priority > max){
				max = p[i].priority;
				idx = i;
			}
		}
		if(idx == -1){
                        time++;
                        continue;
                }
		rem[idx]--;
		time++;
		if(rem[idx] == 0){
                	p[idx].completion = time;
                	p[idx].turnaround = p[idx].completion - p[idx].arrival;
			p[idx].waiting = p[idx].turnaround - p[idx].burst;
                	completed++;
		}
	}
}
