#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1024

char A[11],fin[max][11];
int times;
void save(int N){
    int i;
    for (i=0;i<N;i++){
        fin[times][i]=A[i];
    }
    times++;
}

int cmp(const void*a,const void*b)
    {
        return strcmp((char *)a,(char *)b);
    }

void swap(int i,int j)
{
    int tmp ;

    tmp = A[j] ;
    A[j] = A[i] ;
    A[i] = tmp ;
}


void permutation(int k,int N)
{
    int i ;

    if (k==N-1)
        save(N);
        //println(N);
    else
        for (i=k; i<N; i++) {
            swap(i,k) ;
            permutation(k+1,N) ;
            swap(i,k) ;
            }
}

int main()
{
    int N,i,j,l,num=1;
    scanf("%d",&N);

    for (i=0;i<N;i++){
        A[i]=(char)(i+49);
        num=num*(i+1);
    }

    permutation(0,N) ;
    qsort(fin,num,sizeof(fin[0]),cmp);

    for (j=0;j<times;j++){
        for (l=0;l<N;l++){
            printf ("%c ",fin[j][l]);
        }
        printf ("\n");
    }

    return 0;
}



