#ifndef UTILS_H
#define UTILS_H

typedef struct{
	int pid,arrival,burst,waiting,turnaround,completion,priority;
} Process;

void print_table(Process p[],int n);
void print_avg(Process p[],int n);

#endif

