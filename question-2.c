#include<stdio.h>
#define size 100000
int main()
{
    int N,X[size],H[size],a=0,b=1,i=0,j,L=0,R;
    do{
        scanf("%d",&N);
    }while(N<2||N>size);
    scanf("%d %d",&X[0],&H[0]);
    i++;
    do
    {
        scanf("%d %d",&X[i],&H[i]);
        if((X[i]<X[i-1])||(H[i]<H[i-1]))
        {
            printf("Condition is not full filled\n");
            i--;
        }
        i++;

    }while(i<N);
    j=0;
    i=1;
    do
    {
        if((X[b]-X[a])<(H[b]-H[a]))
        {
            b++;
        }
        else
            {
               if((X[i]-X[j])>(H[i]-H[j]))
        {
           R=((X[i]-X[j])*(X[i]-X[j]))+((H[i]-H[j])*(H[i]-H[j]));
            if(R>L)
            {
                L=R;
            }
            j=i;
            i++;
        }
        else
        {
            i++;
        }
            }

    }while(i<N);
    if(b==N)
    {
        printf("\nLimak can't go to any tree\n");
    }
    else
    {
        printf("Length of Rope : %d",L);
    }

}
