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
        if (q == ' ') goto out; @@ [Using goto to skip spaces is error-prone and may cause infinite loops or missed operators; also, the logic for handling spaces is flawed because it doesn't properly consume all whitespace before the next token.]
        
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


    scanf("%d",&b); @@ [This scanf does not skip leading whitespace properly in all cases, and combined with the earlier space-skipping logic, may read incorrectly or fail on inputs with irregular spacing. Also, modifying b with c after reading assumes c reflects sign correctly, but c is set only in + / - branches, not consistently maintained.]
    b=b*c; @@ [The use of variable 'c' to apply sign is logically inconsistent; subtraction is handled by setting c=-1, but this affects the next operand globally, which interferes with multiplication/division precedence handling.]

    }
    printf("%d", sum);
}