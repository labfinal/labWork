#include<stdio.h>
#include<stdlib.h>
FILE *file;
int main()
{
    int i,size,arr[100000],n;
    printf("enter array size: ");
    scanf("%d",&size);
    file=fopen("qsi.txt","w");
    printf("Enter elemenet : \n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&n);
        fprintf(file,"%d\t",&n);
    }
    fclose(file);
    quickSort(arr,0,size-1);
    printarray(arr,size);
}
void printarray(int arr[],int size)
{
    int i;
    file=fopen("qso.txt","w");
    for(i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
        fprintf(file,"%d\t",arr[i]);
    }
    fclose(file);
}
void quickSort(int arr[],int low,int high)
{
    int i;
    file=fopen("qsi.txt","r");
    for(i=0;i<=high;i++)
    {
        fscanf(file,"%d",&arr[i]);
    }
    while(low<high)
    {
        int part=partition(arr,low,high);
        quickSort(arr,part-1,low);
        quickSort(arr,part+1,high);
    }
    fclose(file);
}

int partition(int arr[],int low,int high)
{
    int j;
    int p=arr[high];
    int i=arr[low-1];
    for(j=0;j<=high-1;j++)
    {
        if(arr[j]<=p)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return arr[i+1];
}

void swap(int a,int b)
{
    int t=a;
    a=b;
    b=t;
}
