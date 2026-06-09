#include<bits/stdc++.h>
int main(){
    int a1,a2,a3;
    char c1,c2,c3;
    a1 = 0;
    c1 = '+'; // @@ [Using char without initialization for c2 and c3 may lead to undefined behavior in the first loop condition check, but the real issue is that <bits/stdc++.h> is non-standard and may cause compilation failure in strict C compilers. Also, the program uses C++ header in a C program, which causes compilation error.]
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