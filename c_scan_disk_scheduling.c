# include <stdio.h>
int queue[50],queue1[20],queue2[20],current,max,temp1=0,temp2=0,temp,n,movement;
int main()
{
    int i,j;
    printf("Enter number of requests ");
    scanf("%d",&n);

    printf("Enter current position ");
    scanf("%d",&current);

    printf("Enter max range of disk");
    scanf("%d",&max);

    for(i=0;i<n;i++)
    {
        printf("Enter request %d ",(i+1));
        scanf("%d",&temp);

        if(temp>current)
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

    for( i=0;i<temp1-1;i++)
    {
        for(int j=0;j<temp1-i-1;j++)
        {
            if(queue1[j]>queue1[j+1])
            {
                temp=queue1[j];
                queue1[j]=queue1[j+1];
                queue1[j+1]=temp;
            }
        }
    }

    for( i=0;i<temp2-1;i++)
    {
        for(int j=0;j<temp2-i-1;j++)
        {
            if(queue2[j]>queue2[j+1])
            {
                temp=queue2[j];
                queue2[j]=queue2[j+1];
                queue2[j+1]=temp;
            }
        }
    }

    for( i=1,j=0;j<temp1;i++,j++)
    {
        queue[i]=queue1[j];
    }
        printf("\n%d\n",i);

    queue[i]=max;

     for( i=temp1+2,j=0;j<temp2;i++,j++)
    {
        queue[i]=queue2[j];
    }
    queue[0]=current;
    queue[i]=0;
    for(int j=0;j<i+1;j++)
    {
        movement=movement+abs(queue[j]-queue[j+1]);
        printf("%d ---> %d : %d\n",queue[j],queue[j+1],movement);
    }
    return 0;
}

