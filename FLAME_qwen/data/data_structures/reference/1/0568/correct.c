#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int *x,int *y)
{int temp;
temp=*x;
*x=*y;
*y=temp;}
//½»»»º¯Êý£»
int jiecheng(int x)
{int i,max=1;
    for(i=1;i<=x;i++){
        max=max*i;
    }
    return max;
}

int main ()
{int a[11]={0,1,2,3,4,5,6,7,8,9,10};
    int N,i,j,k,m,g,p,w;
    scanf("%d",&N);
    for(i=1;i<N;i++){
        printf("%d ",a[i]);
    }printf("%d\n",a[N]);
    for(p=0;p<jiecheng(N)-1;p++){
        for(i=N-1;i>=1;i--){

            if(a[i]<a[i+1]){
                j=i;
                break;}

                }
                for(k=N;k>j;k--){
                    if(a[k]>a[j]){
                        m=k;
                        break;
                    }
                }


                swap(&a[j],&a[m]);

               for(g=j+1;g<=(j+1+N)/2;g++){
                swap(&a[g],&a[N+j+1-g]);
               }



        for(w=1;w<N;w++){
        printf("%d ",a[w]);
    }
    printf("%d\n",a[N]);

    }

return 0;}

