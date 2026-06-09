#include<stdio.h> 
#include<string.h>
int main(){
    char s[100]=" ";
    gets(s); @@ [Compilation error: gets() is deprecated and removed in the C11 standard, which may cause compilation failure on modern compilers. Use fgets(s, sizeof(s), stdin) instead.]
    int i=0;
    int z1=0,z2=0,z3=0;

    for(i;i<strlen(s);i++){
        if(s[i]!='.') z1++;
    }
    if(z1==strlen(s)){
        if(s[0]=='-'){
            printf("-%c.",s[1]);
            i=2;
            z1=z1-1;
        }
    else {
    printf("%c.",s[0]);
    i=1;
    }    
        
        for(i;i<strlen(s);i++){
            if(s[i]!='.') printf("%c",s[i]);
        }
        printf("e%d",z1-1);
    }// @@ [Logical error: Missing return or else clause. If z1==strlen(s), the program prints the result but falls through to the next block where m and n are uninitialized, causing undefined behavior and incorrect output.]
    int m,n;//用来定位 . 和第一个非零数字的位置 @@ [Logical error: Variables m and n are declared here but only initialized if z1!=strlen(s). If the first condition is true, they remain uninitialized and are used later, leading to undefined behavior.]
    
    if(z1!=strlen(s)){
        i=0;
    for(i;i<strlen(s);i++){
        if(s[i]!='0'&&s[i]!='.'&&s[i]!='-'){
            n=i;//第一个非零 
            break;
        }
    }
    i=0;
    for(i;i<strlen(s);i++){
        if(s[i]=='.'){
            m=i;//这是 。 的位置 
            break;
        }
    }
}
    if(m<n) {// 这是描述<1的数 
        int w=m-n;
        if(n==strlen(s)-1){
            if(s[0]=='-')
            printf("-%ce%d",s[n],w);
            else
            printf("%ce%d",s[n],w);
        }
     
    if(n!=strlen(s)-1)    {
       if(s[0]!='-')
        printf("%c.",s[n]);
    else
    printf("-%c.",s[n]);
        i=n+1;
        for(i;i<strlen(s);i++){
        printf("%c",s[i]);
        }
        printf("e%d",w);
}
    }
   
    //
    if(m>n){
            int w=m-n-1;
            if(s[0]!='-'){
                    i=1;    
        printf("%c.",s[n]);
}
        else {printf("-%c.",s[n]);
        i=2;
        }
    
        for(i;i<=strlen(s);i++){ @@ [Logical error: Loop condition i<=strlen(s) accesses the null terminator s[strlen(s)]. It should be i<strlen(s) to avoid processing the string terminator.]
            if (s[i]!='.'&&s[i]!='-')   printf("%c",s[i]);
        }
        printf("e%d",w);

    }
    return 0;
}