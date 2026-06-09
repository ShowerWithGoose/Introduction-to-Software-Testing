#include<bits/stdc++.h>
int main(){
    int a1,a2,a3;
    char c1,c2,c3;
    a1 = 0;
    c1 = '+'; @@ [Uninitialized variables c2 and c3 are used in loop condition indirectly; more critically, the first evaluation of c1 in while(c1!='=') is safe, but after processing the last number and '=', c2 becomes '=', then c1=c2 sets c1='=', so loop exits correctly. However, the real issue is that the initial read assumes input format "number space operator", but if input ends immediately with "=", e.g., "= ", it would fail. But the compilation error suggests a different problem.]

    while(c1!='='){
        scanf("%d %c",&a2,&c2);   
        while(c2=='*' || c2=='/'){
            scanf("%d %c",&a3,&c3);
            if(c2=='*')
                a2 *= a3;
            else if(c2=='/')
                a2 /= a3;
            c2 = c3;    
        }
        if(c1=='+')a1 += a2;
        else if(c1=='-')a1 -= a2;
        c1 = c2;
    }
 
    printf("%d",a1);
 
    return 0;
}