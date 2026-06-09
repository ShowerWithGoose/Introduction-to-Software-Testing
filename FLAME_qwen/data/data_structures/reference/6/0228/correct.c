#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a[200],i,j=0,m;
    while(j!=-1){
        scanf("%d",&j);
        if(j==1){
            scanf("%d",&m);
            if(i==100)
                printf("error ");
            else{
                a[i]=m;
                i++;
            }
        }
        else if(j==0){
            if(i==0)
                printf("error ");
            else{
                printf("%d ",a[--i]);
            }
        }
    }

    return 0;
}

