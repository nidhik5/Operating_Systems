# include <stdio.h>
int start=0,i,j,n,f;
struct File
{
    char name[20];
    int start_block;
    int block_reqd;
};

int main ()
{
    struct File file[10];
    int sectors[10]={0};

    printf("Enter number of sectors available in memory");
    scanf("%d",&n);

    printf("Enter number of files partition ");
    scanf("%d",&f);

    for(i=0;i<f;i++)
    {
        printf ("Enter name of file %d",(i+1));
        scanf("%s",&file[i].name);
        printf("Enter blocks reqd by file %d ",(i+1));
        scanf("%d",&file[i].block_reqd);
    }

    for(i=0;i<f;i++)
    {
        //printf("vbnm");
        if(file[i].block_reqd<=n)
        {
            //printf("nbvcx");
            file[i].start_block=start;
            start=start+file[i].block_reqd+1;
            n=n-file[i].block_reqd;
        }
        else
        {
            printf("No file allocated to file %s",file[i].name);
            file[i].start_block=-1;
        }
    }

    printf("\n File name\t Start block\t blocks required\n");

        for(i=0;i<f;i++)
        {

            if(file[i].start_block!=-1)
                {printf("%s\t",file[i].name);
                printf("%d\t%d\n",file[i].start_block,file[i].block_reqd);
                }
                else
                    printf("Not allocated\n");
        }


    return 0;
}
