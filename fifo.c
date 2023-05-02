# include <stdio.h>
int no_of_frames, no_of_processes,p[10],f[10],h=0,m=0,flag,index;

void read()
{
    printf("Enter number of frames");
    scanf("%d",&no_of_frames);

    printf("Enter number of processes");
    scanf("%d",&no_of_processes);
    for(int i=0;i<no_of_processes;i++)
    {
        printf("Enter size of process %d",(i+1));
        scanf("%d",&p[i]);
    }
}
void fifo()
{
    for(int i=0;i<no_of_frames;i++)
    {
        f[i]=-1;
    }

    index=-1;
    for(int i=0;i<no_of_processes;i++)
    {
        flag=0;
        for(int j=0;j<no_of_frames;j++)
        {
            if(p[i]==f[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("\nSymbol: %d  Frame: ",p[i]);
            for (int j=0;j<no_of_frames;j++)
                printf("%d ",f[j]);
            h+=1;
        }
        else{
            index=(index+1)%no_of_frames;
            f[index]=p[i];
            //printf("\n%d\t",index);
            m+=1;
            printf("\nSymbol: %d  Frame: ",p[i]);
            for (int j=0;j<no_of_frames;j++)
                printf("%d ",f[j]);
        }
    }
     printf("\nPage hits: %d",h);
    printf("\nPage misses: %d",m);
    printf("\nPage miss ratio: %.2f",(float)m/(float)no_of_processes);
        printf("\nPage hit ratio: %.2f",(float)h/(float)no_of_processes);

}

int main()
{
    read();
    fifo();
    return 0;
}
