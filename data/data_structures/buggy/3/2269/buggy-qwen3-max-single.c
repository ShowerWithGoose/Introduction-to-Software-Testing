#include<stdio.h>
#include<string.h>
char s[101];
int main(){
    int j=0;
    char t;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks. Should use 'fgets' instead.]
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
    printf("e-%d",j-1); // @@ [The exponent calculation is incorrect. For numbers like "0.00123", the first non-zero digit is at index 4 ('1'), so exponent should be -(4 - 1) = -3, but this prints -(4 - 1) = -3 only if j is correctly interpreted. However, j is the index of the first non-zero digit, and since '.' is at index 1, exponent should be -(j - 2), not -(j - 1). Also, logic fails when input has no decimal part or edge cases. But primary compilation error is due to 'gets'.]
    }
    return 0;}