#include<stdio.h>
#include<string.h>
char s[101];
int main(){
    int j=0;
    char t;
    gets(s); // @@ [gets is deprecated and removed in C11 standard, causing compilation error; use scanf("%s", s) or fgets instead]
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
        if(i==j+1) // @@ [Logical error: The decimal point should be placed after the first significant digit, not the second. Change condition to i==j]
        printf(".");
        
    }
    printf("e-%d",j-1);
    }
    return 0;}