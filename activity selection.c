#include<stdio.h>
int main()
{
    int start[10],finish[10],size,i;
    printf("Enter activity numbers : ");
    scanf("%d",&size);
    printf("Enter activities duration : \n");
    for(i=0;i<size;i++)
    {
        printf("%d activities : \n",i+1);
        scanf("%d %d",&start[i],&finish[i]);
    }
    activity(start,finish,size);
    return 0;
}
void activity(int start[],int finish[],int size)
{
    int i,j;
    i=0;
    printf("%d\t",i);
    for(j=1;j<size;j++)
    {
        if(start[j]>=finish[i])
        {
            printf("%d\t",j);
            i=j;
        }
    }
}
