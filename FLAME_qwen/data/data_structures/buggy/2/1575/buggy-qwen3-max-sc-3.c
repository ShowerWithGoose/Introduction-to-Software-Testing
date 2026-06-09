#include<bits/stdc++.h>
int main(){
    int a1,a2,a3;
    char c1,c2,c3;
    a1 = 0;
    c1 = '+'; @@ [Using uninitialized variable c1 in loop condition may cause undefined behavior; although c1 is initialized to '+', the loop condition also depends on reading c2 and c3 correctly, but more critically, the header <bits/stdc++.h> is non-standard and may not be available in all environments, which likely caused the "gcc: not found" error indirectly due to compilation environment issues. However, the primary logical issue is that the program does not handle spaces robustly and may fail to read tokens correctly when extra spaces exist, but the immediate compilation error is due to non-standard header.]
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