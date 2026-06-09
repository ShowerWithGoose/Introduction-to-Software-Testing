#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int a=0;int b[105];
    int i=0,j,k,n;
    while(scanf("%d",&n)!=-1){
        if(n==1){
            scanf("%d",&j);
            if(a<100){
                b[a]=j;
                a++;
            }
            else{
                printf("error ");
            }

        }
        else if(n==0){
            if(a<=0){
                printf("error ");
            }
            else{
                printf("%d ",b[a-1]);
                a--;
            }

        }
        else if(n==-1){
            break;
        }
    }
    return 0;
}

