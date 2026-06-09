#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int *data=(int*)malloc(sizeof(int)*MAX);
    int tail=-1;
    int op,n;
    while(scanf("%d",&op)!=EOF)
    {
        if(op==0)
        {
            if(tail==-1) printf("error ");
            else printf("%d ",data[tail--]);
        }
        else if(op==1)
        {
            if(tail+1==MAX) printf("error ");
            tail++;
            scanf("%d",&n);
            data[tail]=n;
        }
        else if(op==-1) break;
    }
    free(data);
    return 0;
}

