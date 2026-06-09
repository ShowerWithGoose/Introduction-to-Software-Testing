#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int stack[105];

int main()
{
    int n,cnt=0;
    scanf("%d",&n);

    while(n!=-1){
        if(n==1){
            if(cnt==100){
                printf("error ");
                scanf("%d ",&stack[cnt]);
            }
            else{
                scanf("%d ",&stack[cnt]);
                //printf("%d %d",cnt,stack[cnt-1]);
                cnt++;
            }
        }
        else{
            if(cnt==0){
                printf("error ");
            }
            else{
                printf("%d ",stack[cnt-1]);
                cnt--;
            }
        }

        scanf("%d",&n);
    }

    return 0;
}

