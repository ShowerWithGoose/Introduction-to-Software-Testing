#include<bits/stdc++.h>
int main(){
    int a1,a2,a3;
    char c1,c2,c3;
    a1 = 0;
    c1 = '+'; // @@ [Uninitialized variables c2 and c3 are used in loop condition indirectly; more critically, the initial value of c1 is set but the first input reads into c2, and if the expression starts with a negative number or has leading spaces, the logic may fail. However, the primary issue causing incorrect behavior is that the loop condition only checks c1!='=', but c1 is only updated after processing an additive term. If the expression ends immediately after '=', the last operator might be '=' but c1 hasn't been updated yet, causing one extra iteration or missing termination. But the actual critical error is that the program does not handle the case where the expression has only one number followed by '=' — because it always tries to read at least one operator after the first number. For example, input "5 =" would cause scanf to wait for another character after 5, but there's only space and '='. The format "%d %c" will skip whitespace and read '=' into c2, then enter the outer loop body. Then since c2 is '=', it skips the inner while, applies c1 (which is '+') to a2=5, sets c1='=', and loops again. Now c1 is '=', so loop exits. That actually works. However, the real bug is that the program uses #include<bits/stdc++.h> which is non-standard and may cause compilation errors in strict C compilers (like gcc in C mode), as <bits/stdc++.h> is a GCC extension for C++ only. This explains the "gcc: not found" error message being misleading — actually, the compilation fails because <bits/stdc++.h> is not available in C. The correct header should be <stdio.h>.]
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