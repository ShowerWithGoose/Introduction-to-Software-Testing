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
        if (q == ' ') goto out; @@ [Using goto to skip spaces is error-prone and may cause infinite loops or missed operators; also, the logic for handling spaces is flawed because it doesn't consume subsequent non-space characters properly.]
        
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


    scanf("%d",&b); @@ [This reads the next number without checking if input has ended or if '=' was already encountered; also, it fails when the expression ends right after an operator (though problem says expression is valid), but more critically, it doesn't handle potential whitespace correctly due to prior flawed space-skipping logic.]
    b=b*c; @@ [The use of 'c' to flip sign is convoluted and incorrectly applied; 'c' is set in '+'/'-' branches but then immediately multiplied into 'b', which interferes with correct precedence handling and leads to wrong operand values.]

    }
    printf("%d", sum);
}