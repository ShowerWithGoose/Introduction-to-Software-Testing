#include<stdio.h>
#include<string.h>
char s[101];
int main(){
    int j=0;
    char t;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. Moreover, some compilers may not support it, leading to compilation errors.]
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
    printf("e-%d",j-1); // @@ [The exponent calculation is incorrect. For numbers like "0.00123", the first non-zero digit is at index 4 ('1'), so exponent should be -(4 - 1) = -3, but this prints -(4 - 1) = -3 only if j is correctly interpreted. However, j is the index of the first non-zero digit, and the decimal point is at index 1, so exponent should be -(j - 2), not -(j - 1). Also, when the number is "0.1", j=2, so it prints e-1, which is correct, but logic is fragile and inconsistent with problem specification.]
    }
    return 0;}