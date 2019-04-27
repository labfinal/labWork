#include<stdio.h>
#include<stdlib.h>
#include<time.h>

FILE *file;

int main()
{
    clock_t ts,te;
    srand(time(NULL));
    int number,num[1000000],n,i;
    printf("How many numbers ? ");
    scanf("%d",&number);
    file=fopen("merge_input.word","w");
    for(i=0;i<number;i++)
    {
        n=rand();
        fprintf(file,"%d   ",n);
    }
    fclose(file);
    unsort_print(num,number);
    ts=clock();
    merge_sort(num,0,number-1);
    te=clock();
    sort_print(num,number);
    double time_taken=(double)(te-ts)/CLOCKS_PER_SEC;
    printf("\nMerge sort took %lf seconds\n",time_taken);
    return 0;

}



int unsort_print(int un_sort[],int size)
{
    int i;
    printf("\nArray before sorting : \n");
    file=fopen("merge_input.word","r");
    for(i=0;i<size;i++)
    {
        fscanf(file,"%d",&un_sort[i]);
        printf("%d  ",un_sort[i]);
    }
    fclose(file);
    printf("\n");
}

int merge_sort(int num[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(num,l,m);
        merge_sort(num,m+1,r);
        merge(num,l,m,r);
    }

}

int merge(int num[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int left[n1],right[n2];
    for(i=0;i<n1;i++)
    {
        left[i]=num[l+i];
    }
    for(j=0;j<n2;j++)
    {
        right[j]=num[m+1+j];
    }
    i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(left[i]<=right[j])
        {
            num[k]=left[i];
            i++;
        }
        else
        {
            num[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        num[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        num[k]=right[j];
        j++;
        k++;
    }
}

int sort_print(int num[],int size)
{
    int i;
    printf("\nArray after sorting : \n");
    file=fopen("merge_output.word","w");
    for(i=0;i<size;i++)
    {
        printf("%d  ",num[i]);
        fprintf(file,"%d   ",num[i]);
    }
    fclose(file);
    printf("\n");

}

