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
            if(k==1 || k==4)a=b; // @@ Should first apply the previous pending multiplication/division on a and b before setting new a.
            else a*=b;           // @@ Should first apply the previous pending operation (k==2 or k==3) on a and b, then set a to that result and update k to new operator.
            k=2;c=1;
        }
        if(q=='/'){
            if(k==1 || k==4)a=b; // @@ Same as above: should first apply previous pending multiplication/division before dividing.
            else a/=b;           // @@ Same as above: should first apply previous pending operation, then update a and k.
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


    scanf("%d",&b);
    b=b*c;

    }
    printf("%d", sum);
}