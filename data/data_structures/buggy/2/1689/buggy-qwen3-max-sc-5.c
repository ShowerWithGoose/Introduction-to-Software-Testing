#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    int a1,a2,a3,result=0;
    char c1,c2,c3=0;
    a1=0;
    c1='+';
    while(c1!='='){
        scanf("%d %c",&a2,&c2);
        while(c2=='*'||c2=='/'){
            scanf("%d %c",&a3,&c3);
            if(c2=='*'){
                a2=a2*a3;
                c2=c3;
            }
            else if(c2=='/'){
                a2=a2/a3;
                c2=c3;
            }
        }
        if(c1=='+')a1+=a2;
        else if(c1=='-')a1-=a2;
        c1=c2; // @@ [The loop variable c1 is never updated inside the while loop, causing an infinite loop. The reference program updates op1=op2 at the end of each iteration, but this buggy version omits that crucial assignment.]
    }
    printf("%d",a1);
    
    return 0; 
}