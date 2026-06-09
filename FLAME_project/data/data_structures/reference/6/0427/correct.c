#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int a[100];
    int x,y=-1,n=0;
    while(scanf("%d",&x)!=EOF){
        if(y==0){
            if(n==0){
                printf("error ");
            }
            else if(n>0){
                printf("%d ",a[n-1]);
                n--;
            }
        }
        if(y==1){
            a[n]=x;
            n++;
        }
        if(x==-1){
            break;
        }
        y=x;
    }

	return 0;
}



