# include <stdio.h>
# define time 4
int n, total_waiting_time=0,total_turnaround_time=0,current_time=0,completed_process=0,time_executed=0;

typedef struct {
int pid;
int remaining_time;
int burst_time;
int arrival_time;
int turnaround_time;
int waiting_time;
}Process ;

Process process[10];

void read()
{
    printf("enter number of processes ");
    scanf("%d",&n);

    for (int i=0;i<n;i++)
    {
        printf("Enter arrival time for process %d ",(i+1));
        scanf("%d",&process[i].arrival_time);
        printf("Enter burst time for process %d ",(i+1));
        scanf("%d",&process[i].burst_time);
        process[i].remaining_time=process[i].burst_time;
        process[i].pid=(i+1);
    }
}

void round_robin()
{
    while(completed_process<n)
    {
        for (int i=0;i<n;i++)
        {
            if(process[i].remaining_time>0)
            {
                if(process[i].remaining_time>time)
                {
                    time_executed=time;
                }
                else{
                    time_executed=process[i].remaining_time;
                }
                process[i].remaining_time-=time_executed;

                current_time+=time_executed;
                process[i].waiting_time+=(current_time-process[i].arrival_time-time_executed);

                printf("%d\n",current_time);
                if (process[i].remaining_time == 0)
                    {
                    process[i].turnaround_time = current_time - process[i].arrival_time;
                    completed_process++;
                    }

            }

        }
    }
}


void display()
{
    printf("ID\tBurst time\tArrival time\tWaiting time\tTurnaround time\n");
    for (int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",process[i].pid,process[i].burst_time,process[i].arrival_time,process[i].waiting_time,process[i].turnaround_time);
        total_waiting_time += process[i].waiting_time;
        total_turnaround_time += process[i].turnaround_time;
    }

    printf("\nTotal waiting time is %d",total_waiting_time);
    printf("\nTotal turnaround time is %d",total_turnaround_time);
    printf("\nAverage waiting time is %f",(float)total_waiting_time/n);
    printf("\nAverage turnaround time is %f",(float)total_turnaround_time/n);
}

int main()
{
    read();
    round_robin();
    display();
    return 0;
}
