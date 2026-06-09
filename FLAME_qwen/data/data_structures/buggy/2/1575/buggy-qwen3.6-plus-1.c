#include<bits/stdc++.h> // @@ This is a C++ specific header file. Compiling this code in a standard C environment will cause a compilation error. It should be replaced with #include <stdio.h>.
int main(){
    int a1,a2,a3;
    char c1,c2,c3;
    a1 = 0;
    c1 = '+';
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