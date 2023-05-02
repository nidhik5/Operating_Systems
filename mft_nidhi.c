# include <stdio.h>
int main_memory, block, p, process[20],no_of_blocks,c=0,total_internal_fragmentation=0;
void read()
{
    printf("Enter size of main memory in bytes ");
    scanf("%d",&main_memory);

    printf("Enter size of block in main memory in bytes ")
    scanf("%d",&block);

    printf("Enter number of processes ");
    scanf("%d",&p);

    no_of_blocks=main_memory/block;

    for(int i=0;i<p;i++)
    {
        printf("Enter size of process in bytes %d ",(i+1));
        scanf("%d",&process[i]);
    }
}

void display()
{
    printf("\n\nProcess\tMemory required by process\t allocated\t Internal Fragmentation");
    for(int i=0;i<p && c<no_of_blocks;i++)
    {
        if(process[i]<block)
        {printf("%d\t\t %d\t\t yes\t\t%d\n",(i+1),process[i],block-process[i]);
        total_internal_fragmentation+=(block-process[i]);
        c++;
        }
        else
        {
        printf("%d\t\t %d\t\t no\t\t--\n",(i+1),process[i]);
        }
    }
    if(i<p)
    printf("No more processes can be allocated memory full");

    printf("\nTotal internal fragmentation is %d",total_internal_fragmentation);
    printf("\nTotal external fragmentation is %d",main_memory-(block*no_of_blocks));

}

int main()
{
    read();
    display();
}
