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
        if (q == ' ') goto out;
        
        if(q=='+'){
            if(k==2)sum+=a*b; // @@ uses b from previous step instead of the number after current operator
            else if(k==3)
            sum+=a/b; // @@ uses b from previous step instead of the number after current operator
            else if(k==1||k==4)sum+=b; // @@ uses b from previous step instead of the number after current operator
            k=1;a=0;c=1;
        }
        if(q=='-'){
            if(k==2)sum+=a*b; // @@ uses b from previous step instead of the number after current operator
            else if(k==3)sum+=a/b; // @@ uses b from previous step instead of the number after current operator
            else if(k==1||k==4)sum+=b; // @@ uses b from previous step instead of the number after current operator
            k=4;a=0;c=-1;
        }
        if(q=='*'){
            if(k==1 || k==4)a=b; // @@ uses b from previous step as left operand, should be current number after operator
            else a*=b; // @@ multiplies with previous b instead of current number
            k=2;c=1;
        }
        if(q=='/'){
            if(k==1 || k==4)a=b; // @@ uses b from previous step as left operand, should be current number after operator
            else a/=b; // @@ divides with previous b instead of current number
            k=3;c=1;
        }
    if(q=='='){
        if(k==1)sum+=b; // @@ may use wrong b (previous number)
        else if(k==2)sum+=a*b; // @@ uses a and b that may be from previous operators
        else if(k==3)sum+=a/b; // @@ uses a and b that may be from previous operators
        else if(k==4)sum+=b; // @@ may use wrong b
        else sum+=a;
        break;
    }


    scanf("%d",&b);
    b=b*c; // @@ multiplies b by sign before next operator, causing misalignment

    }
    printf("%d", sum);
}