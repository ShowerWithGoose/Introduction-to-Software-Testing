#include<stdio.h>
#include<string.h>
char s[101];
int main(){
    int j=0;
    char t;
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. It should be replaced with 'fgets'.]
    if(s[0]!='0'){

    for(int i=0;i<strlen(s);i++){
        
        if(s[i]=='.')
        {
        j=i;break;}
        
    }
        for(int i=0;i<j;i++)
    {
        if(i==1)
        printf(".");
        printf("%c",s[i]);
    }
    
        if(j==1)
        printf(".");
        for(int i=j+1;i<strlen(s);i++)
    {
        printf("%c",s[i]);
    }
        printf("e%d",j-1);
    
}
    else
    {
        for(int i=0;i<strlen(s);i++){
        
        if(s[i]!='0'&&s[i]!='.')
        {
        j=i;break;}
        
    }
    
    for(int i=j;i<strlen(s);i++)
    {
        printf("%c",s[i]);
        if(i==j+1)
        printf(".");
        
    }
    printf("e-%d",j-1); // @@ [The exponent calculation is incorrect. For numbers like "0.00123", the first non-zero digit is at index 4 (assuming s = "0.00123"), so exponent should be -(j - 1) where j is position after decimal, but current logic uses j-1 which gives wrong sign/magnitude. Also, when j==1 (i.e., "0.x..."), this prints e-0 which is invalid; exponent must reflect correct power of 10.]
    }
    return 0;}