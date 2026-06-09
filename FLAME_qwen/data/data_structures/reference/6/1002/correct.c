#include <stdio.h>

int main( )
{
    int op;
    int n;
    int num[105]={};
    int i=-1;
    int flag=0;
    while(1){
        scanf("%d",&op);
        if(op==-1) break;
        else {
            switch(op){
                case 1: if(i==100) {
                        printf("error ");
                        break;
                }
                   else{
                       scanf("%d",&n);
                        num[++i]=n;
                        break;
                   }
                case 0: if(i!=-1) {
                        printf("%d ",num[i]);
                        num[i--]=0;
                }
                    else printf("error ");
                    break;
            }
        }
    }
    return 0;
}

