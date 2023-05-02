# include <stdio.h>
# include <stdlib.h>
# include <math.h>
int i,j,temp,temp1,temp2,queue1[20],queue2[20],queue[20],head,n,movement=0;
int main ()
{
    printf("Enter number of requests");
    scanf("%d",&n);

    printf("Enter head");
    scanf("%d",&head);

    for(i=0; i<n ; i++)
    {
        printf("Enter size of request %d",(i+1));
        scanf("%d",&temp);
        if(temp>head)
        {
            queue1[temp1]=temp;
            temp1++;
        }
        else
        {
            queue2[temp2]=temp;
            temp2++;
        }
    }

        for(i=0;i<temp1-1;i++)
        {
            for(j=0;j<temp1-i-1;j++)
            {
                if(queue1[j]>queue1[j+1])
                {
                    temp=queue1[j];
                    queue1[j]=queue1[j+1];
                    queue1[j+1]=temp;
                }
            }
        }

        for(i=0;i<temp2-1;i++)
        {
            for(j=0;j<temp2-i-1;j++)
            {
                if(queue2[j]>queue2[j+1])
                {
                    temp=queue2[j];
                    queue2[j]=queue2[j+1];
                    queue2[j+1]=temp;
                }
            }
        }
    queue[0]=head;
    for(i=1,j=0;j<temp1;i++,j++)
        queue[i]=queue1[j];

    for(i=temp1+1,j=0;j<temp2;i++,j++)
        queue[i]=queue2[j];

    for(j=0;j<i-1;j++)
    {
        movement=movement+abs(queue[j]-queue[j+1]);
        printf("%d ---> %d : %d\n",queue[j],queue[j+1],movement);
    }
    printf("\nTotal head movement is %d",movement);
}
