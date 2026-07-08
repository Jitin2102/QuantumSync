#include"utils.h"

void sjf(Process p[],int n){
	int completed = 0,time = 0;
	while(completed < n){
		int idx = -1,min = 9999;
		for(int i = 0; i < n;i++){
			if(p[i].arrival <= time && p[i].completion == 0 && p[i].burst < min){
				min = p[i].burst;idx = i;
			}
		}
		if(idx == -1){
			time++;
			continue;
		}
		p[idx].waiting = time - p[idx].arrival;
		time += p[idx].burst;
		p[idx].completion = time;
		p[idx].turnaround = p[idx].completion - p[idx].arrival;
		completed++;
	}
}
