#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    long int number,num[10000],i,j,key;
    printf("Enter Array size : ");
    scanf("%ld",&number);
    FILE *file;
    srand(time(0));
    file=fopen("insert.txt","w");
    for(i=0;i<number;i++)
    {
        num[i]=rand()%1000000;
    }
    printf("\nArray before sorting : \n");
    for(i=0;i<number;i++)
    {
        printf("%ld  ",num[i]);
        fprintf(file,"%ld  ",num[i]);
    }
    printf("\n");
    fclose(file);
    clock_t ts,te;
    ts=clock();
    for(i=1;i<number;i++)
    {
        key=num[i];
        j=i-1;
        while(j>=0&&num[j]>key)
        {
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=key;
    }
    te=clock();
    double time_taken=((double)te-ts)/CLOCKS_PER_SEC;
    printf("\nINSERTION SORT TOOK : %lf seconds",time_taken);
    file=fopen("output.txt","w");
    printf("\n\nArray after sorting :\n");
    for(i=0;i<number;i++)
    {
        printf("%ld  ",num[i]);
        fprintf(file,"%ld  ",num[i]);
    }
    printf("\n");
    fclose(file);
    return 0;
}
