#include<stdio.h>
#include<pthread.h>
int arrival_time1[30],arrival_time2[30],arrival_time3[30];
int burst_time1[30],burst_time2[30],burst_time3[30];
int n,i,at[30],bt[30],p[30],j=0,k=0,l=0;
int time_quantum1,time_quantum2;
int total,x,temp[30],counter=0;

void *round_robin()
{
	printf("Enter Time Quantum for Queue1:"); 
    scanf("%d",&time_quantum2);
	for(i=0;i<j;i++)
	{
		temp[i]=burst_time1[i];
	} 
	printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
	x=j;
    for(total=0,i=0;x!=0;) 
    { 
    	if(temp[i] <= time_quantum2 && temp[i] > 0) 
        { 
            total = total + temp[i]; 
            temp[i] = 0; 
            counter = 1; 
        } 
        else if(temp[i] > 0) 
        { 
            temp[i] = temp[i] - time_quantum2; 
            total = total + time_quantum2; 
        } 
        if(temp[i] == 0 && counter == 1) 
        { 
            x--; 
            printf("\nProcess[%d]\t%d\t%d\t%d", i + 1, burst_time1[i], total - arrival_time1[i], total - arrival_time1[i] - burst_time1[i]);
            //wait_time = wait_time + total - arrival_time1[i] - burst_time1[i]; 
            //turnaround_time = turnaround_time + total - arrival_time1[i]; 
            counter = 0; 
        } 
        if(i == j - 1) 
        {
            i = 0; 
        }
        else if(arrival_time1[i + 1] <= total) 
        {
            i++;
        }
        else 
        {
            i = 0;
        }
    } 
}
int main()
{
	printf("Enter the no. of process you want to enter\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details of process[%d]\n",i+1);
		printf("Arrival Time:");
		scanf("%d",&at[i]);
		printf("Burst Time:");
		scanf("%d",&bt[i]);
		printf("Priority(1 to 15):");
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++)
	{
		if(p[i]>=1&&p[i]<=5)
		{
			printf("Process[%d] belongs to Queue 1\n",i+1);
			arrival_time1[j]=at[i];
			burst_time1[j]=bt[i];
			j++;
		}
		
		else if(p[i]>=6&&p[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			arrival_time2[k]=at[i];
			burst_time2[k]=bt[i];
			k++;
		}
		
		else if(p[i]>=11&&p[i]<=15)
		{
			printf("Process[%d] belongs to Queue 3\n",i+1);
			arrival_time3[l]=at[i];
			burst_time3[l]=bt[i];
			l++;
		}
	}
	
	pthread_t tid1;
	
	pthread_create(&tid1,NULL,round_robin,NULL);
	pthread_join(tid1,NULL);
	return 0;
}
