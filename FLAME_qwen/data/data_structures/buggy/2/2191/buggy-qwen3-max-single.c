#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int sum = 0, a, b, c = 1, k=1;
    char q;

    scanf("%d", &b);
 
    while (1) {
    out:
        scanf("%c", &q);
        if (q == ' ') goto out; @@ [Using goto to skip spaces is error-prone and may cause infinite loops or missed operators; also, the logic for handling operator precedence and state tracking is flawed]
        
        if(q=='+'){
            if(k==2)sum+=a*b;
            else if(k==3)
            sum+=a/b;
            else if(k==1||k==4)sum+=b;
            k=1;a=0;c=1;
        }
        if(q=='-'){
            if(k==2)sum+=a*b;
            else if(k==3)sum+=a/b;
            else if(k==1||k==4)sum+=b;
            k=4;a=0;c=-1;
        }
        if(q=='*'){
            if(k==1 || k==4)a=b;
            else a*=b;
            k=2;c=1;
        }
        if(q=='/'){
            if(k==1 || k==4)a=b;
            else a/=b;
            k=3;c=1;
        }
    if(q=='='){
        if(k==1)sum+=b;
        else if(k==2)sum+=a*b;
        else if(k==3)sum+=a/b;
        else if(k==4)sum+=b;
        else sum+=a;
        break;
    }


    scanf("%d",&b); @@ [This scanf may fail if input ends unexpectedly or if non-integer is read; also, it doesn't handle spaces robustly before the number]
    b=b*c; @@ [The use of 'c' to flip sign is convoluted and incorrectly applied; sign should be handled via operator state, not by modifying operand]

    }
    printf("%d", sum);
}