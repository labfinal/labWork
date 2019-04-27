#include<stdio.h>
#define size 100000
int main()
{
    int N,Q,S[size],T[size],K,i=0,j,R[size];
    do
    {
        scanf("%d %d",&N,&Q);
        if(N>=size||Q>=size)
        {
            printf("Limit overflow\n");
        }
    }while(N>=size||Q>=size);
    do
    {
        scanf("%d",&T[i]);
        i++;
    }while(i<N);
	mergeSort(T,0, N-1);

    for(i=0;i<N;i++)
    {
        scanf("%d",&S[i]);
    }
    i=0;
    j=0;
    while(i<Q)
    {
        R[i]=0;
        do{
            scanf("%d",&K);
        }while(K>N);

        for(j=0;j<K;j++)
        {
            R[i]=R[i]+T[j];
        }
        i++;
    }
    for(i=0;i<Q;i++)
    {
        printf("%d\n",R[i]);
    }
    return 0;
}

void Merge(int T[], int low, int high, int mid)
{

int i=low,j=mid+1,k=0;
int temp[high-low+1];

while(i<=mid && j<= high)
{
    if(T[i]>T[j])
        temp[k++]=T[i++];

    else
        temp[k++]=T[j++];

}

while(i<=mid)
    {
        temp[k++]=T[i++];
    }

while(j<=high)
    {
        temp[k++]=T[j++];
    }

for(i=low;i<=high;i++)
{

    T[i]=temp[i-low];

}
}


void mergeSort(int T[],int low, int high)
 {
int mid;

if(low<high)
{
    mid=(low+high)/2;

    mergeSort(T,low,mid);
    mergeSort(T,mid+1,high);

    Merge(T,low,high,mid);
}
}
