#include<stdio.h>
int start[10],finish[10],size,i,k,temp;
int main()
{

    printf("Enter activity numbers : ");
    scanf("%d",&size);
    printf("Enter activities duration : \n");
    for(i=0;i<size;i++)
    {
        printf("Activities[%d] : \n",i);
        scanf("%d %d",&start[i],&finish[i]);
    }
    sort(start,finish,size);
    activity(start,finish,size);
    return 0;
}

void sort(int start[],int finish[],int size)
{
    for(i=0;i<size;i++)
    {
        for(k =0;k<size-i-1;k++)
        {
            if(start[k]>start[k+1]||(finish[k]-start[k])>(finish[k+1]-start[k+1]))
            {
                temp=start[k];
                start[k]=start[k+1];
                start[k+1]=temp;
                temp=finish[k];
                finish[k]=finish[k+1];
                finish[k+1]=temp;
            }
        }

    }
   /*  for(i=0;i<size;i++)
    {
        printf("%d %d\n",start[i],finish[i]);
    }*/


}
void activity(int start[],int finish[],int size)
{
    printf("output : \n");
    int i,j;
    i=0;
    printf("%d %d\n",start[i],finish[i]);
    for(j=1;j<size;j++)
    {
        if(start[j]>=finish[i])
        {
            printf("%d %d\n",start[j],finish[j]);
            i=j;
        }
    }
}
