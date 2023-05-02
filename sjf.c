# include <stdio.h>
int n, total_waiting_time=0, total_turnaround_time=0,  current_time=0 ;

typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

Process process[10], temp;

void read()
{
    printf("enter number of processes ");
    scanf("%d",&n);

    for (int i=0;i<n;i++)
    {
        printf("Enter burstime for process %d ",(i+1));
        scanf("%d",&process[i].burst_time);
        process[i].pid=(i+1);
    }
}

void sort()
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(process[j].burst_time>process[j+1].burst_time)
            {
                temp=process[j];
                process[j]=process[j+1];
                process[j+1]=temp;

            }
        }
    }
}

void sjf()
{
    for(int i=0;i<n;i++)
    {
        process[i].waiting_time=current_time;
        process[i].turnaround_time=process[i].waiting_time+process[i].burst_time;
        current_time+=process[i].burst_time;

        total_waiting_time+=process[i].waiting_time;
        total_turnaround_time+=process[i].turnaround_time;

    }
}

void display()
{
    printf("ID\tBurst time\tWaiting time\tTurnaround time\n");
    for (int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\n",process[i].pid,process[i].burst_time,process[i].waiting_time,process[i].turnaround_time);
    }

    printf("\nTotal waiting time is %d",total_waiting_time);
    printf("\nTotal turnaound time is %d",total_turnaround_time);
    printf("\nAverage waiting time is %f",(float)total_waiting_time/n);
    printf("\nAverage turnaround time is %f",(float)total_turnaround_time/n);
}

int main()
{
    read();
    sort();
    sjf();
    display();
    return 0;
}
