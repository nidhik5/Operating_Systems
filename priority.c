# include <stdio.h>
int current_time=0,total_waiting_time=0,total_turnaround_time=0,i,j,n,count=0;

struct process{
int pid;
int arrival_time;
int burst_time;
int turnaround_time;
int waiting_time;
int done;
int priority;
};

struct process p[10],temp;

void read()
{
    printf("Enter number of processes");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time of process %d",i);
        scanf("%d",&p[i].arrival_time);
        printf("Enter burst time of process %d",i);
        scanf("%d",&p[i].burst_time);
        p[i].pid=i;
        printf("Enter priority of process %d",i);
        scanf("%d",&p[i].priority);
    }
}

void sort()
{
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].priority>p[j+1].priority)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

void priority()
{
    for(i=0;i<n;i++)
    {
        p[i].done=0;
    }

    while(count!=n)
    {
        for(i=0;i<n;i++)
        {
            if(current_time>=p[i].arrival_time && p[i].done==0)
            {
                p[i].waiting_time=current_time-p[i].arrival_time;
                p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
                total_waiting_time += p[i].waiting_time;
                total_turnaround_time += p[i].turnaround_time;
                                current_time=current_time+p[i].burst_time;

                p[i].done=1;
                count++;
                break;
            }
        }
    }
}

void display()
{
    printf("Process\tBurst time\tPriority\tArrival time\tturnaround time\twaiting time\n");
    for(i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].priority, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("Average waiting time: %.2f\n", (float)total_waiting_time/n);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time/n);
}

int main()
{
    read();
    sort();
    priority();
    display();

    return 0;
}
