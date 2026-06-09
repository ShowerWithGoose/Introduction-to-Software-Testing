#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int n,i,sum=0,tsum,k;
    int a;
    char b;
    scanf("%d ",&a);
    tsum=a;
    k=1;
    while(1){
        scanf("%c",&b);
        if(b=='='){
            sum+=(k*tsum);
            printf("%d",sum);
            return 0;
        }
        scanf(" %d ",&a);
        if(b=='+')
        {
            sum+=(k*tsum);
            tsum=a;
            k=1;
        }
        else if(b=='-')
        {
            sum+=(k*tsum);
            tsum=a;
            k=-1;
        }
        else if(b=='*'){
            tsum*=a;
        }
        else if(b=='/'){
            tsum/=a;
        }
    }
    return 0;
}
